#!/bin/bash
for B in 2 #2.5
do
    for Ex in 10
    do
        for DIST in 8
        do
        ~/ggland_test/scripts/ggland/land_geant4 \
            --test-01=dz=37.465cm,z0=-24cm,ir=0.8cm,r=1.2cm,type=Si,enter,tree=1 \
            --test-13=dz=0.01cm,z0=-5.2674cm,r=1.2cm,type=blackhole,enter,tree=1 \
            --gun=d,dummy,T=0MeV,setboost,feed=target \
            --gun=from=target,Ac229,dummy,T/u=8MeV/u,addboost,feed=cm \
            --gun=from=cm,p,T=$((18-Ex))MeV,isotropic,boost,subboost,feed=recoil \
            --gun=from=recoil,Ac230,recoil,setboost,dummy,feed=compound\
            --gun-file=maxparticles=80,gun_230Ac_${Ex}MeV.txt,from=compound,boost\
            --world=type=vacuum\
            --fieldbox=d=200cm,Bz=${B}T \
            --events=100000 \
            --tree=heliosblackholecylinder.root
            #--cmd=visu_helios.mac
            
        
	        
	    done
    done
done
    #--events=2\
    #--tree=allevents,part,helios_230Ac_${Ex}MeV_S3_${DIST}cm_${B}T.root
    #--test-00=dz=4cm,z0=44cm,dx=60cm,dy=60cm,type=blackhole,enter,tree=1\
    # --test-0=dz=31.2cm,z0=-17.6cm,dx=1.6cm,dy=1.6cm,type=Si,enter,tree=1 \
    #
    ###LESS FANCY HELIOS (4 Si detectors 35cm-long)
    #
    #`for i in 0 1 2 3;do echo " --test-$((i+1))=dz=35cm,dx=1.2cm,dy=0.07cm,y0=0.82cm,z0=-19.5cm,rotz=$((i*90))deg,type=Si,tree=1";done`\
    #
    ###FANCY HELIOS NEW
    #
    #
    # `for i in 0 1 2 3;do echo " --test-$((i+1))=dz=5cm,dx=1cm,dy=0.08cm,y0=0.84cm,z0=-4.5cm,rotz=$((i*90))deg,type=Si,tree=1";done`\
    # `for i in 0 1 2 3;do echo " --test-$((i+5))=dz=5cm,dx=1cm,dy=0.08cm,y0=0.84cm,z0=-9.74cm,rotz=$((i*90))deg,type=Si,tree=1";done`\
    # `for i in 0 1 2 3;do echo " --test-$((i+9))=dz=5cm,dx=1cm,dy=0.08cm,y0=0.84cm,z0=-14.98cm,rotz=$((i*90))deg,type=Si,tree=1";done`\
    # `for i in 0 1 2 3;do echo " --test-$((i+13))=dz=5cm,dx=1cm,dy=0.08cm,y0=0.84cm,z0=-20.22cm,rotz=$((i*90))deg,type=Si,tree=1";done`\
    # `for i in 0 1 2 3;do echo " --test-$((i+17))=dz=5cm,dx=1cm,dy=0.08cm,y0=0.84cm,z0=-25.46cm,rotz=$((i*90))deg,type=Si,tree=1";done`\
    # `for i in 0 1 2 3;do echo " --test-$((i+21))=dz=5cm,dx=1cm,dy=0.08cm,y0=0.84cm,z0=-30.7cm,rotz=$((i*90))deg,type=Si,tree=1";done`\
    #
    ###FANCY HELIOS OLD
    #
    # `for i in 0 1 2 3;do echo " --test-$((i+1))=dz=5.1cm,dx=1cm,dy=0.08cm,y0=0.84cm,z0=-4.825cm,rotz=$((i*90))deg,type=Si,tree=1";done`\
    # `for i in 0 1 2 3;do echo " --test-$((i+5))=dz=5cm,dx=1cm,dy=0.08cm,y0=0.84cm,z0=-10.675cm,rotz=$((i*90))deg,type=Si,tree=1";done`\
    # `for i in 0 1 2 3;do echo " --test-$((i+9))=dz=5cm,dx=1cm,dy=0.08cm,y0=0.84cm,z0=-16.525cm,rotz=$((i*90))deg,type=Si,tree=1";done`\
    # `for i in 0 1 2 3;do echo " --test-$((i+13))=dz=5cm,dx=1cm,dy=0.08cm,y0=0.84cm,z0=-22.375cm,rotz=$((i*90))deg,type=Si,tree=1";done`\
    # `for i in 0 1 2 3;do echo " --test-$((i+17))=dz=5cm,dx=1cm,dy=0.08cm,y0=0.84cm,z0=-28.225cm,rotz=$((i*90))deg,type=Si,tree=1";done`\
    # `for i in 0 1 2 3;do echo " --test-$((i+21))=dz=5cm,dx=1cm,dy=0.08cm,y0=0.84cm,z0=-34.075cm,rotz=$((i*90))deg,type=Si,tree=1";done`\
