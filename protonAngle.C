#define protonAngle_cxx
#include "protonAngle.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <math.h>
#include <valarray>
#include <iostream>

using namespace std;

 

void protonAngle::Loop()

{
//   In a ROOT session, you can do:
//      root> .L protonAngle.C
//      root> protonAngle t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:

// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch

   if (fChain == 0) return;

   FILE * gunTFile;
   const char * correctGunDatatxt = "gun_vals.txt";
   gunTFile = fopen(correctGunDatatxt,"w"); 

   int events = 0;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;

   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;

      nb = fChain->GetEntry(jentry);   nbytes += nb;

      if (TST01sumE < 1e-7) 
	continue;
      
      events++;

      const double pi = 3.14159265358979323846;
      double theta;
      double phi;
 
      for(UInt_t i=0; i<gunn; i++){
	if(gunpdg[i]==2212){
	
         double r = sqrt(pow(gunpx[i],2)+pow(gunpy[i],2)+pow(gunpz[i],2));
	 
         fprintf(gunTFile,"%f ",gunT[i]);

	 theta = acos(gunpz[i] / r);
	 fprintf(gunTFile, "%f ", theta);

         phi = atan2(gunpy[i], gunpx[i]);
         fprintf(gunTFile, "%f ", phi);

         fprintf(gunTFile,"\n");

	}
      }

   }
   printf("Events simulated (ggland): %lld Events kept: %d Ratio: %f\n",nentries,events,(float)events/nentries);
   printf("Files generated:\n%s\n%s",correctGunDatatxt);

   fclose(gunTFile);

}

 
#ifndef __CINT__

int main(int argc, char **argv)

{
  int start_i = 1;

  for (int i = start_i; i < argc; i++)
    {
      protonAngle conv(argv[i]);

      conv.Loop();
    }
}

#endif
