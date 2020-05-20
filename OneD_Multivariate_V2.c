#define OneD_Multivariate_V2_cxx

	//IMPORT LIBRARY//

#include "OneD_Multivariate_V2.h"

#include <TH1D.h>
#include <TH2D.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TFile.h>
#include <TF1.h>
#include "fit1MeV_Gaussian.C"

using namespace std;

#include <vector>
#include <algorithm>
#include <functional>
#include <chrono>
#include <thread>
#include <array>

	//DEFINING VARIABLES//

std::array<std::array<double, 50>, 50> fomK;		//Nested Array For Multivariate

TH2D * FigureK = nullptr;				//Figure of Merit for Kaon (Color Plot)
TH1D * HistogramKHalf = nullptr;			//Fitted Histogram when FOMKaon > 0.5
TH1D * HistogramKOne = nullptr;				//Fitted Histogram when FOMKaon > 1
TH1D * HistogramKThreeHalf = nullptr;			//Fitted Histogram when FOMKaon > 1.5

//TH1D * TwoDimensionHalf = nullptr;			//Not Needed
//TH1D * TwoDimensionOne = nullptr;			//Not Needed
//TH1D * TwoDimensionThreeHalf = nullptr;		//Not Needed

TH1D * FOMKaon = nullptr;				//Graph of Combined Figure of Merit 

TFile * File = nullptr;	
TCanvas * c1 = nullptr;

void OneD_Multivariate_V2::Begin(TTree * /*tree*/)
{

    TString option = GetOption();

}

void OneD_Multivariate_V2::SlaveBegin(TTree * /*tree*/)
{

    TString option = GetOption();
	
	//DEFINING HISTOGRAMS//

    HistogramKHalf = new TH1D("Figures of Merit", "Mass of Xic0 - FOM Kaon > 0.5", 100, 2370, 2570);
    HistogramKHalf->GetXaxis()->SetTitle("MeV");
    HistogramKHalf->GetYaxis()->SetTitle("Events Per 2 MeV");

    HistogramKOne = new TH1D("Figures of Merit", "Mass of Xic0 - FOM Kaon > 1.0", 100, 2370, 2570);
    HistogramKOne->GetXaxis()->SetTitle("MeV");
    HistogramKOne->GetYaxis()->SetTitle("Events Per 2 MeV");

    HistogramKThreeHalf = new TH1D("Figures of Merit", "Mass of Xic0 - FOM > 1.5", 100, 2370, 2570);
    HistogramKThreeHalf->GetXaxis()->SetTitle("MeV");
    HistogramKThreeHalf->GetXaxis()->SetTitle("Events Per 2 MeV");

//  TwoDimensionHalf = new TH1D("Figures of Merit", "Mass of Xic0 - FOM Kaon > 0.5", 100, 2370, 2570);
//  TwoDimensionHalf->GetXaxis()->SetTitle("MeV");
//  TwoDimensionHalf->GetYaxis()->SetTitle("Events Per 2 MeV");

//  TwoDimensionOne = new TH1D("Figures of Merit", "Mass of Xic0 - FOM Kaon > 1", 100, 2370, 2570);
//  TwoDimensionOne->GetXaxis()->SetTitle("MeV");
//  TwoDimensionOne->GetYaxis()->SetTitle("Events Per 2 MeV");

//  TwoDimensionThreeHalf = new TH1D("Figures of Merit", "Mass of Xic0 - FOM > 1.5", 100, 2370, 2570);
//  TwoDimensionThreeHalf->GetXaxis()->SetTitle("MeV");
//  TwoDimensionThreeHalf->GetYaxis()->SetTitle("Events Per 2 Mev");

    FigureK = new TH2D("Figures of Merit", "Color PLot of Xic0 Mass - One Dimensional Projections", 50, 0.7, 4.2, 50, 0.25, 1.0);
    FigureK->GetXaxis()->SetTitle("Log(PromptK_IPCHI2_OWNPV)");
    FigureK->GetYaxis()->SetTitle("PromptK_MC15TuneV1_ProbNNk");
    FigureK->GetZaxis()->SetTitle("Signal*Signal / Background*Background");

    FOMKaon = new TH1D("Figures of Merit", "Frequency of Kaon S:B FOMs", 100, 0, 2);
    FOMKaon->GetXaxis()->SetTitle("FOM");
    FOMKaon->GetYaxis()->SetTitle("Events Per 0.2 S:B");

    File = new TFile("OneD_Multivariate_V2.root", "RECREATE");
    gFile = File;

    c1 = new TCanvas("Cavnas", "Test Canvas");

	//FOM CALCULATION//

    for (double i = 0; i < 50; i++){ 												//50 Boxes for the x-axis
        for (double j = 0; j < 50; j++){ 											//50 Boxes for the y-axis

            double x = 0.735 + (0.07 * i); 											//Formula for Find Midpoint of Each Box in the X
            double y = 0.2475 + (0.015 * j); 											//Formula for Midpoint of Each Box in the Y
            double SignalK = (199.86 + TMath::Exp(10.47 - (1.68 * x))) * (231.32 + TMath::Exp(-16.11 + (25.025 * y))); 		//OneD Probability Fomula for Signal Regions in IP_CHI and ProbNN
            double BackgroundK = (111.07 + TMath::Exp(10.537 - (28.43 * x))) * (581.09 + TMath::Exp(-9.727 + (17.81 * y))); 	//OneD Probability Formula for Background Regios in IP_CHI and ProbNN
            fomK[i][j] = (SignalK / BackgroundK);}} 										//New Figure of Merit Produced by Dividing Signal by Background Formulas

    

}

