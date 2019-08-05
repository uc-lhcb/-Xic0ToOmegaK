#define Multivariate_V2_cxx

#include <TH1D.h>
#include <TH2D.h>
#include <TCanvas.h>
#include <TFile.h>
#include "Multivariate_V2.h"
#include <TH2.h>
#include <TStyle.h>


#include "fit1MeV_Gaussian.C"

using namespace std;

#include <vector>
#include <algorithm>
#include <functional> 
#include <chrono>
#include <thread>
#include <array>

const int TRACK_LONG = 3;
const int TRACK_DOWN = 5;

std::array<std::array<TH1D*, 20>, 20> hists;
std::array<std::array<double, 20>, 20> fom;

TH2D * Figure = nullptr;
TFile * File = nullptr;
TCanvas * c1 = nullptr;

void Multivariate_V2::Begin(TTree * /*tree*/)
{
    TString option = GetOption();
}

void Multivariate_V2::SlaveBegin(TTree * /*tree*/)
{
   
   TString option = GetOption();
	for (double i = 0; i < 20; i++){
		for (double j = 0; j < 20; j++){
		
		hists[i][j] = new TH1D(TString::Format("hist_%f_%f", i, j), "Histograms", 100, 2370, 2570);
		hists[i][j]->GetXaxis()->SetTitle("Mass [MeV]");
		hists[i][j]->GetYaxis()->SetTitle("Events per 2 MeV");

}}

	Figure = new TH2D("Figures of Merit", "Multivariate Cut on Half Data", 20, 0., 20., 20, 0., 1.);
	Figure->GetXaxis()->SetTitle("PromptPi Chi2");
	Figure->GetYaxis()->SetTitle("PromptPi_ProbNNpi");
	Figure->GetZaxis()->SetTitle("Signal Events / Signal Error");

	File = new TFile("Multivariate.root", "RECREATE");
	gFile = File;

	c1 = new TCanvas("canvas", "Test Canvas");

}

Bool_t Multivariate_V2::Process(Long64_t entry)
{
     GetEntry(entry);
     fReader.SetLocalEntry(entry);

double CorrectedOmegaMass = ((*Omega_MM) - (*Lambda_MM) + 1115.683);

bool MassCuts = (
	(*Xi_c0_MM > 2300 && *Xi_c0_MM < 3100)
	&&(CorrectedOmegaMass > 1665 && CorrectedOmegaMass < 1680)
	&&(*Lambda_MM > 1112 && *Lambda_MM < 1120)
	);

bool PrecisionCuts = (
	(*Xi_c0_PT > 2000)

	&&(*LambdaPr_MC15TuneV1_ProbNNp > 0.1)
//	&&(*LambdaPr_TRACK_Type == TRACK_DOWN)
	
	&&(*LambdaPi_MC15TuneV1_ProbNNpi > 0.1)
//	&&(*LambdaPi_TRACK_Type == TRACK_DOWN)

//	&&(*PromptK_IPCHI2_OWNPV > 6)
//	&&(*PromptK_MC15TuneV1_ProbNNk > 0.55)
	);

double EvenNumber = (*eventNumber % 2 == 0);
double OddNumber = (*eventNumber % 2 == 1);



	for (double i = 0; i < 20; i++){
		for (double j = 0; j < 20; j++){
			
			if (((*PromptK_IPCHI2_OWNPV) >= i) && ((*PromptK_MC15TuneV1_ProbNNk) >= j/20) && MassCuts && PrecisionCuts){
				
				hists[i][j]->Fill(*Xi_c0_MM);}}
   
	return kTRUE;
}}

void Multivariate_V2::SlaveTerminate()
{

}

void Multivariate_V2::Terminate()
{
   TF1 *myXifit = new TF1("myXifit", fit1MeV_Gaussian, 2370, 2570, 5);
myXifit->SetParameter(0, 2600);
myXifit->SetParameter(1, 2471);
myXifit->SetParameter(2, 18);
myXifit->SetParLimits(2, 0., 20.);
myXifit->SetParameter(3, 1400);
myXifit->SetParameter(4, 0.);

	for (double i = 0; i < 20; i++){
		for (double j = 0; j < 20; j++){
		
		hists[i][j]->Fit("myXifit", "Q");
		fom[i][j] = (myXifit->GetParameter(0)/myXifit->GetParError(0));

	std::cout <<fom[i][j]<<" Signal:"<<myXifit->GetParameter(0)<<" Error:"<<myXifit->GetParError(0)<<" i="<<i<<" j="<<j<<" Fit Error:"<<myXifit->GetParError(1)<< endl;
		hists[i][j]->Write();

		Figure->Fill(i, j/20, fom[i][j]);

}}

Figure->Draw("COLZ");
c1->Write();
File->Close();

}
