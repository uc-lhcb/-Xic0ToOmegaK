#!/bin/bash
############################################################################
#Setup the environment for the Xic0ToOmegaK analysis
#USAGE: source setup.sh [<LCG-version>] [<platform>]
#       <LCG-version> defaults to 95
#       <platform>    defaults to x86_64-centos7-gcc8-opt
############################################################################

printf "\033[1;37m INFO   \033[0m: Setting up environment for the Xic0ToOmegaK analysis\n"

#parse lcg version
if [ -z "$1" ];then
  printf "\033[1;37m INFO   \033[0m: No LCG version specified. Defaulting to 95\n"
  LCG_VER="95"
else
  LCG_VER="$1"
fi

#parse platform
if [ -z "$2" ];then
  printf "\033[1;37m INFO   \033[0m: No platform specified. Defaulting to x86_64-centos7-gcc8-opt\n"
  PLTF="x86_64-centos7-gcc8-opt"
else
  PLTF="$2"
fi

SFT_DIR=/cvmfs/sft.cern.ch/lcg/views/LCG_$LCG_VER/$PLTF

#for implicit multithreading
export OPENBLAS_MAIN_FREE=1

if [ -d "$SFT_DIR" ]; then
  printf "\033[1;37m INFO   \033[0m: Setting up environment from LCG $LCG_VER views in $SFT_DIR\n"
  source $SFT_DIR/setup.sh
  printf "\033[1;32m SUCCESS\033[0m: LCG environment was set up\n"
else
  printf "\033[1;31m ERROR  \033[0m: Can not setup environment. Make sure cvmfs is mounted..."
fi

alias gitmagic='eval "$(ssh-agent -s)";ssh-add ~/.ssh/id_rsa'
SetupXic0ToOmegaK(){
  cd ~/work/Xic0ToOmegaK
  export DUMPDIR=/share/lazy/David/Xic0ToOmegaK
  export TUPLEDIR=<directory where the tuples are>
  gitmagic
  . setup.sh
}
