//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Sep 20 14:39:08 2023 by ROOT version 6.26/10
// from TTree h102/collect hit tree
// found on file: helioscylinder.root
//////////////////////////////////////////////////////////

#ifndef protonAngle_h
#define protonAngle_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class protonAngle {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   UInt_t          eventno;
   UInt_t          seed1;
   UInt_t          seed2;
   UInt_t          gunn;
   Float_t         gunt[25];   //[gunn]
   Float_t         gunx[25];   //[gunn]
   Float_t         guny[25];   //[gunn]
   Float_t         gunz[25];   //[gunn]
   Float_t         gunpx[25];   //[gunn]
   Float_t         gunpy[25];   //[gunn]
   Float_t         gunpz[25];   //[gunn]
   Float_t         gunp[25];   //[gunn]
   Float_t         gunT[25];   //[gunn]
   Float_t         gunboostbetax[25];   //[gunn]
   Float_t         gunboostbetay[25];   //[gunn]
   Float_t         gunboostbetaz[25];   //[gunn]
   Float_t         gunpreboostT[25];   //[gunn]
   Int_t           gunpdg[25];   //[gunn]
   Float_t         TST01sumE;
   UInt_t          TST01n;
   Float_t         TST01t[5];   //[TST01n]
   Float_t         TST01e[5];   //[TST01n]
   Float_t         TST01x[5];   //[TST01n]
   Float_t         TST01y[5];   //[TST01n]
   Float_t         TST01z[5];   //[TST01n]
   UInt_t          TST01inn;
   Float_t         TST01int[9];   //[TST01inn]
   Float_t         TST01inx[9];   //[TST01inn]
   Float_t         TST01iny[9];   //[TST01inn]
   Float_t         TST01inz[9];   //[TST01inn]
   Float_t         TST01inpx[9];   //[TST01inn]
   Float_t         TST01inpy[9];   //[TST01inn]
   Float_t         TST01inpz[9];   //[TST01inn]
   Float_t         TST01inp[9];   //[TST01inn]
   Float_t         TST01inT[9];   //[TST01inn]
   Int_t           TST01inpdg[9];   //[TST01inn]

   // List of branches
   TBranch        *b_eventno;   //!
   TBranch        *b_seed1;   //!
   TBranch        *b_seed2;   //!
   TBranch        *b_gunn;   //!
   TBranch        *b_gunt;   //!
   TBranch        *b_gunx;   //!
   TBranch        *b_guny;   //!
   TBranch        *b_gunz;   //!
   TBranch        *b_gunpx;   //!
   TBranch        *b_gunpy;   //!
   TBranch        *b_gunpz;   //!
   TBranch        *b_gunp;   //!
   TBranch        *b_gunT;   //!
   TBranch        *b_gunboostbetax;   //!
   TBranch        *b_gunboostbetay;   //!
   TBranch        *b_gunboostbetaz;   //!
   TBranch        *b_gunpreboostT;   //!
   TBranch        *b_gunpdg;   //!
   TBranch        *b_TST01sumE;   //!
   TBranch        *b_TST01n;   //!
   TBranch        *b_TST01t;   //!
   TBranch        *b_TST01e;   //!
   TBranch        *b_TST01x;   //!
   TBranch        *b_TST01y;   //!
   TBranch        *b_TST01z;   //!
   TBranch        *b_TST01inn;   //!
   TBranch        *b_TST01int;   //!
   TBranch        *b_TST01inx;   //!
   TBranch        *b_TST01iny;   //!
   TBranch        *b_TST01inz;   //!
   TBranch        *b_TST01inpx;   //!
   TBranch        *b_TST01inpy;   //!
   TBranch        *b_TST01inpz;   //!
   TBranch        *b_TST01inp;   //!
   TBranch        *b_TST01inT;   //!
   TBranch        *b_TST01inpdg;   //!

   protonAngle(const char *filename);
   virtual ~protonAngle();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);