Bool_t OneD_Multivariate_V2::Process(Long64_t entry)
{
    GetEntry(entry);
    fReader.SetEntry(entry);
	
	//ADDITIONAL CUTS TO ENHANCE SIGNAL//

    double CorrectedOmegaMass = (*Omega_MM) - (*Lambda_MM) + 1115.683;

    bool BorderCut = (
          (TMath::Log10(*PromptK_IPCHI2_OWNPV) > 0.7)
        &&(TMath::Log10(*PromptK_IPCHI2_OWNPV) < 4.2)
        &&(*PromptK_MC15TuneV1_ProbNNk > 0.25)
    );

    bool GeneralCuts = (
        (*Lambda_MM > 1112 && *Lambda_MM < 1120)
        &&(*Xi_c0_PT > 1500)
    );
	
	
											//Right now we have a soup of events in the Multivariate Plot with no way of knowing which event belongs to each bin
											//These next lines allow us to find the FoM for each event and allow us to add the event back into the proper histogram

int p = floor(abs(TMath::Log10(*PromptK_IPCHI2_OWNPV) - 0.7)/(0.07));			//Allows us to get the value of variable IP_CHI to a specific bin
int q = floor(abs(*PromptK_MC15TuneV1_ProbNNk - 0.25)/(0.015));				//Allows us to get the value of variable ProbNN to a specific bin

double FOMK = fomK[p][q];								//So instead of the figure of merit iterating over midpoints, it now iterates over bin values

if (FOMK > 0.5 && GeneralCuts && BorderCut){						//If the bin passes these FoM values they will be added to a new histogram
    HistogramKHalf->Fill(*Xi_c0_MM);}	

if (FOMK > 1.0 && GeneralCuts && BorderCut){
    HistogramKOne->Fill(*Xi_c0_MM);}

if (FOMK > 1.5 && GeneralCuts && BorderCut){
    HistogramKThreeHalf->Fill(*Xi_c0_MM);}

    return kTRUE;

}

void OneD_Multivariate_V2::SlaveTerminate()
{
}
	
void OneD_Multivariate_V2::Terminate()
{

    for (double i = 0; i < 50; i++){
        for (double j = 0; j < 50; j++){

            double x = 0.735 + (0.07 *i);
            double y = 0.2575 + (0.015 * j);

            FOMKaon->Fill(fomK[i][j]);							//Fills Histogram with each value of the Figure of Merit
            FigureK->Fill(x, y, fomK[i][j]);}}						//Fills a Color plot with each combination of x and y, and the corresponding FoM on the z-axis


    TF1 *myXifit = new TF1("myXifit", "fit1MeV_Gaussian", 2370., 2570., 5);
    myXifit->SetParameter(0, 40);
    myXifit->SetParameter(1, 2470);
    myXifit->SetParameter(2, 16);
    myXifit->SetParLimits(2, 0., 20.);
    myXifit->SetParameter(3, 10.);
    myXifit->SetParameter(4, 0.);

//  TF1 *myXifit2 = new TF1("myXifit2", "fit1MeV_Gaussian", 2370., 2570., 5);
//  myXifit2->SetParameter(0, 2000);
//  myXifit2->SetParameter(1, 2470);
//  myXifit2->SetParameter(2, 16);
//  myXifit2->SetParLimits(2, 0., 20.);
//  myXifit2->SetParameter(3, 10.);
//  myXifit2->SetParameter(4, 0.);

    HistogramKHalf->Fit("myXifit");
    HistogramKHalf->SetMinimum(0);
    c1->Write("Kaon Half");

    HistogramKOne->Fit("myXifit");
    HistogramKOne->SetMinimum(0);
    c1->Write("Kaon One");

    HistogramKThreeHalf->Fit("myXifit");
    HistogramKThreeHalf->SetMinimum(0);
    c1->Write("Kaon ThreeHalf");
    
//  TwoDimensionHalf->Fit("myXifit2");
//  TwoDimensionHalf->SetMinimum(0);
//  TwoDimensionHalf->Write("TwoDimension Half");

//  TwoDimensionOne->Write("myXifit2");
//  TwoDimensionOne->SetMinimum(0);
//  TwoDimensionOne->Write("TwoDimension One");

//  TwoDimensionThreeHalf->Write("myXifit2");
//  TwoDimensionThreeHalf->SetMinimum(0);
//  TwoDimensionThreeHalf->Write("TwoDimension ThreeHalf");

    FigureK->Draw("COLZ");
    c1->Write("Kaon Color Plot");

    FOMKaon->Draw();
    c1->Write("Kaon FOMs");

    File->Close();
        }
    
