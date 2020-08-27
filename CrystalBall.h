//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Aug 25 13:25:20 2020 by ROOT version 6.18/00
// from TTree DecayTree/DecayTree
// found on file: Large_2017.root
//////////////////////////////////////////////////////////

#ifndef CrystalBall_h
#define CrystalBall_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include <TTreeReader.h>
#include <TTreeReaderValue.h>
#include <TTreeReaderArray.h>

// Headers needed by this particular selector


class CrystalBall : public TSelector {
public :
   TTreeReader     fReader;  //!the tree reader
   TTree          *fChain = 0;   //!pointer to the analyzed TTree or TChain

   // Readers to access the data (delete the ones you do not need).
   TTreeReaderValue<Double_t> Xi_c0_ENDVERTEX_X = {fReader, "Xi_c0_ENDVERTEX_X"};
   TTreeReaderValue<Double_t> Xi_c0_ENDVERTEX_Y = {fReader, "Xi_c0_ENDVERTEX_Y"};
   TTreeReaderValue<Double_t> Xi_c0_ENDVERTEX_Z = {fReader, "Xi_c0_ENDVERTEX_Z"};
   TTreeReaderValue<Double_t> Xi_c0_ENDVERTEX_XERR = {fReader, "Xi_c0_ENDVERTEX_XERR"};
   TTreeReaderValue<Double_t> Xi_c0_ENDVERTEX_YERR = {fReader, "Xi_c0_ENDVERTEX_YERR"};
   TTreeReaderValue<Double_t> Xi_c0_ENDVERTEX_ZERR = {fReader, "Xi_c0_ENDVERTEX_ZERR"};
   TTreeReaderValue<Double_t> Xi_c0_ENDVERTEX_CHI2 = {fReader, "Xi_c0_ENDVERTEX_CHI2"};
   TTreeReaderValue<Int_t> Xi_c0_ENDVERTEX_NDOF = {fReader, "Xi_c0_ENDVERTEX_NDOF"};
   TTreeReaderValue<Double_t> Xi_c0_OWNPV_X = {fReader, "Xi_c0_OWNPV_X"};
   TTreeReaderValue<Double_t> Xi_c0_OWNPV_Y = {fReader, "Xi_c0_OWNPV_Y"};
   TTreeReaderValue<Double_t> Xi_c0_OWNPV_Z = {fReader, "Xi_c0_OWNPV_Z"};
   TTreeReaderValue<Double_t> Xi_c0_OWNPV_XERR = {fReader, "Xi_c0_OWNPV_XERR"};
   TTreeReaderValue<Double_t> Xi_c0_OWNPV_YERR = {fReader, "Xi_c0_OWNPV_YERR"};
   TTreeReaderValue<Double_t> Xi_c0_OWNPV_ZERR = {fReader, "Xi_c0_OWNPV_ZERR"};
   TTreeReaderValue<Double_t> Xi_c0_OWNPV_CHI2 = {fReader, "Xi_c0_OWNPV_CHI2"};
   TTreeReaderValue<Int_t> Xi_c0_OWNPV_NDOF = {fReader, "Xi_c0_OWNPV_NDOF"};
   TTreeReaderValue<Double_t> Xi_c0_IP_OWNPV = {fReader, "Xi_c0_IP_OWNPV"};
   TTreeReaderValue<Double_t> Xi_c0_IPCHI2_OWNPV = {fReader, "Xi_c0_IPCHI2_OWNPV"};
   TTreeReaderValue<Double_t> Xi_c0_FD_OWNPV = {fReader, "Xi_c0_FD_OWNPV"};
   TTreeReaderValue<Double_t> Xi_c0_FDCHI2_OWNPV = {fReader, "Xi_c0_FDCHI2_OWNPV"};
   TTreeReaderValue<Double_t> Xi_c0_DIRA_OWNPV = {fReader, "Xi_c0_DIRA_OWNPV"};
   TTreeReaderValue<Double_t> Xi_c0_P = {fReader, "Xi_c0_P"};
   TTreeReaderValue<Double_t> Xi_c0_PT = {fReader, "Xi_c0_PT"};
   TTreeReaderValue<Double_t> Xi_c0_PE = {fReader, "Xi_c0_PE"};
   TTreeReaderValue<Double_t> Xi_c0_PX = {fReader, "Xi_c0_PX"};
   TTreeReaderValue<Double_t> Xi_c0_PY = {fReader, "Xi_c0_PY"};
   TTreeReaderValue<Double_t> Xi_c0_PZ = {fReader, "Xi_c0_PZ"};
   TTreeReaderValue<Double_t> Xi_c0_MM = {fReader, "Xi_c0_MM"};
   TTreeReaderValue<Double_t> Xi_c0_MMERR = {fReader, "Xi_c0_MMERR"};
   TTreeReaderValue<Double_t> Xi_c0_M = {fReader, "Xi_c0_M"};
   TTreeReaderValue<Int_t> Xi_c0_ID = {fReader, "Xi_c0_ID"};
   TTreeReaderValue<Double_t> Xi_c0_TAU = {fReader, "Xi_c0_TAU"};
   TTreeReaderValue<Double_t> Xi_c0_TAUERR = {fReader, "Xi_c0_TAUERR"};
   TTreeReaderValue<Double_t> Xi_c0_TAUCHI2 = {fReader, "Xi_c0_TAUCHI2"};
   TTreeReaderValue<Bool_t> Xi_c0_L0Global_Dec = {fReader, "Xi_c0_L0Global_Dec"};
   TTreeReaderValue<Bool_t> Xi_c0_L0Global_TIS = {fReader, "Xi_c0_L0Global_TIS"};
   TTreeReaderValue<Bool_t> Xi_c0_L0Global_TOS = {fReader, "Xi_c0_L0Global_TOS"};
   TTreeReaderValue<Bool_t> Xi_c0_Hlt1Global_Dec = {fReader, "Xi_c0_Hlt1Global_Dec"};
   TTreeReaderValue<Bool_t> Xi_c0_Hlt1Global_TIS = {fReader, "Xi_c0_Hlt1Global_TIS"};
   TTreeReaderValue<Bool_t> Xi_c0_Hlt1Global_TOS = {fReader, "Xi_c0_Hlt1Global_TOS"};
   TTreeReaderValue<Bool_t> Xi_c0_Hlt1Phys_Dec = {fReader, "Xi_c0_Hlt1Phys_Dec"};
   TTreeReaderValue<Bool_t> Xi_c0_Hlt1Phys_TIS = {fReader, "Xi_c0_Hlt1Phys_TIS"};
   TTreeReaderValue<Bool_t> Xi_c0_Hlt1Phys_TOS = {fReader, "Xi_c0_Hlt1Phys_TOS"};
   TTreeReaderValue<Double_t> Xi_c0_X = {fReader, "Xi_c0_X"};
   TTreeReaderValue<Double_t> Xi_c0_Y = {fReader, "Xi_c0_Y"};
   TTreeReaderValue<Double_t> Omega_ENDVERTEX_X = {fReader, "Omega_ENDVERTEX_X"};
   TTreeReaderValue<Double_t> Omega_ENDVERTEX_Y = {fReader, "Omega_ENDVERTEX_Y"};
   TTreeReaderValue<Double_t> Omega_ENDVERTEX_Z = {fReader, "Omega_ENDVERTEX_Z"};
   TTreeReaderValue<Double_t> Omega_ENDVERTEX_XERR = {fReader, "Omega_ENDVERTEX_XERR"};
   TTreeReaderValue<Double_t> Omega_ENDVERTEX_YERR = {fReader, "Omega_ENDVERTEX_YERR"};
   TTreeReaderValue<Double_t> Omega_ENDVERTEX_ZERR = {fReader, "Omega_ENDVERTEX_ZERR"};
   TTreeReaderValue<Double_t> Omega_ENDVERTEX_CHI2 = {fReader, "Omega_ENDVERTEX_CHI2"};
   TTreeReaderValue<Int_t> Omega_ENDVERTEX_NDOF = {fReader, "Omega_ENDVERTEX_NDOF"};
   TTreeReaderValue<Double_t> Omega_OWNPV_X = {fReader, "Omega_OWNPV_X"};
   TTreeReaderValue<Double_t> Omega_OWNPV_Y = {fReader, "Omega_OWNPV_Y"};
   TTreeReaderValue<Double_t> Omega_OWNPV_Z = {fReader, "Omega_OWNPV_Z"};
   TTreeReaderValue<Double_t> Omega_OWNPV_XERR = {fReader, "Omega_OWNPV_XERR"};
   TTreeReaderValue<Double_t> Omega_OWNPV_YERR = {fReader, "Omega_OWNPV_YERR"};
   TTreeReaderValue<Double_t> Omega_OWNPV_ZERR = {fReader, "Omega_OWNPV_ZERR"};
   TTreeReaderValue<Double_t> Omega_OWNPV_CHI2 = {fReader, "Omega_OWNPV_CHI2"};
   TTreeReaderValue<Int_t> Omega_OWNPV_NDOF = {fReader, "Omega_OWNPV_NDOF"};
   TTreeReaderValue<Double_t> Omega_IP_OWNPV = {fReader, "Omega_IP_OWNPV"};
   TTreeReaderValue<Double_t> Omega_IPCHI2_OWNPV = {fReader, "Omega_IPCHI2_OWNPV"};
   TTreeReaderValue<Double_t> Omega_FD_OWNPV = {fReader, "Omega_FD_OWNPV"};
   TTreeReaderValue<Double_t> Omega_FDCHI2_OWNPV = {fReader, "Omega_FDCHI2_OWNPV"};
   TTreeReaderValue<Double_t> Omega_DIRA_OWNPV = {fReader, "Omega_DIRA_OWNPV"};
   TTreeReaderValue<Double_t> Omega_ORIVX_X = {fReader, "Omega_ORIVX_X"};
   TTreeReaderValue<Double_t> Omega_ORIVX_Y = {fReader, "Omega_ORIVX_Y"};
   TTreeReaderValue<Double_t> Omega_ORIVX_Z = {fReader, "Omega_ORIVX_Z"};
   TTreeReaderValue<Double_t> Omega_ORIVX_XERR = {fReader, "Omega_ORIVX_XERR"};
   TTreeReaderValue<Double_t> Omega_ORIVX_YERR = {fReader, "Omega_ORIVX_YERR"};
   TTreeReaderValue<Double_t> Omega_ORIVX_ZERR = {fReader, "Omega_ORIVX_ZERR"};
   TTreeReaderValue<Double_t> Omega_ORIVX_CHI2 = {fReader, "Omega_ORIVX_CHI2"};
   TTreeReaderValue<Int_t> Omega_ORIVX_NDOF = {fReader, "Omega_ORIVX_NDOF"};
   TTreeReaderValue<Double_t> Omega_FD_ORIVX = {fReader, "Omega_FD_ORIVX"};
   TTreeReaderValue<Double_t> Omega_FDCHI2_ORIVX = {fReader, "Omega_FDCHI2_ORIVX"};
   TTreeReaderValue<Double_t> Omega_DIRA_ORIVX = {fReader, "Omega_DIRA_ORIVX"};
   TTreeReaderValue<Double_t> Omega_P = {fReader, "Omega_P"};
   TTreeReaderValue<Double_t> Omega_PT = {fReader, "Omega_PT"};
   TTreeReaderValue<Double_t> Omega_PE = {fReader, "Omega_PE"};
   TTreeReaderValue<Double_t> Omega_PX = {fReader, "Omega_PX"};
   TTreeReaderValue<Double_t> Omega_PY = {fReader, "Omega_PY"};
   TTreeReaderValue<Double_t> Omega_PZ = {fReader, "Omega_PZ"};
   TTreeReaderValue<Double_t> Omega_MM = {fReader, "Omega_MM"};
   TTreeReaderValue<Double_t> Omega_MMERR = {fReader, "Omega_MMERR"};
   TTreeReaderValue<Double_t> Omega_M = {fReader, "Omega_M"};
   TTreeReaderValue<Int_t> Omega_ID = {fReader, "Omega_ID"};
   TTreeReaderValue<Double_t> Omega_TAU = {fReader, "Omega_TAU"};
   TTreeReaderValue<Double_t> Omega_TAUERR = {fReader, "Omega_TAUERR"};
   TTreeReaderValue<Double_t> Omega_TAUCHI2 = {fReader, "Omega_TAUCHI2"};
   TTreeReaderValue<Bool_t> Omega_L0Global_Dec = {fReader, "Omega_L0Global_Dec"};
   TTreeReaderValue<Bool_t> Omega_L0Global_TIS = {fReader, "Omega_L0Global_TIS"};
   TTreeReaderValue<Bool_t> Omega_L0Global_TOS = {fReader, "Omega_L0Global_TOS"};
   TTreeReaderValue<Bool_t> Omega_Hlt1Global_Dec = {fReader, "Omega_Hlt1Global_Dec"};
   TTreeReaderValue<Bool_t> Omega_Hlt1Global_TIS = {fReader, "Omega_Hlt1Global_TIS"};
   TTreeReaderValue<Bool_t> Omega_Hlt1Global_TOS = {fReader, "Omega_Hlt1Global_TOS"};
   TTreeReaderValue<Bool_t> Omega_Hlt1Phys_Dec = {fReader, "Omega_Hlt1Phys_Dec"};
   TTreeReaderValue<Bool_t> Omega_Hlt1Phys_TIS = {fReader, "Omega_Hlt1Phys_TIS"};
   TTreeReaderValue<Bool_t> Omega_Hlt1Phys_TOS = {fReader, "Omega_Hlt1Phys_TOS"};
   TTreeReaderValue<Double_t> Omega_X = {fReader, "Omega_X"};
   TTreeReaderValue<Double_t> Omega_Y = {fReader, "Omega_Y"};
   TTreeReaderValue<Double_t> Lambda_ENDVERTEX_X = {fReader, "Lambda_ENDVERTEX_X"};
   TTreeReaderValue<Double_t> Lambda_ENDVERTEX_Y = {fReader, "Lambda_ENDVERTEX_Y"};
   TTreeReaderValue<Double_t> Lambda_ENDVERTEX_Z = {fReader, "Lambda_ENDVERTEX_Z"};
   TTreeReaderValue<Double_t> Lambda_ENDVERTEX_XERR = {fReader, "Lambda_ENDVERTEX_XERR"};
   TTreeReaderValue<Double_t> Lambda_ENDVERTEX_YERR = {fReader, "Lambda_ENDVERTEX_YERR"};
   TTreeReaderValue<Double_t> Lambda_ENDVERTEX_ZERR = {fReader, "Lambda_ENDVERTEX_ZERR"};
   TTreeReaderValue<Double_t> Lambda_ENDVERTEX_CHI2 = {fReader, "Lambda_ENDVERTEX_CHI2"};
   TTreeReaderValue<Int_t> Lambda_ENDVERTEX_NDOF = {fReader, "Lambda_ENDVERTEX_NDOF"};
   TTreeReaderValue<Double_t> Lambda_OWNPV_X = {fReader, "Lambda_OWNPV_X"};
   TTreeReaderValue<Double_t> Lambda_OWNPV_Y = {fReader, "Lambda_OWNPV_Y"};
   TTreeReaderValue<Double_t> Lambda_OWNPV_Z = {fReader, "Lambda_OWNPV_Z"};
   TTreeReaderValue<Double_t> Lambda_OWNPV_XERR = {fReader, "Lambda_OWNPV_XERR"};
   TTreeReaderValue<Double_t> Lambda_OWNPV_YERR = {fReader, "Lambda_OWNPV_YERR"};
   TTreeReaderValue<Double_t> Lambda_OWNPV_ZERR = {fReader, "Lambda_OWNPV_ZERR"};
   TTreeReaderValue<Double_t> Lambda_OWNPV_CHI2 = {fReader, "Lambda_OWNPV_CHI2"};
   TTreeReaderValue<Int_t> Lambda_OWNPV_NDOF = {fReader, "Lambda_OWNPV_NDOF"};
   TTreeReaderValue<Double_t> Lambda_IP_OWNPV = {fReader, "Lambda_IP_OWNPV"};
   TTreeReaderValue<Double_t> Lambda_IPCHI2_OWNPV = {fReader, "Lambda_IPCHI2_OWNPV"};
   TTreeReaderValue<Double_t> Lambda_FD_OWNPV = {fReader, "Lambda_FD_OWNPV"};
   TTreeReaderValue<Double_t> Lambda_FDCHI2_OWNPV = {fReader, "Lambda_FDCHI2_OWNPV"};
   TTreeReaderValue<Double_t> Lambda_DIRA_OWNPV = {fReader, "Lambda_DIRA_OWNPV"};
   TTreeReaderValue<Double_t> Lambda_ORIVX_X = {fReader, "Lambda_ORIVX_X"};
   TTreeReaderValue<Double_t> Lambda_ORIVX_Y = {fReader, "Lambda_ORIVX_Y"};
   TTreeReaderValue<Double_t> Lambda_ORIVX_Z = {fReader, "Lambda_ORIVX_Z"};
   TTreeReaderValue<Double_t> Lambda_ORIVX_XERR = {fReader, "Lambda_ORIVX_XERR"};
   TTreeReaderValue<Double_t> Lambda_ORIVX_YERR = {fReader, "Lambda_ORIVX_YERR"};
   TTreeReaderValue<Double_t> Lambda_ORIVX_ZERR = {fReader, "Lambda_ORIVX_ZERR"};
   TTreeReaderValue<Double_t> Lambda_ORIVX_CHI2 = {fReader, "Lambda_ORIVX_CHI2"};
   TTreeReaderValue<Int_t> Lambda_ORIVX_NDOF = {fReader, "Lambda_ORIVX_NDOF"};
   TTreeReaderValue<Double_t> Lambda_FD_ORIVX = {fReader, "Lambda_FD_ORIVX"};
   TTreeReaderValue<Double_t> Lambda_FDCHI2_ORIVX = {fReader, "Lambda_FDCHI2_ORIVX"};
   TTreeReaderValue<Double_t> Lambda_DIRA_ORIVX = {fReader, "Lambda_DIRA_ORIVX"};
   TTreeReaderValue<Double_t> Lambda_P = {fReader, "Lambda_P"};
   TTreeReaderValue<Double_t> Lambda_PT = {fReader, "Lambda_PT"};
   TTreeReaderValue<Double_t> Lambda_PE = {fReader, "Lambda_PE"};
   TTreeReaderValue<Double_t> Lambda_PX = {fReader, "Lambda_PX"};
   TTreeReaderValue<Double_t> Lambda_PY = {fReader, "Lambda_PY"};
   TTreeReaderValue<Double_t> Lambda_PZ = {fReader, "Lambda_PZ"};
   TTreeReaderValue<Double_t> Lambda_MM = {fReader, "Lambda_MM"};
   TTreeReaderValue<Double_t> Lambda_MMERR = {fReader, "Lambda_MMERR"};
   TTreeReaderValue<Double_t> Lambda_M = {fReader, "Lambda_M"};
   TTreeReaderValue<Int_t> Lambda_ID = {fReader, "Lambda_ID"};
   TTreeReaderValue<Double_t> Lambda_TAU = {fReader, "Lambda_TAU"};
   TTreeReaderValue<Double_t> Lambda_TAUERR = {fReader, "Lambda_TAUERR"};
   TTreeReaderValue<Double_t> Lambda_TAUCHI2 = {fReader, "Lambda_TAUCHI2"};
   TTreeReaderValue<Bool_t> Lambda_L0Global_Dec = {fReader, "Lambda_L0Global_Dec"};
   TTreeReaderValue<Bool_t> Lambda_L0Global_TIS = {fReader, "Lambda_L0Global_TIS"};
   TTreeReaderValue<Bool_t> Lambda_L0Global_TOS = {fReader, "Lambda_L0Global_TOS"};
   TTreeReaderValue<Bool_t> Lambda_Hlt1Global_Dec = {fReader, "Lambda_Hlt1Global_Dec"};
   TTreeReaderValue<Bool_t> Lambda_Hlt1Global_TIS = {fReader, "Lambda_Hlt1Global_TIS"};
   TTreeReaderValue<Bool_t> Lambda_Hlt1Global_TOS = {fReader, "Lambda_Hlt1Global_TOS"};
   TTreeReaderValue<Bool_t> Lambda_Hlt1Phys_Dec = {fReader, "Lambda_Hlt1Phys_Dec"};
   TTreeReaderValue<Bool_t> Lambda_Hlt1Phys_TIS = {fReader, "Lambda_Hlt1Phys_TIS"};
   TTreeReaderValue<Bool_t> Lambda_Hlt1Phys_TOS = {fReader, "Lambda_Hlt1Phys_TOS"};
   TTreeReaderValue<Double_t> Lambda_X = {fReader, "Lambda_X"};
   TTreeReaderValue<Double_t> Lambda_Y = {fReader, "Lambda_Y"};
   TTreeReaderValue<Double_t> LambdaPr_MC12TuneV2_ProbNNe = {fReader, "LambdaPr_MC12TuneV2_ProbNNe"};
   TTreeReaderValue<Double_t> LambdaPr_MC12TuneV2_ProbNNmu = {fReader, "LambdaPr_MC12TuneV2_ProbNNmu"};
   TTreeReaderValue<Double_t> LambdaPr_MC12TuneV2_ProbNNpi = {fReader, "LambdaPr_MC12TuneV2_ProbNNpi"};
   TTreeReaderValue<Double_t> LambdaPr_MC12TuneV2_ProbNNk = {fReader, "LambdaPr_MC12TuneV2_ProbNNk"};
   TTreeReaderValue<Double_t> LambdaPr_MC12TuneV2_ProbNNp = {fReader, "LambdaPr_MC12TuneV2_ProbNNp"};
   TTreeReaderValue<Double_t> LambdaPr_MC12TuneV2_ProbNNghost = {fReader, "LambdaPr_MC12TuneV2_ProbNNghost"};
   TTreeReaderValue<Double_t> LambdaPr_MC12TuneV3_ProbNNe = {fReader, "LambdaPr_MC12TuneV3_ProbNNe"};
   TTreeReaderValue<Double_t> LambdaPr_MC12TuneV3_ProbNNmu = {fReader, "LambdaPr_MC12TuneV3_ProbNNmu"};
   TTreeReaderValue<Double_t> LambdaPr_MC12TuneV3_ProbNNpi = {fReader, "LambdaPr_MC12TuneV3_ProbNNpi"};
   TTreeReaderValue<Double_t> LambdaPr_MC12TuneV3_ProbNNk = {fReader, "LambdaPr_MC12TuneV3_ProbNNk"};
   TTreeReaderValue<Double_t> LambdaPr_MC12TuneV3_ProbNNp = {fReader, "LambdaPr_MC12TuneV3_ProbNNp"};
   TTreeReaderValue<Double_t> LambdaPr_MC12TuneV3_ProbNNghost = {fReader, "LambdaPr_MC12TuneV3_ProbNNghost"};
   TTreeReaderValue<Double_t> LambdaPr_MC12TuneV4_ProbNNe = {fReader, "LambdaPr_MC12TuneV4_ProbNNe"};
   TTreeReaderValue<Double_t> LambdaPr_MC12TuneV4_ProbNNmu = {fReader, "LambdaPr_MC12TuneV4_ProbNNmu"};
   TTreeReaderValue<Double_t> LambdaPr_MC12TuneV4_ProbNNpi = {fReader, "LambdaPr_MC12TuneV4_ProbNNpi"};
   TTreeReaderValue<Double_t> LambdaPr_MC12TuneV4_ProbNNk = {fReader, "LambdaPr_MC12TuneV4_ProbNNk"};
   TTreeReaderValue<Double_t> LambdaPr_MC12TuneV4_ProbNNp = {fReader, "LambdaPr_MC12TuneV4_ProbNNp"};
   TTreeReaderValue<Double_t> LambdaPr_MC12TuneV4_ProbNNghost = {fReader, "LambdaPr_MC12TuneV4_ProbNNghost"};
   TTreeReaderValue<Double_t> LambdaPr_MC15TuneV1_ProbNNe = {fReader, "LambdaPr_MC15TuneV1_ProbNNe"};
   TTreeReaderValue<Double_t> LambdaPr_MC15TuneV1_ProbNNmu = {fReader, "LambdaPr_MC15TuneV1_ProbNNmu"};
   TTreeReaderValue<Double_t> LambdaPr_MC15TuneV1_ProbNNpi = {fReader, "LambdaPr_MC15TuneV1_ProbNNpi"};
   TTreeReaderValue<Double_t> LambdaPr_MC15TuneV1_ProbNNk = {fReader, "LambdaPr_MC15TuneV1_ProbNNk"};
   TTreeReaderValue<Double_t> LambdaPr_MC15TuneV1_ProbNNp = {fReader, "LambdaPr_MC15TuneV1_ProbNNp"};
   TTreeReaderValue<Double_t> LambdaPr_MC15TuneV1_ProbNNghost = {fReader, "LambdaPr_MC15TuneV1_ProbNNghost"};
   TTreeReaderValue<Double_t> LambdaPr_OWNPV_X = {fReader, "LambdaPr_OWNPV_X"};
   TTreeReaderValue<Double_t> LambdaPr_OWNPV_Y = {fReader, "LambdaPr_OWNPV_Y"};
   TTreeReaderValue<Double_t> LambdaPr_OWNPV_Z = {fReader, "LambdaPr_OWNPV_Z"};
   TTreeReaderValue<Double_t> LambdaPr_OWNPV_XERR = {fReader, "LambdaPr_OWNPV_XERR"};
   TTreeReaderValue<Double_t> LambdaPr_OWNPV_YERR = {fReader, "LambdaPr_OWNPV_YERR"};
   TTreeReaderValue<Double_t> LambdaPr_OWNPV_ZERR = {fReader, "LambdaPr_OWNPV_ZERR"};
   TTreeReaderValue<Double_t> LambdaPr_OWNPV_CHI2 = {fReader, "LambdaPr_OWNPV_CHI2"};
   TTreeReaderValue<Int_t> LambdaPr_OWNPV_NDOF = {fReader, "LambdaPr_OWNPV_NDOF"};
   TTreeReaderValue<Double_t> LambdaPr_IP_OWNPV = {fReader, "LambdaPr_IP_OWNPV"};
   TTreeReaderValue<Double_t> LambdaPr_IPCHI2_OWNPV = {fReader, "LambdaPr_IPCHI2_OWNPV"};
   TTreeReaderValue<Double_t> LambdaPr_ORIVX_X = {fReader, "LambdaPr_ORIVX_X"};
   TTreeReaderValue<Double_t> LambdaPr_ORIVX_Y = {fReader, "LambdaPr_ORIVX_Y"};
   TTreeReaderValue<Double_t> LambdaPr_ORIVX_Z = {fReader, "LambdaPr_ORIVX_Z"};
   TTreeReaderValue<Double_t> LambdaPr_ORIVX_XERR = {fReader, "LambdaPr_ORIVX_XERR"};
   TTreeReaderValue<Double_t> LambdaPr_ORIVX_YERR = {fReader, "LambdaPr_ORIVX_YERR"};
   TTreeReaderValue<Double_t> LambdaPr_ORIVX_ZERR = {fReader, "LambdaPr_ORIVX_ZERR"};
   TTreeReaderValue<Double_t> LambdaPr_ORIVX_CHI2 = {fReader, "LambdaPr_ORIVX_CHI2"};
   TTreeReaderValue<Int_t> LambdaPr_ORIVX_NDOF = {fReader, "LambdaPr_ORIVX_NDOF"};
   TTreeReaderValue<Double_t> LambdaPr_P = {fReader, "LambdaPr_P"};
   TTreeReaderValue<Double_t> LambdaPr_PT = {fReader, "LambdaPr_PT"};
   TTreeReaderValue<Double_t> LambdaPr_PE = {fReader, "LambdaPr_PE"};
   TTreeReaderValue<Double_t> LambdaPr_PX = {fReader, "LambdaPr_PX"};
   TTreeReaderValue<Double_t> LambdaPr_PY = {fReader, "LambdaPr_PY"};
   TTreeReaderValue<Double_t> LambdaPr_PZ = {fReader, "LambdaPr_PZ"};
   TTreeReaderValue<Double_t> LambdaPr_M = {fReader, "LambdaPr_M"};
   TTreeReaderValue<Int_t> LambdaPr_ID = {fReader, "LambdaPr_ID"};
   TTreeReaderValue<Double_t> LambdaPr_PIDe = {fReader, "LambdaPr_PIDe"};
   TTreeReaderValue<Double_t> LambdaPr_PIDmu = {fReader, "LambdaPr_PIDmu"};
   TTreeReaderValue<Double_t> LambdaPr_PIDK = {fReader, "LambdaPr_PIDK"};
   TTreeReaderValue<Double_t> LambdaPr_PIDp = {fReader, "LambdaPr_PIDp"};
   TTreeReaderValue<Double_t> LambdaPr_PIDd = {fReader, "LambdaPr_PIDd"};
   TTreeReaderValue<Double_t> LambdaPr_ProbNNe = {fReader, "LambdaPr_ProbNNe"};
   TTreeReaderValue<Double_t> LambdaPr_ProbNNk = {fReader, "LambdaPr_ProbNNk"};
   TTreeReaderValue<Double_t> LambdaPr_ProbNNp = {fReader, "LambdaPr_ProbNNp"};
   TTreeReaderValue<Double_t> LambdaPr_ProbNNpi = {fReader, "LambdaPr_ProbNNpi"};
   TTreeReaderValue<Double_t> LambdaPr_ProbNNmu = {fReader, "LambdaPr_ProbNNmu"};
   TTreeReaderValue<Double_t> LambdaPr_ProbNNd = {fReader, "LambdaPr_ProbNNd"};
   TTreeReaderValue<Double_t> LambdaPr_ProbNNghost = {fReader, "LambdaPr_ProbNNghost"};
   TTreeReaderValue<Bool_t> LambdaPr_hasMuon = {fReader, "LambdaPr_hasMuon"};
   TTreeReaderValue<Bool_t> LambdaPr_isMuon = {fReader, "LambdaPr_isMuon"};
   TTreeReaderValue<Bool_t> LambdaPr_hasRich = {fReader, "LambdaPr_hasRich"};
   TTreeReaderValue<Bool_t> LambdaPr_UsedRichAerogel = {fReader, "LambdaPr_UsedRichAerogel"};
   TTreeReaderValue<Bool_t> LambdaPr_UsedRich1Gas = {fReader, "LambdaPr_UsedRich1Gas"};
   TTreeReaderValue<Bool_t> LambdaPr_UsedRich2Gas = {fReader, "LambdaPr_UsedRich2Gas"};
   TTreeReaderValue<Bool_t> LambdaPr_RichAboveElThres = {fReader, "LambdaPr_RichAboveElThres"};
   TTreeReaderValue<Bool_t> LambdaPr_RichAboveMuThres = {fReader, "LambdaPr_RichAboveMuThres"};
   TTreeReaderValue<Bool_t> LambdaPr_RichAbovePiThres = {fReader, "LambdaPr_RichAbovePiThres"};
   TTreeReaderValue<Bool_t> LambdaPr_RichAboveKaThres = {fReader, "LambdaPr_RichAboveKaThres"};
   TTreeReaderValue<Bool_t> LambdaPr_RichAbovePrThres = {fReader, "LambdaPr_RichAbovePrThres"};
   TTreeReaderValue<Bool_t> LambdaPr_hasCalo = {fReader, "LambdaPr_hasCalo"};
   TTreeReaderValue<Bool_t> LambdaPr_L0Global_Dec = {fReader, "LambdaPr_L0Global_Dec"};
   TTreeReaderValue<Bool_t> LambdaPr_L0Global_TIS = {fReader, "LambdaPr_L0Global_TIS"};
   TTreeReaderValue<Bool_t> LambdaPr_L0Global_TOS = {fReader, "LambdaPr_L0Global_TOS"};
   TTreeReaderValue<Bool_t> LambdaPr_Hlt1Global_Dec = {fReader, "LambdaPr_Hlt1Global_Dec"};
   TTreeReaderValue<Bool_t> LambdaPr_Hlt1Global_TIS = {fReader, "LambdaPr_Hlt1Global_TIS"};
   TTreeReaderValue<Bool_t> LambdaPr_Hlt1Global_TOS = {fReader, "LambdaPr_Hlt1Global_TOS"};
   TTreeReaderValue<Bool_t> LambdaPr_Hlt1Phys_Dec = {fReader, "LambdaPr_Hlt1Phys_Dec"};
   TTreeReaderValue<Bool_t> LambdaPr_Hlt1Phys_TIS = {fReader, "LambdaPr_Hlt1Phys_TIS"};
   TTreeReaderValue<Bool_t> LambdaPr_Hlt1Phys_TOS = {fReader, "LambdaPr_Hlt1Phys_TOS"};
   TTreeReaderValue<Int_t> LambdaPr_TRACK_Type = {fReader, "LambdaPr_TRACK_Type"};
   TTreeReaderValue<Int_t> LambdaPr_TRACK_Key = {fReader, "LambdaPr_TRACK_Key"};
   TTreeReaderValue<Double_t> LambdaPr_TRACK_CHI2NDOF = {fReader, "LambdaPr_TRACK_CHI2NDOF"};
   TTreeReaderValue<Double_t> LambdaPr_TRACK_PCHI2 = {fReader, "LambdaPr_TRACK_PCHI2"};
   TTreeReaderValue<Double_t> LambdaPr_TRACK_MatchCHI2 = {fReader, "LambdaPr_TRACK_MatchCHI2"};
   TTreeReaderValue<Double_t> LambdaPr_TRACK_GhostProb = {fReader, "LambdaPr_TRACK_GhostProb"};
   TTreeReaderValue<Double_t> LambdaPr_TRACK_CloneDist = {fReader, "LambdaPr_TRACK_CloneDist"};
   TTreeReaderValue<Double_t> LambdaPr_TRACK_Likelihood = {fReader, "LambdaPr_TRACK_Likelihood"};
   TTreeReaderValue<Double_t> LambdaPr_X = {fReader, "LambdaPr_X"};
   TTreeReaderValue<Double_t> LambdaPr_Y = {fReader, "LambdaPr_Y"};
   TTreeReaderValue<Double_t> LambdaPi_MC12TuneV2_ProbNNe = {fReader, "LambdaPi_MC12TuneV2_ProbNNe"};
   TTreeReaderValue<Double_t> LambdaPi_MC12TuneV2_ProbNNmu = {fReader, "LambdaPi_MC12TuneV2_ProbNNmu"};
   TTreeReaderValue<Double_t> LambdaPi_MC12TuneV2_ProbNNpi = {fReader, "LambdaPi_MC12TuneV2_ProbNNpi"};
   TTreeReaderValue<Double_t> LambdaPi_MC12TuneV2_ProbNNk = {fReader, "LambdaPi_MC12TuneV2_ProbNNk"};
   TTreeReaderValue<Double_t> LambdaPi_MC12TuneV2_ProbNNp = {fReader, "LambdaPi_MC12TuneV2_ProbNNp"};
   TTreeReaderValue<Double_t> LambdaPi_MC12TuneV2_ProbNNghost = {fReader, "LambdaPi_MC12TuneV2_ProbNNghost"};
   TTreeReaderValue<Double_t> LambdaPi_MC12TuneV3_ProbNNe = {fReader, "LambdaPi_MC12TuneV3_ProbNNe"};
   TTreeReaderValue<Double_t> LambdaPi_MC12TuneV3_ProbNNmu = {fReader, "LambdaPi_MC12TuneV3_ProbNNmu"};
   TTreeReaderValue<Double_t> LambdaPi_MC12TuneV3_ProbNNpi = {fReader, "LambdaPi_MC12TuneV3_ProbNNpi"};
   TTreeReaderValue<Double_t> LambdaPi_MC12TuneV3_ProbNNk = {fReader, "LambdaPi_MC12TuneV3_ProbNNk"};
   TTreeReaderValue<Double_t> LambdaPi_MC12TuneV3_ProbNNp = {fReader, "LambdaPi_MC12TuneV3_ProbNNp"};
   TTreeReaderValue<Double_t> LambdaPi_MC12TuneV3_ProbNNghost = {fReader, "LambdaPi_MC12TuneV3_ProbNNghost"};
   TTreeReaderValue<Double_t> LambdaPi_MC12TuneV4_ProbNNe = {fReader, "LambdaPi_MC12TuneV4_ProbNNe"};
   TTreeReaderValue<Double_t> LambdaPi_MC12TuneV4_ProbNNmu = {fReader, "LambdaPi_MC12TuneV4_ProbNNmu"};
   TTreeReaderValue<Double_t> LambdaPi_MC12TuneV4_ProbNNpi = {fReader, "LambdaPi_MC12TuneV4_ProbNNpi"};
   TTreeReaderValue<Double_t> LambdaPi_MC12TuneV4_ProbNNk = {fReader, "LambdaPi_MC12TuneV4_ProbNNk"};
   TTreeReaderValue<Double_t> LambdaPi_MC12TuneV4_ProbNNp = {fReader, "LambdaPi_MC12TuneV4_ProbNNp"};
   TTreeReaderValue<Double_t> LambdaPi_MC12TuneV4_ProbNNghost = {fReader, "LambdaPi_MC12TuneV4_ProbNNghost"};
   TTreeReaderValue<Double_t> LambdaPi_MC15TuneV1_ProbNNe = {fReader, "LambdaPi_MC15TuneV1_ProbNNe"};
   TTreeReaderValue<Double_t> LambdaPi_MC15TuneV1_ProbNNmu = {fReader, "LambdaPi_MC15TuneV1_ProbNNmu"};
   TTreeReaderValue<Double_t> LambdaPi_MC15TuneV1_ProbNNpi = {fReader, "LambdaPi_MC15TuneV1_ProbNNpi"};
   TTreeReaderValue<Double_t> LambdaPi_MC15TuneV1_ProbNNk = {fReader, "LambdaPi_MC15TuneV1_ProbNNk"};
   TTreeReaderValue<Double_t> LambdaPi_MC15TuneV1_ProbNNp = {fReader, "LambdaPi_MC15TuneV1_ProbNNp"};
   TTreeReaderValue<Double_t> LambdaPi_MC15TuneV1_ProbNNghost = {fReader, "LambdaPi_MC15TuneV1_ProbNNghost"};
   TTreeReaderValue<Double_t> LambdaPi_OWNPV_X = {fReader, "LambdaPi_OWNPV_X"};
   TTreeReaderValue<Double_t> LambdaPi_OWNPV_Y = {fReader, "LambdaPi_OWNPV_Y"};
   TTreeReaderValue<Double_t> LambdaPi_OWNPV_Z = {fReader, "LambdaPi_OWNPV_Z"};
   TTreeReaderValue<Double_t> LambdaPi_OWNPV_XERR = {fReader, "LambdaPi_OWNPV_XERR"};
   TTreeReaderValue<Double_t> LambdaPi_OWNPV_YERR = {fReader, "LambdaPi_OWNPV_YERR"};
   TTreeReaderValue<Double_t> LambdaPi_OWNPV_ZERR = {fReader, "LambdaPi_OWNPV_ZERR"};
   TTreeReaderValue<Double_t> LambdaPi_OWNPV_CHI2 = {fReader, "LambdaPi_OWNPV_CHI2"};
   TTreeReaderValue<Int_t> LambdaPi_OWNPV_NDOF = {fReader, "LambdaPi_OWNPV_NDOF"};
   TTreeReaderValue<Double_t> LambdaPi_IP_OWNPV = {fReader, "LambdaPi_IP_OWNPV"};
   TTreeReaderValue<Double_t> LambdaPi_IPCHI2_OWNPV = {fReader, "LambdaPi_IPCHI2_OWNPV"};
   TTreeReaderValue<Double_t> LambdaPi_ORIVX_X = {fReader, "LambdaPi_ORIVX_X"};
   TTreeReaderValue<Double_t> LambdaPi_ORIVX_Y = {fReader, "LambdaPi_ORIVX_Y"};
   TTreeReaderValue<Double_t> LambdaPi_ORIVX_Z = {fReader, "LambdaPi_ORIVX_Z"};
   TTreeReaderValue<Double_t> LambdaPi_ORIVX_XERR = {fReader, "LambdaPi_ORIVX_XERR"};
   TTreeReaderValue<Double_t> LambdaPi_ORIVX_YERR = {fReader, "LambdaPi_ORIVX_YERR"};
   TTreeReaderValue<Double_t> LambdaPi_ORIVX_ZERR = {fReader, "LambdaPi_ORIVX_ZERR"};
   TTreeReaderValue<Double_t> LambdaPi_ORIVX_CHI2 = {fReader, "LambdaPi_ORIVX_CHI2"};
   TTreeReaderValue<Int_t> LambdaPi_ORIVX_NDOF = {fReader, "LambdaPi_ORIVX_NDOF"};
   TTreeReaderValue<Double_t> LambdaPi_P = {fReader, "LambdaPi_P"};
   TTreeReaderValue<Double_t> LambdaPi_PT = {fReader, "LambdaPi_PT"};
   TTreeReaderValue<Double_t> LambdaPi_PE = {fReader, "LambdaPi_PE"};
   TTreeReaderValue<Double_t> LambdaPi_PX = {fReader, "LambdaPi_PX"};
   TTreeReaderValue<Double_t> LambdaPi_PY = {fReader, "LambdaPi_PY"};
   TTreeReaderValue<Double_t> LambdaPi_PZ = {fReader, "LambdaPi_PZ"};
   TTreeReaderValue<Double_t> LambdaPi_M = {fReader, "LambdaPi_M"};
   TTreeReaderValue<Int_t> LambdaPi_ID = {fReader, "LambdaPi_ID"};
   TTreeReaderValue<Double_t> LambdaPi_PIDe = {fReader, "LambdaPi_PIDe"};
   TTreeReaderValue<Double_t> LambdaPi_PIDmu = {fReader, "LambdaPi_PIDmu"};
   TTreeReaderValue<Double_t> LambdaPi_PIDK = {fReader, "LambdaPi_PIDK"};
   TTreeReaderValue<Double_t> LambdaPi_PIDp = {fReader, "LambdaPi_PIDp"};
   TTreeReaderValue<Double_t> LambdaPi_PIDd = {fReader, "LambdaPi_PIDd"};
   TTreeReaderValue<Double_t> LambdaPi_ProbNNe = {fReader, "LambdaPi_ProbNNe"};
   TTreeReaderValue<Double_t> LambdaPi_ProbNNk = {fReader, "LambdaPi_ProbNNk"};
   TTreeReaderValue<Double_t> LambdaPi_ProbNNp = {fReader, "LambdaPi_ProbNNp"};
   TTreeReaderValue<Double_t> LambdaPi_ProbNNpi = {fReader, "LambdaPi_ProbNNpi"};
   TTreeReaderValue<Double_t> LambdaPi_ProbNNmu = {fReader, "LambdaPi_ProbNNmu"};
   TTreeReaderValue<Double_t> LambdaPi_ProbNNd = {fReader, "LambdaPi_ProbNNd"};
   TTreeReaderValue<Double_t> LambdaPi_ProbNNghost = {fReader, "LambdaPi_ProbNNghost"};
   TTreeReaderValue<Bool_t> LambdaPi_hasMuon = {fReader, "LambdaPi_hasMuon"};
   TTreeReaderValue<Bool_t> LambdaPi_isMuon = {fReader, "LambdaPi_isMuon"};
   TTreeReaderValue<Bool_t> LambdaPi_hasRich = {fReader, "LambdaPi_hasRich"};
   TTreeReaderValue<Bool_t> LambdaPi_UsedRichAerogel = {fReader, "LambdaPi_UsedRichAerogel"};
   TTreeReaderValue<Bool_t> LambdaPi_UsedRich1Gas = {fReader, "LambdaPi_UsedRich1Gas"};
   TTreeReaderValue<Bool_t> LambdaPi_UsedRich2Gas = {fReader, "LambdaPi_UsedRich2Gas"};
   TTreeReaderValue<Bool_t> LambdaPi_RichAboveElThres = {fReader, "LambdaPi_RichAboveElThres"};
   TTreeReaderValue<Bool_t> LambdaPi_RichAboveMuThres = {fReader, "LambdaPi_RichAboveMuThres"};
   TTreeReaderValue<Bool_t> LambdaPi_RichAbovePiThres = {fReader, "LambdaPi_RichAbovePiThres"};
   TTreeReaderValue<Bool_t> LambdaPi_RichAboveKaThres = {fReader, "LambdaPi_RichAboveKaThres"};
   TTreeReaderValue<Bool_t> LambdaPi_RichAbovePrThres = {fReader, "LambdaPi_RichAbovePrThres"};
   TTreeReaderValue<Bool_t> LambdaPi_hasCalo = {fReader, "LambdaPi_hasCalo"};
   TTreeReaderValue<Bool_t> LambdaPi_L0Global_Dec = {fReader, "LambdaPi_L0Global_Dec"};
   TTreeReaderValue<Bool_t> LambdaPi_L0Global_TIS = {fReader, "LambdaPi_L0Global_TIS"};
   TTreeReaderValue<Bool_t> LambdaPi_L0Global_TOS = {fReader, "LambdaPi_L0Global_TOS"};
   TTreeReaderValue<Bool_t> LambdaPi_Hlt1Global_Dec = {fReader, "LambdaPi_Hlt1Global_Dec"};
   TTreeReaderValue<Bool_t> LambdaPi_Hlt1Global_TIS = {fReader, "LambdaPi_Hlt1Global_TIS"};
   TTreeReaderValue<Bool_t> LambdaPi_Hlt1Global_TOS = {fReader, "LambdaPi_Hlt1Global_TOS"};
   TTreeReaderValue<Bool_t> LambdaPi_Hlt1Phys_Dec = {fReader, "LambdaPi_Hlt1Phys_Dec"};
   TTreeReaderValue<Bool_t> LambdaPi_Hlt1Phys_TIS = {fReader, "LambdaPi_Hlt1Phys_TIS"};
   TTreeReaderValue<Bool_t> LambdaPi_Hlt1Phys_TOS = {fReader, "LambdaPi_Hlt1Phys_TOS"};
   TTreeReaderValue<Int_t> LambdaPi_TRACK_Type = {fReader, "LambdaPi_TRACK_Type"};
   TTreeReaderValue<Int_t> LambdaPi_TRACK_Key = {fReader, "LambdaPi_TRACK_Key"};
   TTreeReaderValue<Double_t> LambdaPi_TRACK_CHI2NDOF = {fReader, "LambdaPi_TRACK_CHI2NDOF"};
   TTreeReaderValue<Double_t> LambdaPi_TRACK_PCHI2 = {fReader, "LambdaPi_TRACK_PCHI2"};
   TTreeReaderValue<Double_t> LambdaPi_TRACK_MatchCHI2 = {fReader, "LambdaPi_TRACK_MatchCHI2"};
   TTreeReaderValue<Double_t> LambdaPi_TRACK_GhostProb = {fReader, "LambdaPi_TRACK_GhostProb"};
   TTreeReaderValue<Double_t> LambdaPi_TRACK_CloneDist = {fReader, "LambdaPi_TRACK_CloneDist"};
   TTreeReaderValue<Double_t> LambdaPi_TRACK_Likelihood = {fReader, "LambdaPi_TRACK_Likelihood"};
   TTreeReaderValue<Double_t> LambdaPi_X = {fReader, "LambdaPi_X"};
   TTreeReaderValue<Double_t> LambdaPi_Y = {fReader, "LambdaPi_Y"};
   TTreeReaderValue<Double_t> OmegaK_MC12TuneV2_ProbNNe = {fReader, "OmegaK_MC12TuneV2_ProbNNe"};
   TTreeReaderValue<Double_t> OmegaK_MC12TuneV2_ProbNNmu = {fReader, "OmegaK_MC12TuneV2_ProbNNmu"};
   TTreeReaderValue<Double_t> OmegaK_MC12TuneV2_ProbNNpi = {fReader, "OmegaK_MC12TuneV2_ProbNNpi"};
   TTreeReaderValue<Double_t> OmegaK_MC12TuneV2_ProbNNk = {fReader, "OmegaK_MC12TuneV2_ProbNNk"};
   TTreeReaderValue<Double_t> OmegaK_MC12TuneV2_ProbNNp = {fReader, "OmegaK_MC12TuneV2_ProbNNp"};
   TTreeReaderValue<Double_t> OmegaK_MC12TuneV2_ProbNNghost = {fReader, "OmegaK_MC12TuneV2_ProbNNghost"};
   TTreeReaderValue<Double_t> OmegaK_MC12TuneV3_ProbNNe = {fReader, "OmegaK_MC12TuneV3_ProbNNe"};
   TTreeReaderValue<Double_t> OmegaK_MC12TuneV3_ProbNNmu = {fReader, "OmegaK_MC12TuneV3_ProbNNmu"};
   TTreeReaderValue<Double_t> OmegaK_MC12TuneV3_ProbNNpi = {fReader, "OmegaK_MC12TuneV3_ProbNNpi"};
   TTreeReaderValue<Double_t> OmegaK_MC12TuneV3_ProbNNk = {fReader, "OmegaK_MC12TuneV3_ProbNNk"};
   TTreeReaderValue<Double_t> OmegaK_MC12TuneV3_ProbNNp = {fReader, "OmegaK_MC12TuneV3_ProbNNp"};
   TTreeReaderValue<Double_t> OmegaK_MC12TuneV3_ProbNNghost = {fReader, "OmegaK_MC12TuneV3_ProbNNghost"};
   TTreeReaderValue<Double_t> OmegaK_MC12TuneV4_ProbNNe = {fReader, "OmegaK_MC12TuneV4_ProbNNe"};
   TTreeReaderValue<Double_t> OmegaK_MC12TuneV4_ProbNNmu = {fReader, "OmegaK_MC12TuneV4_ProbNNmu"};
   TTreeReaderValue<Double_t> OmegaK_MC12TuneV4_ProbNNpi = {fReader, "OmegaK_MC12TuneV4_ProbNNpi"};
   TTreeReaderValue<Double_t> OmegaK_MC12TuneV4_ProbNNk = {fReader, "OmegaK_MC12TuneV4_ProbNNk"};
   TTreeReaderValue<Double_t> OmegaK_MC12TuneV4_ProbNNp = {fReader, "OmegaK_MC12TuneV4_ProbNNp"};
   TTreeReaderValue<Double_t> OmegaK_MC12TuneV4_ProbNNghost = {fReader, "OmegaK_MC12TuneV4_ProbNNghost"};
   TTreeReaderValue<Double_t> OmegaK_MC15TuneV1_ProbNNe = {fReader, "OmegaK_MC15TuneV1_ProbNNe"};
   TTreeReaderValue<Double_t> OmegaK_MC15TuneV1_ProbNNmu = {fReader, "OmegaK_MC15TuneV1_ProbNNmu"};
   TTreeReaderValue<Double_t> OmegaK_MC15TuneV1_ProbNNpi = {fReader, "OmegaK_MC15TuneV1_ProbNNpi"};
   TTreeReaderValue<Double_t> OmegaK_MC15TuneV1_ProbNNk = {fReader, "OmegaK_MC15TuneV1_ProbNNk"};
   TTreeReaderValue<Double_t> OmegaK_MC15TuneV1_ProbNNp = {fReader, "OmegaK_MC15TuneV1_ProbNNp"};
   TTreeReaderValue<Double_t> OmegaK_MC15TuneV1_ProbNNghost = {fReader, "OmegaK_MC15TuneV1_ProbNNghost"};
   TTreeReaderValue<Double_t> OmegaK_OWNPV_X = {fReader, "OmegaK_OWNPV_X"};
   TTreeReaderValue<Double_t> OmegaK_OWNPV_Y = {fReader, "OmegaK_OWNPV_Y"};
   TTreeReaderValue<Double_t> OmegaK_OWNPV_Z = {fReader, "OmegaK_OWNPV_Z"};
   TTreeReaderValue<Double_t> OmegaK_OWNPV_XERR = {fReader, "OmegaK_OWNPV_XERR"};
   TTreeReaderValue<Double_t> OmegaK_OWNPV_YERR = {fReader, "OmegaK_OWNPV_YERR"};
   TTreeReaderValue<Double_t> OmegaK_OWNPV_ZERR = {fReader, "OmegaK_OWNPV_ZERR"};
   TTreeReaderValue<Double_t> OmegaK_OWNPV_CHI2 = {fReader, "OmegaK_OWNPV_CHI2"};
   TTreeReaderValue<Int_t> OmegaK_OWNPV_NDOF = {fReader, "OmegaK_OWNPV_NDOF"};
   TTreeReaderValue<Double_t> OmegaK_IP_OWNPV = {fReader, "OmegaK_IP_OWNPV"};
   TTreeReaderValue<Double_t> OmegaK_IPCHI2_OWNPV = {fReader, "OmegaK_IPCHI2_OWNPV"};
   TTreeReaderValue<Double_t> OmegaK_ORIVX_X = {fReader, "OmegaK_ORIVX_X"};
   TTreeReaderValue<Double_t> OmegaK_ORIVX_Y = {fReader, "OmegaK_ORIVX_Y"};
   TTreeReaderValue<Double_t> OmegaK_ORIVX_Z = {fReader, "OmegaK_ORIVX_Z"};
   TTreeReaderValue<Double_t> OmegaK_ORIVX_XERR = {fReader, "OmegaK_ORIVX_XERR"};
   TTreeReaderValue<Double_t> OmegaK_ORIVX_YERR = {fReader, "OmegaK_ORIVX_YERR"};
   TTreeReaderValue<Double_t> OmegaK_ORIVX_ZERR = {fReader, "OmegaK_ORIVX_ZERR"};
   TTreeReaderValue<Double_t> OmegaK_ORIVX_CHI2 = {fReader, "OmegaK_ORIVX_CHI2"};
   TTreeReaderValue<Int_t> OmegaK_ORIVX_NDOF = {fReader, "OmegaK_ORIVX_NDOF"};
   TTreeReaderValue<Double_t> OmegaK_P = {fReader, "OmegaK_P"};
   TTreeReaderValue<Double_t> OmegaK_PT = {fReader, "OmegaK_PT"};
   TTreeReaderValue<Double_t> OmegaK_PE = {fReader, "OmegaK_PE"};
   TTreeReaderValue<Double_t> OmegaK_PX = {fReader, "OmegaK_PX"};
   TTreeReaderValue<Double_t> OmegaK_PY = {fReader, "OmegaK_PY"};
   TTreeReaderValue<Double_t> OmegaK_PZ = {fReader, "OmegaK_PZ"};
   TTreeReaderValue<Double_t> OmegaK_M = {fReader, "OmegaK_M"};
   TTreeReaderValue<Int_t> OmegaK_ID = {fReader, "OmegaK_ID"};
   TTreeReaderValue<Double_t> OmegaK_PIDe = {fReader, "OmegaK_PIDe"};
   TTreeReaderValue<Double_t> OmegaK_PIDmu = {fReader, "OmegaK_PIDmu"};
   TTreeReaderValue<Double_t> OmegaK_PIDK = {fReader, "OmegaK_PIDK"};
   TTreeReaderValue<Double_t> OmegaK_PIDp = {fReader, "OmegaK_PIDp"};
   TTreeReaderValue<Double_t> OmegaK_PIDd = {fReader, "OmegaK_PIDd"};
   TTreeReaderValue<Double_t> OmegaK_ProbNNe = {fReader, "OmegaK_ProbNNe"};
   TTreeReaderValue<Double_t> OmegaK_ProbNNk = {fReader, "OmegaK_ProbNNk"};
   TTreeReaderValue<Double_t> OmegaK_ProbNNp = {fReader, "OmegaK_ProbNNp"};
   TTreeReaderValue<Double_t> OmegaK_ProbNNpi = {fReader, "OmegaK_ProbNNpi"};
   TTreeReaderValue<Double_t> OmegaK_ProbNNmu = {fReader, "OmegaK_ProbNNmu"};
   TTreeReaderValue<Double_t> OmegaK_ProbNNd = {fReader, "OmegaK_ProbNNd"};
   TTreeReaderValue<Double_t> OmegaK_ProbNNghost = {fReader, "OmegaK_ProbNNghost"};
   TTreeReaderValue<Bool_t> OmegaK_hasMuon = {fReader, "OmegaK_hasMuon"};
   TTreeReaderValue<Bool_t> OmegaK_isMuon = {fReader, "OmegaK_isMuon"};
   TTreeReaderValue<Bool_t> OmegaK_hasRich = {fReader, "OmegaK_hasRich"};
   TTreeReaderValue<Bool_t> OmegaK_UsedRichAerogel = {fReader, "OmegaK_UsedRichAerogel"};
   TTreeReaderValue<Bool_t> OmegaK_UsedRich1Gas = {fReader, "OmegaK_UsedRich1Gas"};
   TTreeReaderValue<Bool_t> OmegaK_UsedRich2Gas = {fReader, "OmegaK_UsedRich2Gas"};
   TTreeReaderValue<Bool_t> OmegaK_RichAboveElThres = {fReader, "OmegaK_RichAboveElThres"};
   TTreeReaderValue<Bool_t> OmegaK_RichAboveMuThres = {fReader, "OmegaK_RichAboveMuThres"};
   TTreeReaderValue<Bool_t> OmegaK_RichAbovePiThres = {fReader, "OmegaK_RichAbovePiThres"};
   TTreeReaderValue<Bool_t> OmegaK_RichAboveKaThres = {fReader, "OmegaK_RichAboveKaThres"};
   TTreeReaderValue<Bool_t> OmegaK_RichAbovePrThres = {fReader, "OmegaK_RichAbovePrThres"};
   TTreeReaderValue<Bool_t> OmegaK_hasCalo = {fReader, "OmegaK_hasCalo"};
   TTreeReaderValue<Bool_t> OmegaK_L0Global_Dec = {fReader, "OmegaK_L0Global_Dec"};
   TTreeReaderValue<Bool_t> OmegaK_L0Global_TIS = {fReader, "OmegaK_L0Global_TIS"};
   TTreeReaderValue<Bool_t> OmegaK_L0Global_TOS = {fReader, "OmegaK_L0Global_TOS"};
   TTreeReaderValue<Bool_t> OmegaK_Hlt1Global_Dec = {fReader, "OmegaK_Hlt1Global_Dec"};
   TTreeReaderValue<Bool_t> OmegaK_Hlt1Global_TIS = {fReader, "OmegaK_Hlt1Global_TIS"};
   TTreeReaderValue<Bool_t> OmegaK_Hlt1Global_TOS = {fReader, "OmegaK_Hlt1Global_TOS"};
   TTreeReaderValue<Bool_t> OmegaK_Hlt1Phys_Dec = {fReader, "OmegaK_Hlt1Phys_Dec"};
   TTreeReaderValue<Bool_t> OmegaK_Hlt1Phys_TIS = {fReader, "OmegaK_Hlt1Phys_TIS"};
   TTreeReaderValue<Bool_t> OmegaK_Hlt1Phys_TOS = {fReader, "OmegaK_Hlt1Phys_TOS"};
   TTreeReaderValue<Int_t> OmegaK_TRACK_Type = {fReader, "OmegaK_TRACK_Type"};
   TTreeReaderValue<Int_t> OmegaK_TRACK_Key = {fReader, "OmegaK_TRACK_Key"};
   TTreeReaderValue<Double_t> OmegaK_TRACK_CHI2NDOF = {fReader, "OmegaK_TRACK_CHI2NDOF"};
   TTreeReaderValue<Double_t> OmegaK_TRACK_PCHI2 = {fReader, "OmegaK_TRACK_PCHI2"};
   TTreeReaderValue<Double_t> OmegaK_TRACK_MatchCHI2 = {fReader, "OmegaK_TRACK_MatchCHI2"};
   TTreeReaderValue<Double_t> OmegaK_TRACK_GhostProb = {fReader, "OmegaK_TRACK_GhostProb"};
   TTreeReaderValue<Double_t> OmegaK_TRACK_CloneDist = {fReader, "OmegaK_TRACK_CloneDist"};
   TTreeReaderValue<Double_t> OmegaK_TRACK_Likelihood = {fReader, "OmegaK_TRACK_Likelihood"};
   TTreeReaderValue<Double_t> OmegaK_X = {fReader, "OmegaK_X"};
   TTreeReaderValue<Double_t> OmegaK_Y = {fReader, "OmegaK_Y"};
   TTreeReaderValue<Double_t> PromptK_MC12TuneV2_ProbNNe = {fReader, "PromptK_MC12TuneV2_ProbNNe"};
   TTreeReaderValue<Double_t> PromptK_MC12TuneV2_ProbNNmu = {fReader, "PromptK_MC12TuneV2_ProbNNmu"};
   TTreeReaderValue<Double_t> PromptK_MC12TuneV2_ProbNNpi = {fReader, "PromptK_MC12TuneV2_ProbNNpi"};
   TTreeReaderValue<Double_t> PromptK_MC12TuneV2_ProbNNk = {fReader, "PromptK_MC12TuneV2_ProbNNk"};
   TTreeReaderValue<Double_t> PromptK_MC12TuneV2_ProbNNp = {fReader, "PromptK_MC12TuneV2_ProbNNp"};
   TTreeReaderValue<Double_t> PromptK_MC12TuneV2_ProbNNghost = {fReader, "PromptK_MC12TuneV2_ProbNNghost"};
   TTreeReaderValue<Double_t> PromptK_MC12TuneV3_ProbNNe = {fReader, "PromptK_MC12TuneV3_ProbNNe"};
   TTreeReaderValue<Double_t> PromptK_MC12TuneV3_ProbNNmu = {fReader, "PromptK_MC12TuneV3_ProbNNmu"};
   TTreeReaderValue<Double_t> PromptK_MC12TuneV3_ProbNNpi = {fReader, "PromptK_MC12TuneV3_ProbNNpi"};
   TTreeReaderValue<Double_t> PromptK_MC12TuneV3_ProbNNk = {fReader, "PromptK_MC12TuneV3_ProbNNk"};
   TTreeReaderValue<Double_t> PromptK_MC12TuneV3_ProbNNp = {fReader, "PromptK_MC12TuneV3_ProbNNp"};
   TTreeReaderValue<Double_t> PromptK_MC12TuneV3_ProbNNghost = {fReader, "PromptK_MC12TuneV3_ProbNNghost"};
   TTreeReaderValue<Double_t> PromptK_MC12TuneV4_ProbNNe = {fReader, "PromptK_MC12TuneV4_ProbNNe"};
   TTreeReaderValue<Double_t> PromptK_MC12TuneV4_ProbNNmu = {fReader, "PromptK_MC12TuneV4_ProbNNmu"};
   TTreeReaderValue<Double_t> PromptK_MC12TuneV4_ProbNNpi = {fReader, "PromptK_MC12TuneV4_ProbNNpi"};
   TTreeReaderValue<Double_t> PromptK_MC12TuneV4_ProbNNk = {fReader, "PromptK_MC12TuneV4_ProbNNk"};
   TTreeReaderValue<Double_t> PromptK_MC12TuneV4_ProbNNp = {fReader, "PromptK_MC12TuneV4_ProbNNp"};
   TTreeReaderValue<Double_t> PromptK_MC12TuneV4_ProbNNghost = {fReader, "PromptK_MC12TuneV4_ProbNNghost"};
   TTreeReaderValue<Double_t> PromptK_MC15TuneV1_ProbNNe = {fReader, "PromptK_MC15TuneV1_ProbNNe"};
   TTreeReaderValue<Double_t> PromptK_MC15TuneV1_ProbNNmu = {fReader, "PromptK_MC15TuneV1_ProbNNmu"};
   TTreeReaderValue<Double_t> PromptK_MC15TuneV1_ProbNNpi = {fReader, "PromptK_MC15TuneV1_ProbNNpi"};
   TTreeReaderValue<Double_t> PromptK_MC15TuneV1_ProbNNk = {fReader, "PromptK_MC15TuneV1_ProbNNk"};
   TTreeReaderValue<Double_t> PromptK_MC15TuneV1_ProbNNp = {fReader, "PromptK_MC15TuneV1_ProbNNp"};
   TTreeReaderValue<Double_t> PromptK_MC15TuneV1_ProbNNghost = {fReader, "PromptK_MC15TuneV1_ProbNNghost"};
   TTreeReaderValue<Double_t> PromptK_OWNPV_X = {fReader, "PromptK_OWNPV_X"};
   TTreeReaderValue<Double_t> PromptK_OWNPV_Y = {fReader, "PromptK_OWNPV_Y"};
   TTreeReaderValue<Double_t> PromptK_OWNPV_Z = {fReader, "PromptK_OWNPV_Z"};
   TTreeReaderValue<Double_t> PromptK_OWNPV_XERR = {fReader, "PromptK_OWNPV_XERR"};
   TTreeReaderValue<Double_t> PromptK_OWNPV_YERR = {fReader, "PromptK_OWNPV_YERR"};
   TTreeReaderValue<Double_t> PromptK_OWNPV_ZERR = {fReader, "PromptK_OWNPV_ZERR"};
   TTreeReaderValue<Double_t> PromptK_OWNPV_CHI2 = {fReader, "PromptK_OWNPV_CHI2"};
   TTreeReaderValue<Int_t> PromptK_OWNPV_NDOF = {fReader, "PromptK_OWNPV_NDOF"};
   TTreeReaderValue<Double_t> PromptK_IP_OWNPV = {fReader, "PromptK_IP_OWNPV"};
   TTreeReaderValue<Double_t> PromptK_IPCHI2_OWNPV = {fReader, "PromptK_IPCHI2_OWNPV"};
   TTreeReaderValue<Double_t> PromptK_ORIVX_X = {fReader, "PromptK_ORIVX_X"};
   TTreeReaderValue<Double_t> PromptK_ORIVX_Y = {fReader, "PromptK_ORIVX_Y"};
   TTreeReaderValue<Double_t> PromptK_ORIVX_Z = {fReader, "PromptK_ORIVX_Z"};
   TTreeReaderValue<Double_t> PromptK_ORIVX_XERR = {fReader, "PromptK_ORIVX_XERR"};
   TTreeReaderValue<Double_t> PromptK_ORIVX_YERR = {fReader, "PromptK_ORIVX_YERR"};
   TTreeReaderValue<Double_t> PromptK_ORIVX_ZERR = {fReader, "PromptK_ORIVX_ZERR"};
   TTreeReaderValue<Double_t> PromptK_ORIVX_CHI2 = {fReader, "PromptK_ORIVX_CHI2"};
   TTreeReaderValue<Int_t> PromptK_ORIVX_NDOF = {fReader, "PromptK_ORIVX_NDOF"};
   TTreeReaderValue<Double_t> PromptK_P = {fReader, "PromptK_P"};
   TTreeReaderValue<Double_t> PromptK_PT = {fReader, "PromptK_PT"};
   TTreeReaderValue<Double_t> PromptK_PE = {fReader, "PromptK_PE"};
   TTreeReaderValue<Double_t> PromptK_PX = {fReader, "PromptK_PX"};
   TTreeReaderValue<Double_t> PromptK_PY = {fReader, "PromptK_PY"};
   TTreeReaderValue<Double_t> PromptK_PZ = {fReader, "PromptK_PZ"};
   TTreeReaderValue<Double_t> PromptK_M = {fReader, "PromptK_M"};
   TTreeReaderValue<Int_t> PromptK_ID = {fReader, "PromptK_ID"};
   TTreeReaderValue<Double_t> PromptK_PIDe = {fReader, "PromptK_PIDe"};
   TTreeReaderValue<Double_t> PromptK_PIDmu = {fReader, "PromptK_PIDmu"};
   TTreeReaderValue<Double_t> PromptK_PIDK = {fReader, "PromptK_PIDK"};
   TTreeReaderValue<Double_t> PromptK_PIDp = {fReader, "PromptK_PIDp"};
   TTreeReaderValue<Double_t> PromptK_PIDd = {fReader, "PromptK_PIDd"};
   TTreeReaderValue<Double_t> PromptK_ProbNNe = {fReader, "PromptK_ProbNNe"};
   TTreeReaderValue<Double_t> PromptK_ProbNNk = {fReader, "PromptK_ProbNNk"};
   TTreeReaderValue<Double_t> PromptK_ProbNNp = {fReader, "PromptK_ProbNNp"};
   TTreeReaderValue<Double_t> PromptK_ProbNNpi = {fReader, "PromptK_ProbNNpi"};
   TTreeReaderValue<Double_t> PromptK_ProbNNmu = {fReader, "PromptK_ProbNNmu"};
   TTreeReaderValue<Double_t> PromptK_ProbNNd = {fReader, "PromptK_ProbNNd"};
   TTreeReaderValue<Double_t> PromptK_ProbNNghost = {fReader, "PromptK_ProbNNghost"};
   TTreeReaderValue<Bool_t> PromptK_hasMuon = {fReader, "PromptK_hasMuon"};
   TTreeReaderValue<Bool_t> PromptK_isMuon = {fReader, "PromptK_isMuon"};
   TTreeReaderValue<Bool_t> PromptK_hasRich = {fReader, "PromptK_hasRich"};
   TTreeReaderValue<Bool_t> PromptK_UsedRichAerogel = {fReader, "PromptK_UsedRichAerogel"};
   TTreeReaderValue<Bool_t> PromptK_UsedRich1Gas = {fReader, "PromptK_UsedRich1Gas"};
   TTreeReaderValue<Bool_t> PromptK_UsedRich2Gas = {fReader, "PromptK_UsedRich2Gas"};
   TTreeReaderValue<Bool_t> PromptK_RichAboveElThres = {fReader, "PromptK_RichAboveElThres"};
   TTreeReaderValue<Bool_t> PromptK_RichAboveMuThres = {fReader, "PromptK_RichAboveMuThres"};
   TTreeReaderValue<Bool_t> PromptK_RichAbovePiThres = {fReader, "PromptK_RichAbovePiThres"};
   TTreeReaderValue<Bool_t> PromptK_RichAboveKaThres = {fReader, "PromptK_RichAboveKaThres"};
   TTreeReaderValue<Bool_t> PromptK_RichAbovePrThres = {fReader, "PromptK_RichAbovePrThres"};
   TTreeReaderValue<Bool_t> PromptK_hasCalo = {fReader, "PromptK_hasCalo"};
   TTreeReaderValue<Bool_t> PromptK_L0Global_Dec = {fReader, "PromptK_L0Global_Dec"};
   TTreeReaderValue<Bool_t> PromptK_L0Global_TIS = {fReader, "PromptK_L0Global_TIS"};
   TTreeReaderValue<Bool_t> PromptK_L0Global_TOS = {fReader, "PromptK_L0Global_TOS"};
   TTreeReaderValue<Bool_t> PromptK_Hlt1Global_Dec = {fReader, "PromptK_Hlt1Global_Dec"};
   TTreeReaderValue<Bool_t> PromptK_Hlt1Global_TIS = {fReader, "PromptK_Hlt1Global_TIS"};
   TTreeReaderValue<Bool_t> PromptK_Hlt1Global_TOS = {fReader, "PromptK_Hlt1Global_TOS"};
   TTreeReaderValue<Bool_t> PromptK_Hlt1Phys_Dec = {fReader, "PromptK_Hlt1Phys_Dec"};
   TTreeReaderValue<Bool_t> PromptK_Hlt1Phys_TIS = {fReader, "PromptK_Hlt1Phys_TIS"};
   TTreeReaderValue<Bool_t> PromptK_Hlt1Phys_TOS = {fReader, "PromptK_Hlt1Phys_TOS"};
   TTreeReaderValue<Int_t> PromptK_TRACK_Type = {fReader, "PromptK_TRACK_Type"};
   TTreeReaderValue<Int_t> PromptK_TRACK_Key = {fReader, "PromptK_TRACK_Key"};
   TTreeReaderValue<Double_t> PromptK_TRACK_CHI2NDOF = {fReader, "PromptK_TRACK_CHI2NDOF"};
   TTreeReaderValue<Double_t> PromptK_TRACK_PCHI2 = {fReader, "PromptK_TRACK_PCHI2"};
   TTreeReaderValue<Double_t> PromptK_TRACK_MatchCHI2 = {fReader, "PromptK_TRACK_MatchCHI2"};
   TTreeReaderValue<Double_t> PromptK_TRACK_GhostProb = {fReader, "PromptK_TRACK_GhostProb"};
   TTreeReaderValue<Double_t> PromptK_TRACK_CloneDist = {fReader, "PromptK_TRACK_CloneDist"};
   TTreeReaderValue<Double_t> PromptK_TRACK_Likelihood = {fReader, "PromptK_TRACK_Likelihood"};
   TTreeReaderValue<Double_t> PromptK_X = {fReader, "PromptK_X"};
   TTreeReaderValue<Double_t> PromptK_Y = {fReader, "PromptK_Y"};
   TTreeReaderValue<UInt_t> nCandidate = {fReader, "nCandidate"};
   TTreeReaderValue<ULong64_t> totCandidates = {fReader, "totCandidates"};
   TTreeReaderValue<ULong64_t> EventInSequence = {fReader, "EventInSequence"};
   TTreeReaderValue<UInt_t> runNumber = {fReader, "runNumber"};
   TTreeReaderValue<ULong64_t> eventNumber = {fReader, "eventNumber"};
   TTreeReaderValue<UInt_t> BCID = {fReader, "BCID"};
   TTreeReaderValue<Int_t> BCType = {fReader, "BCType"};
   TTreeReaderValue<UInt_t> OdinTCK = {fReader, "OdinTCK"};
   TTreeReaderValue<UInt_t> L0DUTCK = {fReader, "L0DUTCK"};
   TTreeReaderValue<UInt_t> HLT1TCK = {fReader, "HLT1TCK"};
   TTreeReaderValue<UInt_t> HLT2TCK = {fReader, "HLT2TCK"};
   TTreeReaderValue<ULong64_t> GpsTime = {fReader, "GpsTime"};
   TTreeReaderValue<Short_t> Polarity = {fReader, "Polarity"};
   TTreeReaderValue<Int_t> nPV = {fReader, "nPV"};
   TTreeReaderArray<Float_t> PVX = {fReader, "PVX"};
   TTreeReaderArray<Float_t> PVY = {fReader, "PVY"};
   TTreeReaderArray<Float_t> PVZ = {fReader, "PVZ"};
   TTreeReaderArray<Float_t> PVXERR = {fReader, "PVXERR"};
   TTreeReaderArray<Float_t> PVYERR = {fReader, "PVYERR"};
   TTreeReaderArray<Float_t> PVZERR = {fReader, "PVZERR"};
   TTreeReaderArray<Float_t> PVCHI2 = {fReader, "PVCHI2"};
   TTreeReaderArray<Float_t> PVNDOF = {fReader, "PVNDOF"};
   TTreeReaderArray<Float_t> PVNTRACKS = {fReader, "PVNTRACKS"};
   TTreeReaderValue<Int_t> nPVs = {fReader, "nPVs"};
   TTreeReaderValue<Int_t> nTracks = {fReader, "nTracks"};
   TTreeReaderValue<Int_t> nLongTracks = {fReader, "nLongTracks"};
   TTreeReaderValue<Int_t> nDownstreamTracks = {fReader, "nDownstreamTracks"};
   TTreeReaderValue<Int_t> nUpstreamTracks = {fReader, "nUpstreamTracks"};
   TTreeReaderValue<Int_t> nVeloTracks = {fReader, "nVeloTracks"};
   TTreeReaderValue<Int_t> nTTracks = {fReader, "nTTracks"};
   TTreeReaderValue<Int_t> nBackTracks = {fReader, "nBackTracks"};
   TTreeReaderValue<Int_t> nRich1Hits = {fReader, "nRich1Hits"};
   TTreeReaderValue<Int_t> nRich2Hits = {fReader, "nRich2Hits"};
   TTreeReaderValue<Int_t> nVeloClusters = {fReader, "nVeloClusters"};
   TTreeReaderValue<Int_t> nITClusters = {fReader, "nITClusters"};
   TTreeReaderValue<Int_t> nTTClusters = {fReader, "nTTClusters"};
   TTreeReaderValue<Int_t> nOTClusters = {fReader, "nOTClusters"};
   TTreeReaderValue<Int_t> nSPDHits = {fReader, "nSPDHits"};
   TTreeReaderValue<Int_t> nMuonCoordsS0 = {fReader, "nMuonCoordsS0"};
   TTreeReaderValue<Int_t> nMuonCoordsS1 = {fReader, "nMuonCoordsS1"};
   TTreeReaderValue<Int_t> nMuonCoordsS2 = {fReader, "nMuonCoordsS2"};
   TTreeReaderValue<Int_t> nMuonCoordsS3 = {fReader, "nMuonCoordsS3"};
   TTreeReaderValue<Int_t> nMuonCoordsS4 = {fReader, "nMuonCoordsS4"};
   TTreeReaderValue<Int_t> nMuonTracks = {fReader, "nMuonTracks"};


   CrystalBall(TTree * /*tree*/ =0) { }
   virtual ~CrystalBall() { }
   virtual Int_t   Version() const { return 2; }
   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual void    Init(TTree *tree);
   virtual Bool_t  Notify();
   virtual Bool_t  Process(Long64_t entry);
   virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
   virtual void    SetOption(const char *option) { fOption = option; }
   virtual void    SetObject(TObject *obj) { fObject = obj; }
   virtual void    SetInputList(TList *input) { fInput = input; }
   virtual TList  *GetOutputList() const { return fOutput; }
   virtual void    SlaveTerminate();
   virtual void    Terminate();

   ClassDef(CrystalBall,0);

};

#endif

#ifdef CrystalBall_cxx
void CrystalBall::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the reader is initialized.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   fReader.SetTree(tree);
}

Bool_t CrystalBall::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}


#endif // #ifdef CrystalBall_cxx