public:
   const char *_filename;
};

#endif

#ifdef protonAngle_cxx
/*
protonAngle::protonAngle(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("helioscylinder.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("helioscylinder.root");
      }
      f->GetObject("h102",tree);

   }
   Init(tree);
}
*/

protonAngle::protonAngle(const char *filename) : fChain(0) 
{
  TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject(filename);
  if (!f || !f->IsOpen()) {
    f = new TFile(filename);
  }
  TTree *tree;
  f->GetObject("h102",tree);
  Init(tree);
  _filename = strdup(filename);
  
  this->Loop();
  exit(0);
}

protonAngle::~protonAngle()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t protonAngle::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t protonAngle::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void protonAngle::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("eventno", &eventno, &b_eventno);
   fChain->SetBranchAddress("seed1", &seed1, &b_seed1);
   fChain->SetBranchAddress("seed2", &seed2, &b_seed2);
   fChain->SetBranchAddress("gunn", &gunn, &b_gunn);
   fChain->SetBranchAddress("gunt", gunt, &b_gunt);
   fChain->SetBranchAddress("gunx", gunx, &b_gunx);
   fChain->SetBranchAddress("guny", guny, &b_guny);
   fChain->SetBranchAddress("gunz", gunz, &b_gunz);
   fChain->SetBranchAddress("gunpx", gunpx, &b_gunpx);
   fChain->SetBranchAddress("gunpy", gunpy, &b_gunpy);
   fChain->SetBranchAddress("gunpz", gunpz, &b_gunpz);
   fChain->SetBranchAddress("gunp", gunp, &b_gunp);
   fChain->SetBranchAddress("gunT", gunT, &b_gunT);
   fChain->SetBranchAddress("gunboostbetax", gunboostbetax, &b_gunboostbetax);
   fChain->SetBranchAddress("gunboostbetay", gunboostbetay, &b_gunboostbetay);
   fChain->SetBranchAddress("gunboostbetaz", gunboostbetaz, &b_gunboostbetaz);
   fChain->SetBranchAddress("gunpreboostT", gunpreboostT, &b_gunpreboostT);
   fChain->SetBranchAddress("gunpdg", gunpdg, &b_gunpdg);
   fChain->SetBranchAddress("TST01sumE", &TST01sumE, &b_TST01sumE);
   fChain->SetBranchAddress("TST01n", &TST01n, &b_TST01n);
   fChain->SetBranchAddress("TST01t", TST01t, &b_TST01t);
   fChain->SetBranchAddress("TST01e", TST01e, &b_TST01e);
   fChain->SetBranchAddress("TST01x", TST01x, &b_TST01x);
   fChain->SetBranchAddress("TST01y", TST01y, &b_TST01y);
   fChain->SetBranchAddress("TST01z", TST01z, &b_TST01z);
   fChain->SetBranchAddress("TST01inn", &TST01inn, &b_TST01inn);
   fChain->SetBranchAddress("TST01int", TST01int, &b_TST01int);
   fChain->SetBranchAddress("TST01inx", TST01inx, &b_TST01inx);
   fChain->SetBranchAddress("TST01iny", TST01iny, &b_TST01iny);
   fChain->SetBranchAddress("TST01inz", TST01inz, &b_TST01inz);
   fChain->SetBranchAddress("TST01inpx", TST01inpx, &b_TST01inpx);
   fChain->SetBranchAddress("TST01inpy", TST01inpy, &b_TST01inpy);
   fChain->SetBranchAddress("TST01inpz", TST01inpz, &b_TST01inpz);
   fChain->SetBranchAddress("TST01inp", TST01inp, &b_TST01inp);
   fChain->SetBranchAddress("TST01inT", TST01inT, &b_TST01inT);
   fChain->SetBranchAddress("TST01inpdg", TST01inpdg, &b_TST01inpdg);
   Notify();
}

Bool_t protonAngle::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void protonAngle::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t protonAngle::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef protonAngle_cxx
