//Taken part of the code from stavropo and updated it!
// In order to run it just type in the root framework 
// .x analyze_orca6_data.cc("data_events_49_7397_9579.root","atm_muon_events_49_7397_9579.root","neutrino_orca6_7397_9579.root","random_noise_events_49_7397_9579.root","test.root")
// .x analyze_orca6_data.cc("data_events_49_7397_9579.root","atm_muon_events_49_7397_9579.root","atm_nu_events_49_7397_9579.root","random_noise_events_49_7397_9579.root","test.root")


// C++
using namespace std;
#include <cmath>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <map>
#include <string>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <math.h>
#include <stdlib.h>
#include <iomanip>
#include <algorithm>
#include <set>
#include <functional>
#include <numeric>
#include <map>

/*void print(std::list<std::string> const &list)
{
    for (auto const &i: list) {
        std::cout << i << std::endl;
    }
} */


int analyze_orca6_data( string datafile , string atm_muon_file , string atm_nu_file , string rand_no_file ,string outname ){

//------------------ DATA ---------------------------- 
TFile* f_data = new TFile();
f_data= TFile::Open(Form("/home/mrboson/Downloads/km3net/MC_Analysis/Analyze_ORCA6/analysis/Analysis_Data/%s",datafile.c_str()));   

TTree* data_run_qual_params = (TTree*)f_data->Get("QualParams");
int run;
double livetime;
data_run_qual_params->SetBranchAddress("run",&run);
data_run_qual_params->SetBranchAddress("livetime",&livetime);
double total_data_livetime =0;
for( int i=0 ; i<data_run_qual_params->GetEntries() ; i++ ){
data_run_qual_params->GetEntry(i);
total_data_livetime += livetime;
}
cout << "Data livetime = " << total_data_livetime/(24*3600) << " days." << endl;
 /* 
TTree* data_events = (TTree*)f_data->Get("ProcEvts");

int event_id, frame_index, trigger_counter;
int no_hits, no_doms_hit, no_dus_hit, no_trig_hits, no_doms_trig_hit, no_dus_trig_hit, no_cher_hits, no_doms_cher_hit, no_dus_cher_hit, no_trig_cher_hits, no_doms_trig_cher_hit, no_dus_trig_cher_hit;
float cos_zen, max_lik, log_lik, reco_energy, reco_vrtx_x, reco_vrtx_y, reco_vrtx_z, reco_vrtx_r, Nhits, Qhits, beta0, TrkLength, d_closest, z_closest;
float mean_z_hits, mean_z_trig_hits, mean_z_cher_hits, mean_z_trig_cher_hits, trig_hits_over_all, cher_hits_over_all, trig_cher_hits_over_all, Qup_m_Qdn_JGandalf, max_tot_trig;
int Dn_m_Up_hits, Dn_m_Up_trig_hits, Dn_m_Up_cher_hits, Dn_m_Up_trig_cher_hits, early_trig_10;

data_events->SetBranchAddress("run",&run);
data_events->SetBranchAddress("event_id",&event_id);
data_events->SetBranchAddress("frame_index",&frame_index);
data_events->SetBranchAddress("trigger_counter",&trigger_counter);
data_events->SetBranchAddress("no_hits",&no_hits);
data_events->SetBranchAddress("no_doms_hit",&no_doms_hit);
data_events->SetBranchAddress("no_dus_hit",&no_dus_hit);
data_events->SetBranchAddress("no_trig_hits",&no_trig_hits);
data_events->SetBranchAddress("no_doms_trig_hit",&no_doms_trig_hit);
data_events->SetBranchAddress("no_dus_trig_hit",&no_dus_trig_hit);
data_events->SetBranchAddress("no_cher_hits",&no_cher_hits);
data_events->SetBranchAddress("no_doms_cher_hit",&no_doms_cher_hit);
data_events->SetBranchAddress("no_dus_cher_hit",&no_dus_cher_hit);
data_events->SetBranchAddress("no_trig_cher_hits",&no_trig_cher_hits);
data_events->SetBranchAddress("no_doms_trig_cher_hit",&no_doms_trig_cher_hit);
data_events->SetBranchAddress("no_dus_trig_cher_hit",&no_dus_trig_cher_hit);
data_events->SetBranchAddress("cos_zen",&cos_zen);
data_events->SetBranchAddress("max_lik",&max_lik);
data_events->SetBranchAddress("log_lik",&log_lik);
data_events->SetBranchAddress("reco_energy",&reco_energy);
data_events->SetBranchAddress("reco_vrtx_x",&reco_vrtx_x);
data_events->SetBranchAddress("reco_vrtx_y",&reco_vrtx_y);
data_events->SetBranchAddress("reco_vrtx_z",&reco_vrtx_z);
data_events->SetBranchAddress("reco_vrtx_r",&reco_vrtx_r);
data_events->SetBranchAddress("Nhits",&Nhits);
data_events->SetBranchAddress("Qhits",&Qhits);
data_events->SetBranchAddress("beta0",&beta0);
data_events->SetBranchAddress("TrkLength",&TrkLength);
data_events->SetBranchAddress("d_closest",&d_closest);
data_events->SetBranchAddress("z_closest",&z_closest);
data_events->SetBranchAddress("mean_z_hits",&mean_z_hits);
data_events->SetBranchAddress("mean_z_trig_hits",&mean_z_trig_hits);
data_events->SetBranchAddress("mean_z_cher_hits",&mean_z_cher_hits);
data_events->SetBranchAddress("mean_z_trig_cher_hits",&mean_z_trig_cher_hits);
data_events->SetBranchAddress("trig_hits_over_all",&trig_hits_over_all);
data_events->SetBranchAddress("cher_hits_over_all",&cher_hits_over_all);
data_events->SetBranchAddress("trig_cher_hits_over_all",&trig_cher_hits_over_all);
data_events->SetBranchAddress("Qup_m_Qdn_JGandalf",&Qup_m_Qdn_JGandalf);
data_events->SetBranchAddress("max_tot_trig",&max_tot_trig);
data_events->SetBranchAddress("early_trig_10",&early_trig_10);
data_events->SetBranchAddress("Dn_m_Up_hits",&Dn_m_Up_hits);
data_events->SetBranchAddress("Dn_m_Up_trig_hits",&Dn_m_Up_trig_hits);
data_events->SetBranchAddress("Dn_m_Up_cher_hits",&Dn_m_Up_cher_hits);
data_events->SetBranchAddress("Dn_m_Up_trig_cher_hits",&Dn_m_Up_trig_cher_hits);

TH1F* h_data_no_hits = new TH1F("h_data_no_hits",";# hits;counts;", 1001 , -0.5 , 1000.5 );
TH1F* h_data_no_hit_doms = new TH1F("h_data_no_hit_doms","hit DOMs", 108 , 0.5 , 108.5 );
TH1F* h_data_no_trig_hits = new TH1F("h_data_no_trig_hits",";# hits;counts;", 1001 , -0.5 , 1000.5 );
TH1F* h_data_no_trig_doms = new TH1F("h_data_no_trig_doms","triggered DOMs", 108 , 0.5 , 108.5 );
TH1F* h_data_no_cher_hits = new TH1F("h_data_no_cher_hits","Cherenkov hits", 1001 , -0.5 , 1000.5 );
TH1F* h_data_no_cher_doms = new TH1F("h_data_no_cher_doms","Cherenkov doms", 108 , 0.5 , 108.5 );
TH1F* h_data_no_trig_cher_doms = new TH1F("h_data_no_trig_cher_doms","Trig & Cherenkov doms", 72 , 0.5 , 72.5 );
TH1F* h_data_no_trig_dus = new TH1F("h_data_no_trig_dus"," DUs", 6 , 0.5 , 6.5 );
TH1F* h_data_no_cher_dus = new TH1F("h_data_no_cher_dus"," DUs", 6 , 0.5 , 6.5 );
TH1F* h_data_no_trig_cher_dus = new TH1F("h_data_no_trig_cher_dus"," DUs", 6 , 0.5 , 6.5 );
TH1F* h_data_no_trig_cher_hits = new TH1F("h_data_no_trig_cher_hits","Trig & Cherenkov hits", 1001 , -0.5 , 1000.5 );
TH1F* h_data_cos_zenith = new TH1F("h_data_cos_zen",";cos(reco zenith)", 100 , -1.0 , 1.0 );
TH1F* h_data_max_lik_dist = new TH1F("h_data_max_lik",";L;", 100 , 0 , 2000 );
TH1F* h_data_log_lik_dist = new TH1F("h_data_log_lik",";log(L);", 100 , -1.0 , 4.0 );
TH1F* h_data_reco_energy = new TH1F("h_data_reco_energy",";log[E_reco/GeV];", 40 , 0 , 4.0 );
TH2F* h_data_reco_vertex_pos = new TH2F("h_data_reco_vertex_pos",";radial position [m];vertical position [m]", 100, 0 , 100 , 160 , -40 , 280 );
TH1F* h_data_reco_vrtx_r = new TH1F("h_data_reco_vrtx_r","reco vrtx radial pos.;r [m];", 40 , 0 , 200 );
TH1F* h_data_reco_vrtx_x = new TH1F("h_data_reco_vrtx_x","reco vrtx x pos.;x [m];", 40 , 0 , 200 );
TH1F* h_data_reco_vrtx_y = new TH1F("h_data_reco_vrtx_y","reco vrtx y pos.;y [m];", 40 , 0 , 200 );
TH1F* h_data_reco_vrtx_z = new TH1F("h_data_reco_vrtx_z","reco vrtx z pos.;z [m];", 40 , 0 , 200 );
TH1F* h_data_Nhits = new TH1F("h_data_Nhits",";NHits;", 300 , 0.5 , 300.5 );
TH1F* h_data_beta0 = new TH1F("h_data_beta0",";beta0;",100,0,1);
TH1F* h_data_Qhits = new TH1F("h_data_Qhits",";L/Nhits;",120,0,6);
TH1F* h_data_trklength = new TH1F("h_data_trklength","", 150 , 0 , 300);
TH1F* h_data_d_closest = new TH1F("h_data_d_closest",";d_closest [m];", 15 , 0 , 150 );
TH1F* h_data_z_closest = new TH1F("h_data_z_closest",";z_closest [m];", 50 , -100 , 400 );
TH1F* h_data_mean_z_hits = new TH1F("h_data_mean_z_hits",";vertical position [m];", 160 , -40 , 280 );
TH1F* h_data_mean_z_trig_hits = new TH1F("h_data_mean_z_trig_hits",";vertical position [m];", 160 , -40 , 280 );
TH1F* h_data_mean_z_cher_hits = new TH1F("h_data_mean_z_cher_hits",";vertical position [m];", 160 , -40 , 280 );
TH1F* h_data_mean_z_trig_cher_hits = new TH1F("h_data_mean_z_trig_cher_hits",";vertical position [m];", 160 , -40 , 280 );
TH1F* h_data_ratio_hits_trig_over_all = new TH1F("h_data_ratio_hits_trig_over_all","trig_hits/all_hits", 100 , 0.0 , 1.0 );
TH1F* h_data_ratio_hits_cher_over_all = new TH1F("h_data_ratio_hits_cher_over_all","cher_hits/all_hits", 100 , 0.0 , 1.0 );
TH1F* h_data_ratio_hits_trig_cher_over_all = new TH1F("h_data_ratio_hits_trig_cher_over_all","cher_hits/all_hits", 100 , 0.0 , 1.0 );
TH1F* h_data_Qup_m_Qdn_JGandalf = new TH1F("h_data_Qup_m_Qdn_JGandalf","Qup_m_Qdn_JGandalf;Qup-Qdn;", 250 , 0 , 250 );
TH1F* h_data_max_trig_tot = new TH1F("h_data_max_trig_tot",";tot [ns];", 100 , 0 , 500 );
TH1F* h_data_early_trig_10 = new TH1F("h_data_early_trig_10","", 201 , -0.5 , 200.5 );
TH1F* h_data_Dn_m_Up_hits = new TH1F("h_data_Dn_m_Up_hits","Lower_hits_minus_Upper_hits" , 1500 , -500 , 1000);
TH1F* h_data_Dn_m_Up_trig_hits = new TH1F("h_data_Dn_m_Up_trig_hits","Lower_hits_minus_Upper_hits_trig" , 1500 , -500 , 1000);
TH1F* h_data_Dn_m_Up_cher_hits = new TH1F("h_data_Dn_m_Up_cher_hits","Lower_hits_minus_Upper_hits_cher" , 1500 , -500 , 1000);
TH1F* h_data_Dn_m_Up_trig_cher_hits = new TH1F("h_data_Dn_m_Up_trig_cher_hits","Lower_hits_minus_Upper_hits_trig_cher" , 1500 , -500 , 1000);


for( int i=0 ; i<data_events->GetEntries() ; i++ ){


data_events->GetEntry(i); // get i-th event parameters

//if( (cos_zen<0) && (max_tot_trig<220) && (early_trig_10<5) && (no_doms_cher_hit>5) && (cher_hits_over_all>0.28) && (Dn_m_Up_trig_cher_hits>0) && (Dn_m_Up_cher_hits>5) && (mean_z_cher_hits>55) && (log_lik>1.7) && (Qhits>2.0) && (Nhits>20) && (Qup_m_Qdn_JGandalf>10) && (max_lik/TrkLength>1.5) && (reco_vrtx_r<45.0) && (reco_vrtx_y>-38.0) && (reco_vrtx_y<38.0) && (z_closest<185) ){
if((no_doms_cher_hit>5)&&(log_lik>1.7) ){
// if ((Nhits>20)) {
h_data_no_hits->Fill(no_hits);
h_data_no_trig_hits->Fill(no_trig_hits);
h_data_no_cher_hits->Fill(no_cher_hits);
h_data_no_trig_cher_hits->Fill(no_trig_cher_hits); 
h_data_no_hit_doms->Fill(no_doms_hit); 
h_data_no_trig_doms->Fill(no_doms_trig_hit); 
h_data_no_cher_doms->Fill(no_doms_cher_hit);
h_data_no_trig_cher_doms->Fill(no_doms_trig_cher_hit);
h_data_no_trig_dus->Fill(no_dus_trig_hit);
h_data_no_cher_dus->Fill(no_dus_cher_hit);
h_data_no_trig_cher_dus->Fill(no_dus_trig_cher_hit);
h_data_cos_zenith->Fill(cos_zen);
h_data_max_lik_dist->Fill(max_lik);
h_data_log_lik_dist->Fill(log_lik);
h_data_reco_energy->Fill(reco_energy);
h_data_reco_vertex_pos->Fill(reco_vrtx_r,reco_vrtx_z);
h_data_reco_vrtx_r->Fill(reco_vrtx_r);
h_data_reco_vrtx_x->Fill(reco_vrtx_x);
h_data_reco_vrtx_y->Fill(reco_vrtx_y);
h_data_reco_vrtx_z->Fill(reco_vrtx_z);
h_data_Nhits->Fill(Nhits);
h_data_beta0->Fill(beta0);
h_data_Qhits->Fill(Qhits);
h_data_trklength->Fill(TrkLength);
h_data_d_closest->Fill(d_closest);
h_data_z_closest->Fill(z_closest);
h_data_mean_z_hits->Fill(mean_z_hits);
h_data_mean_z_trig_hits->Fill(mean_z_trig_hits);
h_data_mean_z_cher_hits->Fill(mean_z_cher_hits);
h_data_mean_z_trig_cher_hits->Fill(mean_z_trig_cher_hits);
h_data_ratio_hits_trig_over_all->Fill(trig_hits_over_all);
h_data_ratio_hits_cher_over_all->Fill(cher_hits_over_all);
h_data_ratio_hits_trig_cher_over_all->Fill(trig_cher_hits_over_all);
h_data_Qup_m_Qdn_JGandalf->Fill(Qup_m_Qdn_JGandalf);
h_data_max_trig_tot->Fill(max_tot_trig);
h_data_early_trig_10->Fill(early_trig_10);
h_data_Dn_m_Up_hits->Fill(Dn_m_Up_hits);
h_data_Dn_m_Up_trig_hits->Fill(Dn_m_Up_trig_hits);
h_data_Dn_m_Up_cher_hits->Fill(Dn_m_Up_cher_hits);
h_data_Dn_m_Up_trig_cher_hits->Fill(Dn_m_Up_trig_cher_hits);

}

if(i%1000000==0) cout << "Data Ev. = " << i << endl;

//<1= 

}


//----------------------- MC ATMOSPHERIC MUONS --------------------------------
TFile* f_mc_atm_muon = new TFile();
f_mc_atm_muon= TFile::Open(Form("/home/mrboson/Downloads/km3net/MC_Analysis/Analyze_ORCA6/analysis/Analysis_Data/%s",atm_muon_file.c_str()));   


TTree* atm_muon_run_qual_params = (TTree*)f_mc_atm_muon->Get("QualParams");
run=0;
livetime=0;
atm_muon_run_qual_params->SetBranchAddress("run",&run);
atm_muon_run_qual_params->SetBranchAddress("livetime",&livetime);
double total_mc_atm_muon_livetime=0;
for( int i=0 ; i<atm_muon_run_qual_params->GetEntries() ; i++ ){
atm_muon_run_qual_params->GetEntry(i);
total_mc_atm_muon_livetime += livetime;
}
cout << "Atm muon (MUPAGE) livetime = " << total_mc_atm_muon_livetime/(24*3600) << " days." << endl;

TTree* mc_atm_muon_events = (TTree*)f_mc_atm_muon->Get("ProcEvts");


float zenith, true_zenith, true_cos_zen, true_energy;
float reco_level;//new variable in order to quantify the difference between true and reco zenith 
int index;
event_id = frame_index = trigger_counter = 0 ;
no_hits = no_doms_hit = no_dus_hit = no_trig_hits = no_doms_trig_hit = no_dus_trig_hit = no_cher_hits = no_doms_cher_hit = no_dus_cher_hit = no_trig_cher_hits = no_doms_trig_cher_hit = no_dus_trig_cher_hit = 0 ;
cos_zen = max_lik = log_lik = reco_energy = reco_vrtx_x = reco_vrtx_y = reco_vrtx_z = reco_vrtx_r = Nhits = Qhits = beta0 = TrkLength = d_closest = z_closest = 0 ;
mean_z_hits = mean_z_trig_hits = mean_z_cher_hits = mean_z_trig_cher_hits = trig_hits_over_all = cher_hits_over_all = trig_cher_hits_over_all = Qup_m_Qdn_JGandalf = max_tot_trig = 0 ;
Dn_m_Up_hits = Dn_m_Up_trig_hits = Dn_m_Up_cher_hits = Dn_m_Up_trig_cher_hits = early_trig_10 = 0 ;

//----------------- All MC muon Data ---------------------------------------------
mc_atm_muon_events->SetBranchAddress("reconstruction level",&reco_level);
mc_atm_muon_events->SetBranchAddress("run",&run);
mc_atm_muon_events->SetBranchAddress("index",&index);
mc_atm_muon_events->SetBranchAddress("event_id",&event_id);
mc_atm_muon_events->SetBranchAddress("frame_index",&frame_index);
mc_atm_muon_events->SetBranchAddress("trigger_counter",&trigger_counter);
mc_atm_muon_events->SetBranchAddress("no_hits",&no_hits);
mc_atm_muon_events->SetBranchAddress("no_doms_hit",&no_doms_hit);
mc_atm_muon_events->SetBranchAddress("no_dus_hit",&no_dus_hit);
mc_atm_muon_events->SetBranchAddress("no_trig_hits",&no_trig_hits);
mc_atm_muon_events->SetBranchAddress("no_doms_trig_hit",&no_doms_trig_hit);
mc_atm_muon_events->SetBranchAddress("no_dus_trig_hit",&no_dus_trig_hit);
mc_atm_muon_events->SetBranchAddress("no_cher_hits",&no_cher_hits);
mc_atm_muon_events->SetBranchAddress("no_doms_cher_hit",&no_doms_cher_hit);
mc_atm_muon_events->SetBranchAddress("no_dus_cher_hit",&no_dus_cher_hit);
mc_atm_muon_events->SetBranchAddress("no_trig_cher_hits",&no_trig_cher_hits);
mc_atm_muon_events->SetBranchAddress("no_doms_trig_cher_hit",&no_doms_trig_cher_hit);
mc_atm_muon_events->SetBranchAddress("no_dus_trig_cher_hit",&no_dus_trig_cher_hit);
mc_atm_muon_events->SetBranchAddress("zenith",&zenith);
mc_atm_muon_events->SetBranchAddress("true_zenith",&true_zenith);
mc_atm_muon_events->SetBranchAddress("cos_zen",&cos_zen);
mc_atm_muon_events->SetBranchAddress("true_cos_zen",&true_cos_zen);
mc_atm_muon_events->SetBranchAddress("max_lik",&max_lik);
mc_atm_muon_events->SetBranchAddress("log_lik",&log_lik);
mc_atm_muon_events->SetBranchAddress("true_energy",&true_energy);
mc_atm_muon_events->SetBranchAddress("reco_energy",&reco_energy);
mc_atm_muon_events->SetBranchAddress("reco_vrtx_x",&reco_vrtx_x);
mc_atm_muon_events->SetBranchAddress("reco_vrtx_y",&reco_vrtx_y);
mc_atm_muon_events->SetBranchAddress("reco_vrtx_z",&reco_vrtx_z);
mc_atm_muon_events->SetBranchAddress("reco_vrtx_r",&reco_vrtx_r);
mc_atm_muon_events->SetBranchAddress("Nhits",&Nhits);
mc_atm_muon_events->SetBranchAddress("Qhits",&Qhits);
mc_atm_muon_events->SetBranchAddress("beta0",&beta0);
mc_atm_muon_events->SetBranchAddress("TrkLength",&TrkLength);
mc_atm_muon_events->SetBranchAddress("d_closest",&d_closest);
mc_atm_muon_events->SetBranchAddress("z_closest",&z_closest);
mc_atm_muon_events->SetBranchAddress("mean_z_hits",&mean_z_hits);
mc_atm_muon_events->SetBranchAddress("mean_z_trig_hits",&mean_z_trig_hits);
mc_atm_muon_events->SetBranchAddress("mean_z_cher_hits",&mean_z_cher_hits);
mc_atm_muon_events->SetBranchAddress("mean_z_trig_cher_hits",&mean_z_trig_cher_hits);
mc_atm_muon_events->SetBranchAddress("trig_hits_over_all",&trig_hits_over_all);
mc_atm_muon_events->SetBranchAddress("cher_hits_over_all",&cher_hits_over_all);
mc_atm_muon_events->SetBranchAddress("trig_cher_hits_over_all",&trig_cher_hits_over_all);
mc_atm_muon_events->SetBranchAddress("Qup_m_Qdn_JGandalf",&Qup_m_Qdn_JGandalf);
mc_atm_muon_events->SetBranchAddress("max_tot_trig",&max_tot_trig);
mc_atm_muon_events->SetBranchAddress("early_trig_10",&early_trig_10);
mc_atm_muon_events->SetBranchAddress("Dn_m_Up_hits",&Dn_m_Up_hits);
mc_atm_muon_events->SetBranchAddress("Dn_m_Up_trig_hits",&Dn_m_Up_trig_hits);
mc_atm_muon_events->SetBranchAddress("Dn_m_Up_cher_hits",&Dn_m_Up_cher_hits);
mc_atm_muon_events->SetBranchAddress("Dn_m_Up_trig_cher_hits",&Dn_m_Up_trig_cher_hits);

TH1F* h_mc_atm_muon_reco_levels = new TH1F("h_mc_atm_muon_reco_levels",";# degrees;", 100 ,0 , 100 );
TH1F* h_mc_atm_muon_no_hits = new TH1F("h_mc_atm_muon_no_hits",";# hits;counts;", 1001 , -0.5 , 1000.5 );
TH1F* h_mc_atm_muon_no_hit_doms = new TH1F("h_mc_atm_muon_no_hit_doms","hit DOMs", 108 , 0.5 , 108.5 );
TH1F* h_mc_atm_muon_no_trig_hits = new TH1F("h_mc_atm_muon_no_trig_hits",";# hits;counts;", 1001 , -0.5 , 1000.5 );
TH1F* h_mc_atm_muon_no_trig_doms = new TH1F("h_mc_atm_muon_no_trig_doms","triggered DOMs", 108 , 0.5 , 108.5 );
TH1F* h_mc_atm_muon_no_cher_hits = new TH1F("h_mc_atm_muon_no_cher_hits","Cherenkov hits", 1001 , -0.5 , 1000.5 );
TH1F* h_mc_atm_muon_no_cher_doms = new TH1F("h_mc_atm_muon_no_cher_doms","Cherenkov doms", 108 , 0.5 , 108.5 );
TH1F* h_mc_atm_muon_no_trig_cher_doms = new TH1F("h_mc_atm_muon_no_trig_cher_doms","Trig & Cherenkov doms", 72 , 0.5 , 72.5 );
TH1F* h_mc_atm_muon_no_trig_dus = new TH1F("h_mc_atm_muon_no_trig_dus"," DUs", 6 , 0.5 , 6.5 );
TH1F* h_mc_atm_muon_no_cher_dus = new TH1F("h_mc_atm_muon_no_cher_dus"," DUs", 6 , 0.5 , 6.5 );
TH1F* h_mc_atm_muon_no_trig_cher_dus = new TH1F("h_mc_atm_muon_no_trig_cher_dus"," DUs", 6 , 0.5 , 6.5 );
TH1F* h_mc_atm_muon_no_trig_cher_hits = new TH1F("h_mc_atm_muon_no_trig_cher_hits","Trig & Cherenkov hits", 1001 , -0.5 , 1000.5 );
TH1F* h_mc_atm_muon_zenith = new TH1F("h_mc_atm_muon_zenith",";reco zenith [deg]", 180 , 0.0 , 180.0 );
TH1F* h_mc_atm_muon_true_zenith = new TH1F("h_mc_atm_muon_true_zenith",";true zenith [deg]", 180 , 0.0 , 180.0 );
TH1F* h_mc_atm_muon_cos_zenith = new TH1F("h_mc_atm_muon_cos_zen",";cos(reco zenith)", 100 , -1.0 , 1.0 );
TH1F* h_mc_atm_muon_true_cos_zen = new TH1F("h_mc_atm_muon_true_cos_zen",";cos(reco zenith)", 100 , -1.0 , 1.0 );
TH1F* h_mc_atm_muon_max_lik_dist = new TH1F("h_mc_atm_muon_max_lik",";L;", 100 , 0 , 2000 );
TH1F* h_mc_atm_muon_log_lik_dist = new TH1F("h_mc_atm_muon_log_lik",";log(L);", 100 , -1.0 , 4.0 );
TH1F* h_mc_atm_muon_true_energy = new TH1F("h_mc_atm_muon_true_energy",";log[E_reco/GeV];", 40 , 0 , 4.0 );
TH1F* h_mc_atm_muon_reco_energy = new TH1F("h_mc_atm_muon_reco_energy",";log[E_reco/GeV];", 40 , 0 , 4.0 );
TH2F* h_mc_atm_muon_reco_vertex_pos = new TH2F("h_mc_atm_muon_reco_vertex_pos",";radial position [m];vertical position [m]", 100, 0 , 100 , 160 , -40 , 280 );
TH1F* h_mc_atm_muon_reco_vrtx_r = new TH1F("h_mc_atm_muon_reco_vrtx_r","reco vrtx radial pos.;r [m];", 40 , 0 , 200 );
TH1F* h_mc_atm_muon_reco_vrtx_x = new TH1F("h_mc_atm_muon_reco_vrtx_x","reco vrtx x pos.;x [m];", 40 , 0 , 200 );
TH1F* h_mc_atm_muon_reco_vrtx_y = new TH1F("h_mc_atm_muon_reco_vrtx_y","reco vrtx y pos.;y [m];", 40 , 0 , 200 );
TH1F* h_mc_atm_muon_reco_vrtx_z = new TH1F("h_mc_atm_muon_reco_vrtx_z","reco vrtx z pos.;z [m];", 40 , 0 , 200 );
TH1F* h_mc_atm_muon_Nhits = new TH1F("h_mc_atm_muon_Nhits",";NHits;", 300 , 0.5 , 300.5 );
TH1F* h_mc_atm_muon_beta0 = new TH1F("h_mc_atm_muon_beta0",";beta0;",100,0,1);
TH1F* h_mc_atm_muon_Qhits = new TH1F("h_mc_atm_muon_Qhits",";L/Nhits;",120,0,6);
TH1F* h_mc_atm_muon_trklength = new TH1F("h_mc_atm_muon_trklength","", 150 , 0 , 300);
TH1F* h_mc_atm_muon_d_closest = new TH1F("h_mc_atm_muon_d_closest",";d_closest [m];", 15 , 0 , 150 );
TH1F* h_mc_atm_muon_z_closest = new TH1F("h_mc_atm_muon_z_closest",";z_closest [m];", 50 , -100 , 400 );
TH1F* h_mc_atm_muon_mean_z_hits = new TH1F("h_mc_atm_muon_mean_z_hits",";vertical position [m];", 160 , -40 , 280 );
TH1F* h_mc_atm_muon_mean_z_trig_hits = new TH1F("h_mc_atm_muon_mean_z_trig_hits",";vertical position [m];", 160 , -40 , 280 );
TH1F* h_mc_atm_muon_mean_z_cher_hits = new TH1F("h_mc_atm_muon_mean_z_cher_hits",";vertical position [m];", 160 , -40 , 280 );
TH1F* h_mc_atm_muon_mean_z_trig_cher_hits = new TH1F("h_mc_atm_muon_mean_z_trig_cher_hits",";vertical position [m];", 160 , -40 , 280 );
TH1F* h_mc_atm_muon_ratio_hits_trig_over_all = new TH1F("h_mc_atm_muon_ratio_hits_trig_over_all","trig_hits/all_hits", 100 , 0.0 , 1.0 );
TH1F* h_mc_atm_muon_ratio_hits_cher_over_all = new TH1F("h_mc_atm_muon_ratio_hits_cher_over_all","cher_hits/all_hits", 100 , 0.0 , 1.0 );
TH1F* h_mc_atm_muon_ratio_hits_trig_cher_over_all = new TH1F("h_mc_atm_muon_ratio_hits_trig_cher_over_all","cher_hits/all_hits", 100 , 0.0 , 1.0 );
TH1F* h_mc_atm_muon_Qup_m_Qdn_JGandalf = new TH1F("h_mc_atm_muon_Qup_m_Qdn_JGandalf","Qup_m_Qdn_JGandalf;Qup-Qdn;", 250 , 0 , 250 );
TH1F* h_mc_atm_muon_max_trig_tot = new TH1F("h_mc_atm_muon_max_trig_tot",";tot [ns];", 100 , 0 , 500 );
TH1F* h_mc_atm_muon_early_trig_10 = new TH1F("h_mc_atm_muon_early_trig_10","", 201 , -0.5 , 200.5 );
TH1F* h_mc_atm_muon_Dn_m_Up_hits = new TH1F("h_mc_atm_muon_Dn_m_Up_hits","Lower_hits_minus_Upper_hits" , 1500 , -500 , 1000);
TH1F* h_mc_atm_muon_Dn_m_Up_trig_hits = new TH1F("h_mc_atm_muon_Dn_m_Up_trig_hits","Lower_hits_minus_Upper_hits_trig" , 1500 , -500 , 1000);
TH1F* h_mc_atm_muon_Dn_m_Up_cher_hits = new TH1F("h_mc_atm_muon_Dn_m_Up_cher_hits","Lower_hits_minus_Upper_hits_cher" , 1500 , -500 , 1000);
TH1F* h_mc_atm_muon_Dn_m_Up_trig_cher_hits = new TH1F("h_mc_atm_muon_Dn_m_Up_trig_cher_hits","Lower_hits_minus_Upper_hits_trig_cher" , 1500 , -500 , 1000);

for( int i=0 ; i<mc_atm_muon_events->GetEntries() ; i++ ){

mc_atm_muon_events->GetEntry(i); // get i-th event parameters
reco_level= abs(true_zenith-zenith); // see the error in the degrees of zenith 
//cout << "reco_level="<<reco_level<<endl;

//cuts
//if( (cos_zen<0) && (max_tot_trig<220) && (early_trig_10<5) && (no_doms_cher_hit>5) && (cher_hits_over_all>0.28) && (Dn_m_Up_trig_cher_hits>0) && (Dn_m_Up_cher_hits>5) && (mean_z_cher_hits>55) && (log_lik>1.7) && (Qhits>2.0) && (Nhits>20) && (Qup_m_Qdn_JGandalf>10) && (max_lik/TrkLength>1.5) && (reco_vrtx_r<45.0) && (reco_vrtx_y>-38.0) && (reco_vrtx_y<38.0) && (z_closest<185) ){
if((no_doms_cher_hit>5)&&(log_lik>1.7) ){
//if (Nhits>20){
 h_mc_atm_muon_no_hits->Fill(no_hits);
h_mc_atm_muon_no_trig_hits->Fill(no_trig_hits);
h_mc_atm_muon_no_cher_hits->Fill(no_cher_hits);
h_mc_atm_muon_no_trig_cher_hits->Fill(no_trig_cher_hits); 
h_mc_atm_muon_no_hit_doms->Fill(no_doms_hit); 
h_mc_atm_muon_no_trig_doms->Fill(no_doms_trig_hit); 
h_mc_atm_muon_no_cher_doms->Fill(no_doms_cher_hit);
h_mc_atm_muon_no_trig_cher_doms->Fill(no_doms_trig_cher_hit);
h_mc_atm_muon_no_trig_dus->Fill(no_dus_trig_hit);
h_mc_atm_muon_no_cher_dus->Fill(no_dus_cher_hit);
h_mc_atm_muon_no_trig_cher_dus->Fill(no_dus_trig_cher_hit);
h_mc_atm_muon_zenith->Fill(zenith);
h_mc_atm_muon_true_zenith->Fill(true_zenith);
h_mc_atm_muon_cos_zenith->Fill(cos_zen);
h_mc_atm_muon_true_cos_zen->Fill(true_cos_zen);
h_mc_atm_muon_max_lik_dist->Fill(max_lik);
h_mc_atm_muon_log_lik_dist->Fill(log_lik);
h_mc_atm_muon_true_energy->Fill(true_energy);
h_mc_atm_muon_reco_energy->Fill(reco_energy);
h_mc_atm_muon_reco_vertex_pos->Fill(reco_vrtx_r,reco_vrtx_z);
h_mc_atm_muon_reco_vrtx_r->Fill(reco_vrtx_r);
h_mc_atm_muon_reco_vrtx_x->Fill(reco_vrtx_x);
h_mc_atm_muon_reco_vrtx_y->Fill(reco_vrtx_y);
h_mc_atm_muon_reco_vrtx_z->Fill(reco_vrtx_z);
h_mc_atm_muon_Nhits->Fill(Nhits);
h_mc_atm_muon_beta0->Fill(beta0);
h_mc_atm_muon_Qhits->Fill(Qhits);
h_mc_atm_muon_trklength->Fill(TrkLength);
h_mc_atm_muon_d_closest->Fill(d_closest);
h_mc_atm_muon_z_closest->Fill(z_closest);
h_mc_atm_muon_mean_z_hits->Fill(mean_z_hits);
h_mc_atm_muon_mean_z_trig_hits->Fill(mean_z_trig_hits);
h_mc_atm_muon_mean_z_cher_hits->Fill(mean_z_cher_hits);
h_mc_atm_muon_mean_z_trig_cher_hits->Fill(mean_z_trig_cher_hits);
h_mc_atm_muon_ratio_hits_trig_over_all->Fill(trig_hits_over_all);
h_mc_atm_muon_ratio_hits_cher_over_all->Fill(cher_hits_over_all);
h_mc_atm_muon_ratio_hits_trig_cher_over_all->Fill(trig_cher_hits_over_all);
h_mc_atm_muon_Qup_m_Qdn_JGandalf->Fill(Qup_m_Qdn_JGandalf);
h_mc_atm_muon_max_trig_tot->Fill(max_tot_trig);
h_mc_atm_muon_early_trig_10->Fill(early_trig_10);
h_mc_atm_muon_Dn_m_Up_hits->Fill(Dn_m_Up_hits);
h_mc_atm_muon_Dn_m_Up_trig_hits->Fill(Dn_m_Up_trig_hits);
h_mc_atm_muon_Dn_m_Up_cher_hits->Fill(Dn_m_Up_cher_hits);
h_mc_atm_muon_Dn_m_Up_trig_cher_hits->Fill(Dn_m_Up_trig_cher_hits);



 }

if(i%1000000==0) cout << "Atm. muon Ev. = " << i << endl;

//<1= 


}

// scale mc atm. muon histograms to the data livetime//change again total_mc_atm_muon_livetime again in the end//
h_mc_atm_muon_reco_levels -> Scale(total_data_livetime/total_mc_atm_muon_livetime);
h_mc_atm_muon_no_hits->Scale(total_data_livetime/total_mc_atm_muon_livetime);
h_mc_atm_muon_no_trig_hits->Scale(total_data_livetime/total_mc_atm_muon_livetime);
h_mc_atm_muon_no_cher_hits->Scale(total_data_livetime/total_mc_atm_muon_livetime);
h_mc_atm_muon_no_trig_cher_hits->Scale(total_data_livetime/total_mc_atm_muon_livetime); 
h_mc_atm_muon_no_hit_doms->Scale(total_data_livetime/total_mc_atm_muon_livetime); 
h_mc_atm_muon_no_trig_doms->Scale(total_data_livetime/total_mc_atm_muon_livetime); 
h_mc_atm_muon_no_cher_doms->Scale(total_data_livetime/total_mc_atm_muon_livetime);
h_mc_atm_muon_no_trig_cher_doms->Scale(total_data_livetime/total_mc_atm_muon_livetime);
h_mc_atm_muon_no_trig_dus->Scale(total_data_livetime/total_mc_atm_muon_livetime);
h_mc_atm_muon_no_cher_dus->Scale(total_data_livetime/total_mc_atm_muon_livetime);
h_mc_atm_muon_no_trig_cher_dus->Scale(total_data_livetime/total_mc_atm_muon_livetime);
h_mc_atm_muon_zenith->Scale(total_data_livetime/total_mc_atm_muon_livetime);
h_mc_atm_muon_true_zenith->Scale(total_data_livetime/total_mc_atm_muon_livetime);
h_mc_atm_muon_cos_zenith->Scale(total_data_livetime/total_mc_atm_muon_livetime);
h_mc_atm_muon_true_cos_zen->Scale(total_data_livetime/total_mc_atm_muon_livetime);
h_mc_atm_muon_max_lik_dist->Scale(total_data_livetime/total_mc_atm_muon_livetime);
h_mc_atm_muon_log_lik_dist->Scale(total_data_livetime/total_mc_atm_muon_livetime);
h_mc_atm_muon_true_energy->Scale(total_data_livetime/total_mc_atm_muon_livetime);
h_mc_atm_muon_reco_energy->Scale(total_data_livetime/total_mc_atm_muon_livetime);
h_mc_atm_muon_reco_vertex_pos->Scale(total_data_livetime/total_mc_atm_muon_livetime);
h_mc_atm_muon_reco_vrtx_r->Scale(total_data_livetime/total_mc_atm_muon_livetime);
h_mc_atm_muon_reco_vrtx_x->Scale(total_data_livetime/total_mc_atm_muon_livetime);
h_mc_atm_muon_reco_vrtx_y->Scale(total_data_livetime/total_mc_atm_muon_livetime);
h_mc_atm_muon_reco_vrtx_z->Scale(total_data_livetime/total_mc_atm_muon_livetime);
h_mc_atm_muon_Nhits->Scale(total_data_livetime/total_mc_atm_muon_livetime);
h_mc_atm_muon_beta0->Scale(total_data_livetime/total_mc_atm_muon_livetime);
h_mc_atm_muon_Qhits->Scale(total_data_livetime/total_mc_atm_muon_livetime);
h_mc_atm_muon_trklength->Scale(total_data_livetime/total_mc_atm_muon_livetime);
h_mc_atm_muon_d_closest->Scale(total_data_livetime/total_mc_atm_muon_livetime);
h_mc_atm_muon_z_closest->Scale(total_data_livetime/total_mc_atm_muon_livetime);
h_mc_atm_muon_mean_z_hits->Scale(total_data_livetime/total_mc_atm_muon_livetime);
h_mc_atm_muon_mean_z_trig_hits->Scale(total_data_livetime/total_mc_atm_muon_livetime);
h_mc_atm_muon_mean_z_cher_hits->Scale(total_data_livetime/total_mc_atm_muon_livetime);
h_mc_atm_muon_mean_z_trig_cher_hits->Scale(total_data_livetime/total_mc_atm_muon_livetime);
h_mc_atm_muon_ratio_hits_trig_over_all->Scale(total_data_livetime/total_mc_atm_muon_livetime);
h_mc_atm_muon_ratio_hits_cher_over_all->Scale(total_data_livetime/total_mc_atm_muon_livetime);
h_mc_atm_muon_ratio_hits_trig_cher_over_all->Scale(total_data_livetime/total_mc_atm_muon_livetime);
h_mc_atm_muon_Qup_m_Qdn_JGandalf->Scale(total_data_livetime/total_mc_atm_muon_livetime);
h_mc_atm_muon_max_trig_tot->Scale(total_data_livetime/total_mc_atm_muon_livetime);
h_mc_atm_muon_early_trig_10->Scale(total_data_livetime/total_mc_atm_muon_livetime);
h_mc_atm_muon_Dn_m_Up_hits->Scale(total_data_livetime/total_mc_atm_muon_livetime);
h_mc_atm_muon_Dn_m_Up_trig_hits->Scale(total_data_livetime/total_mc_atm_muon_livetime);
h_mc_atm_muon_Dn_m_Up_cher_hits->Scale(total_data_livetime/total_mc_atm_muon_livetime);
h_mc_atm_muon_Dn_m_Up_trig_cher_hits->Scale(total_data_livetime/total_mc_atm_muon_livetime);
*/

//----------------------- MC ATMOSPHERIC NEUTRINOS --------------------------------
//gSystem -> AccessPathName(Form("/home/mrboson/Downloads/km3net/MC_Analysis/Analyze_ORCA6/analysis/Analysis_Data/%",atm_nu_file.c_str()));
//cout << atm_nu_file.c_str() << endl;
TFile* f_mc_atm_nu = new TFile();
f_mc_atm_nu= TFile::Open(Form("/home/mrboson/Downloads/km3net/MC_Analysis/Analyze_ORCA6/analysis/Analysis_Data/%s",atm_nu_file.c_str()));   
//Form("/home/mrboson/Downloads/km3net/MC_Analysis/Analyze_ORCA6/analysis/Analysis_Data/%i",atm_nu_file.c_str()));          //(atm_nu_file.c_str());
//f_mc_atm_nu = TFile::Open("root://ccxroot:1999/home/mrboson/Downloads/km3net/MC_Analysis/Analyze_ORCA6/analysis/Analysis Data/atm_nu_file.c_str()");


TTree* atm_nu_run_qual_params = (TTree*)f_mc_atm_nu->Get("QualParams");
run=0;

int no_runs=0;
atm_nu_run_qual_params->SetBranchAddress("run",&run);
double total_mc_atm_nu_livetime=0;
for( int i=0 ; i<atm_nu_run_qual_params->GetEntries() ; i++ ){
atm_nu_run_qual_params->GetEntry(i);
if(run%10!=0) no_runs++; 
}

TTree* mc_atm_nu_events = (TTree*)f_mc_atm_nu->Get("ProcEvts");

double w3_osci; //if I run only simulations for neutrinos
int flav , index ;
char interaction_type;
float zenith, true_zenith, true_cos_zen, true_energy;
int event_id, frame_index, trigger_counter;
int no_hits, no_doms_hit, no_dus_hit, no_trig_hits, no_doms_trig_hit, no_dus_trig_hit, no_cher_hits, no_doms_cher_hit, no_dus_cher_hit, no_trig_cher_hits, no_doms_trig_cher_hit, no_dus_trig_cher_hit;
float cos_zen, max_lik, log_lik, reco_energy, reco_vrtx_x, reco_vrtx_y, reco_vrtx_z, reco_vrtx_r, Nhits, Qhits, beta0, TrkLength, d_closest, z_closest;
float mean_z_hits, mean_z_trig_hits, mean_z_cher_hits, mean_z_trig_cher_hits, trig_hits_over_all, cher_hits_over_all, trig_cher_hits_over_all, Qup_m_Qdn_JGandalf, max_tot_trig;
int Dn_m_Up_hits, Dn_m_Up_trig_hits, Dn_m_Up_cher_hits, Dn_m_Up_trig_cher_hits, early_trig_10;
float diff_energy,  bjorken_y;
double true_phi, reco_phi;

/*double w3_osci; //In case, 
int flav;
char interaction_type;
float zenith, true_zenith, true_cos_zen, true_energy;
float reco_level;//new variable in order to quantify the difference between true and reco zenith 
int index;
//zenith, true_zenith, true_cos_zen, true_energy = 0 ;
//index = event_id = frame_index = trigger_counter = 0 ;
no_hits = no_doms_hit = no_dus_hit = no_trig_hits = no_doms_trig_hit = no_dus_trig_hit = no_cher_hits = no_doms_cher_hit = no_dus_cher_hit = no_trig_cher_hits = no_doms_trig_cher_hit = no_dus_trig_cher_hit = 0 ;
cos_zen = max_lik = log_lik = reco_energy = reco_vrtx_x = reco_vrtx_y = reco_vrtx_z = reco_vrtx_r = Nhits = Qhits = beta0 = TrkLength = d_closest = z_closest = 0 ;
mean_z_hits = mean_z_trig_hits = mean_z_cher_hits = mean_z_trig_cher_hits = trig_hits_over_all = cher_hits_over_all = trig_cher_hits_over_all = Qup_m_Qdn_JGandalf = max_tot_trig = 0 ;
Dn_m_Up_hits = Dn_m_Up_trig_hits = Dn_m_Up_cher_hits = Dn_m_Up_trig_cher_hits = early_trig_10 = 0 ; */

/*
// create output root file
//TFile* f_out = new TFile("dummy.root","RECREATE"); // output file that contains the TTree
string outfile_name;
if( (flavour==12 || flavour==-12) && (isCC==1) ){ outfile_name = Form("/sps/km3net/users/stavropo/ORCA6/preproc/mc/atm_neutrinos/output_e/%s",outfile.c_str()); }
if( (flavour==14 || flavour==-14) && (isCC==1) ){ outfile_name = Form("/sps/km3net/users/stavropo/ORCA6/preproc/mc/atm_neutrinos/output_mu/%s",outfile.c_str()); } 
if( (flavour==16 || flavour==-16) && (isCC==1) ){ outfile_name = Form("/sps/km3net/users/stavropo/ORCA6/preproc/mc/atm_neutrinos/output_tau/%s",outfile.c_str()); }
if( isCC==0 ){ outfile_name = Form("/sps/km3net/users/stavropo/ORCA6/preproc/mc/atm_neutrinos/output_nc/%s",outfile.c_str()); }
TFile* f_out = new TFile( outfile_name.c_str() , "RECREATE" );

interaction_type = isCC; // 1-->CC || 0-->NC
*/

mc_atm_nu_events->SetBranchAddress("run",&run);
mc_atm_nu_events->SetBranchAddress("index",&index);
mc_atm_nu_events->SetBranchAddress("event_id",&event_id);
mc_atm_nu_events->SetBranchAddress("frame_index",&frame_index);
mc_atm_nu_events->SetBranchAddress("trigger_counter",&trigger_counter);
mc_atm_nu_events->SetBranchAddress("w3_osci",&w3_osci);
mc_atm_nu_events->SetBranchAddress("flav",&flav);
mc_atm_nu_events->SetBranchAddress("interaction_type",&interaction_type);
mc_atm_nu_events->SetBranchAddress("no_hits",&no_hits);
mc_atm_nu_events->SetBranchAddress("no_doms_hit",&no_doms_hit);
mc_atm_nu_events->SetBranchAddress("no_dus_hit",&no_dus_hit);
mc_atm_nu_events->SetBranchAddress("no_trig_hits",&no_trig_hits);
mc_atm_nu_events->SetBranchAddress("no_doms_trig_hit",&no_doms_trig_hit);
mc_atm_nu_events->SetBranchAddress("no_dus_trig_hit",&no_dus_trig_hit);
mc_atm_nu_events->SetBranchAddress("no_cher_hits",&no_cher_hits);
mc_atm_nu_events->SetBranchAddress("no_doms_cher_hit",&no_doms_cher_hit);
mc_atm_nu_events->SetBranchAddress("no_dus_cher_hit",&no_dus_cher_hit);
mc_atm_nu_events->SetBranchAddress("no_trig_cher_hits",&no_trig_cher_hits);
mc_atm_nu_events->SetBranchAddress("no_doms_trig_cher_hit",&no_doms_trig_cher_hit);
mc_atm_nu_events->SetBranchAddress("no_dus_trig_cher_hit",&no_dus_trig_cher_hit);
mc_atm_nu_events->SetBranchAddress("zenith",&zenith);
mc_atm_nu_events->SetBranchAddress("true_phi",&true_phi);
mc_atm_nu_events->SetBranchAddress("reco_phi",&reco_phi);
mc_atm_nu_events->SetBranchAddress("bjorken_y",&bjorken_y); 
mc_atm_nu_events->SetBranchAddress("true_zenith",&true_zenith);
mc_atm_nu_events->SetBranchAddress("cos_zen",&cos_zen);
mc_atm_nu_events->SetBranchAddress("true_cos_zen",&true_cos_zen);
mc_atm_nu_events->SetBranchAddress("max_lik",&max_lik);
mc_atm_nu_events->SetBranchAddress("log_lik",&log_lik);
mc_atm_nu_events->SetBranchAddress("true_energy",&true_energy);
mc_atm_nu_events->SetBranchAddress("reco_energy",&reco_energy);
mc_atm_nu_events->SetBranchAddress("reco_vrtx_x",&reco_vrtx_x);
mc_atm_nu_events->SetBranchAddress("reco_vrtx_y",&reco_vrtx_y);
mc_atm_nu_events->SetBranchAddress("reco_vrtx_z",&reco_vrtx_z);
mc_atm_nu_events->SetBranchAddress("reco_vrtx_r",&reco_vrtx_r);
mc_atm_nu_events->SetBranchAddress("Nhits",&Nhits);
mc_atm_nu_events->SetBranchAddress("Qhits",&Qhits);
mc_atm_nu_events->SetBranchAddress("beta0",&beta0);
mc_atm_nu_events->SetBranchAddress("TrkLength",&TrkLength);
mc_atm_nu_events->SetBranchAddress("d_closest",&d_closest);
mc_atm_nu_events->SetBranchAddress("z_closest",&z_closest);
mc_atm_nu_events->SetBranchAddress("mean_z_hits",&mean_z_hits);
mc_atm_nu_events->SetBranchAddress("mean_z_trig_hits",&mean_z_trig_hits);
mc_atm_nu_events->SetBranchAddress("mean_z_cher_hits",&mean_z_cher_hits);
mc_atm_nu_events->SetBranchAddress("mean_z_trig_cher_hits",&mean_z_trig_cher_hits);
mc_atm_nu_events->SetBranchAddress("trig_hits_over_all",&trig_hits_over_all);
mc_atm_nu_events->SetBranchAddress("cher_hits_over_all",&cher_hits_over_all);
mc_atm_nu_events->SetBranchAddress("trig_cher_hits_over_all",&trig_cher_hits_over_all);
mc_atm_nu_events->SetBranchAddress("Qup_m_Qdn_JGandalf",&Qup_m_Qdn_JGandalf);
mc_atm_nu_events->SetBranchAddress("max_tot_trig",&max_tot_trig);
mc_atm_nu_events->SetBranchAddress("early_trig_10",&early_trig_10);
mc_atm_nu_events->SetBranchAddress("Dn_m_Up_hits",&Dn_m_Up_hits);
mc_atm_nu_events->SetBranchAddress("Dn_m_Up_trig_hits",&Dn_m_Up_trig_hits);
mc_atm_nu_events->SetBranchAddress("Dn_m_Up_cher_hits",&Dn_m_Up_cher_hits);
mc_atm_nu_events->SetBranchAddress("Dn_m_Up_trig_cher_hits",&Dn_m_Up_trig_cher_hits);

//For the horizontal

TH1F* h_mc_atm_nu_horizontal_no_hits = new TH1F("h_mc_atm_nu_horizontal_no_hits",";# hits;counts;", 1001 , -0.5 , 1000.5 );
TH1F* h_mc_atm_nu_horizontal_no_hit_doms = new TH1F("h_mc_atm_nu_horizontal_no_hit_doms","hit DOMs", 108 , 0.5 , 108.5 );
TH1F* h_mc_atm_nu_horizontal_no_trig_hits = new TH1F("h_mc_atm_nu_horizontal_no_trig_hits",";# hits;counts;", 1001 , -0.5 , 1000.5 );
TH1F* h_mc_atm_nu_horizontal_no_trig_doms = new TH1F("h_mc_atm_nu_horizontal_no_trig_doms","triggered DOMs", 108 , 0.5 , 108.5 );
TH1F* h_mc_atm_nu_horizontal_no_cher_hits = new TH1F("h_mc_atm_nu_horizontal_no_cher_hits","Cherenkov hits", 1001 , -0.5 , 1000.5 );
TH1F* h_mc_atm_nu_horizontal_no_cher_doms = new TH1F("h_mc_atm_nu_horizontal_no_cher_doms","Cherenkov doms", 108 , 0.5 , 108.5 );
TH1F* h_mc_atm_nu_horizontal_no_trig_cher_doms = new TH1F("h_mc_atm_nu_horizontal_no_trig_cher_doms","Trig & Cherenkov doms", 72 , 0.5 , 72.5 );
TH1F* h_mc_atm_nu_horizontal_no_trig_dus = new TH1F("h_mc_atm_nu_horizontal_no_trig_dus"," DUs", 6 , 0.5 , 6.5 );
TH1F* h_mc_atm_nu_horizontal_no_cher_dus = new TH1F("h_mc_atm_nu_horizontal_no_cher_dus"," DUs", 6 , 0.5 , 6.5 );
TH1F* h_mc_atm_nu_horizontal_no_trig_cher_dus = new TH1F("h_mc_atm_nu_horizontal_no_trig_cher_dus"," DUs", 6 , 0.5 , 6.5 );
TH1F* h_mc_atm_nu_horizontal_no_trig_cher_hits = new TH1F("h_mc_atm_nu_horizontal_no_trig_cher_hits","Trig & Cherenkov hits", 1001 , -0.5 , 1000.5 );
TH1F* h_mc_atm_nu_horizontal_zenith = new TH1F("h_mc_atm_nu_horizontal_zenith",";reco zenith [deg]", 180 , 0.0 , 180.0 );
TH1F* h_mc_atm_nu_horizontal_true_zenith = new TH1F("h_mc_atm_nu_horizontal_true_zenith",";true zenith [deg]", 180 , 0.0 , 180.0 );
TH1F* h_mc_atm_nu_horizontal_cos_zenith = new TH1F("h_mc_atm_nu_horizontal_cos_zen",";cos(reco zenith)", 100 , -1.0 , 1.0 );
TH1F* h_mc_atm_nu_horizontal_true_cos_zen = new TH1F("h_mc_atm_nu_horizontal_true_cos_zen",";cos(reco zenith)", 100 , -1.0 , 1.0 );
TH1F* h_mc_atm_nu_horizontal_max_lik_dist = new TH1F("h_mc_atm_nu_horizontal_max_lik",";L;", 100 , 0 , 2000 );
TH1F* h_mc_atm_nu_horizontal_log_lik_dist = new TH1F("h_mc_atm_nu_horizontal_log_lik",";log(L);", 100 , -1.0 , 4.0 );
TH1F* h_mc_atm_nu_horizontal_true_energy_no_log = new TH1F("h_mc_atm_nu_horizontal_true_energy_no_log", ";True Energy (GeV);",500,0,5000);
TH1F* h_mc_atm_nu_horizontal_true_energy = new TH1F("h_mc_atm_nu_horizontal_true_energy",";log[true/GeV];", 40 , 0 , 4.0 );
TH1F* h_mc_atm_nu_horizontal_reco_energy = new TH1F("h_mc_atm_nu_horizontal_reco_energy",";log[E_reco/GeV];", 40 , 0 , 4.0 );
TH2F* h_mc_atm_nu_horizontal_E_reco_E_true_rec_zen_all = new TH2F("h_mc_atm_nu_horizontal_E_reco_E_true_rec_zen_all",";log[E_true/GeV];log[E_reco/GeV]", 300 , 0 , 4.0 , 300 , 0 , 4.0 );
TH2F* h_mc_atm_nu_horizontal_E_reco_E_true_rec_zen_30_all = new TH2F("h_mc_atm_nu_horizontal_E_reco_E_true_rec_zen_30_all",";log[E_true/GeV];log[E_reco/GeV]", 300 , 0 , 4.0 , 300 , 0 , 4.0 );
TH2F* h_mc_atm_nu_horizontal_E_reco_E_true_rec_zen_120_all = new TH2F("h_mc_atm_nu_horizontal_E_reco_E_true_rec_zen_120_all",";log[E_true/GeV];log[E_reco/GeV]", 300 , 0 , 4.0 , 300 , 0 , 4.0 );
TH2F* h_mc_atm_nu_horizontal_E_reco_E_true_rec_zen_150_all = new TH2F("h_mc_atm_nu_horizontal_E_reco_E_true_rec_zen_150_all",";log[E_true/GeV];log[E_reco/GeV]",300 , 0 , 4.0 , 300 , 0 , 4.0 );
TH2F* h_mc_atm_nu_horizontal_reco_vertex_pos = new TH2F("h_mc_atm_nu_horizontal_reco_vertex_pos",";radial position [m];vertical position [m]", 100, 0 , 100 , 160 , -40 , 280 );
TH1F* h_mc_atm_nu_horizontal_reco_vrtx_r = new TH1F("h_mc_atm_nu_horizontal_reco_vrtx_r","reco vrtx radial pos.;r [m];", 40 , 0 , 200 );
TH1F* h_mc_atm_nu_horizontal_reco_vrtx_x = new TH1F("h_mc_atm_nu_horizontal_reco_vrtx_x","reco vrtx x pos.;x [m];", 40 , 0 , 200 );
TH1F* h_mc_atm_nu_horizontal_reco_vrtx_y = new TH1F("h_mc_atm_nu_horizontal_reco_vrtx_y","reco vrtx y pos.;y [m];", 40 , 0 , 200 );
TH1F* h_mc_atm_nu_horizontal_reco_vrtx_z = new TH1F("h_mc_atm_nu_horizontal_reco_vrtx_z","reco vrtx z pos.;z [m];", 40 , 0 , 200 );
TH1F* h_mc_atm_nu_horizontal_Nhits = new TH1F("h_mc_atm_nu_horizontal_Nhits",";NHits;", 300 , 0.5 , 300.5 );
TH1F* h_mc_atm_nu_horizontal_beta0 = new TH1F("h_mc_atm_nu_horizontal_beta0",";beta0;",100,0,1);
TH1F* h_mc_atm_nu_horizontal_Qhits = new TH1F("h_mc_atm_nu_horizontal_Qhits",";L/Nhits;",120,0,6);
TH1F* h_mc_atm_nu_horizontal_trklength = new TH1F("h_mc_atm_nu_horizontal_trklength",";Track Length [m];", 150 , 0 , 300);
TH1F* h_mc_atm_nu_horizontal_d_closest = new TH1F("h_mc_atm_nu_horizontal_d_closest",";d_closest [m];", 15 , 0 , 150 );
TH1F* h_mc_atm_nu_horizontal_z_closest = new TH1F("h_mc_atm_nu_horizontal_z_closest",";z_closest [m];", 50 , -100 , 400 );
TH1F* h_mc_atm_nu_horizontal_mean_z_hits = new TH1F("h_mc_atm_nu_horizontal_mean_z_hits",";vertical position [m];", 160 , -40 , 280 );
TH1F* h_mc_atm_nu_horizontal_mean_z_trig_hits = new TH1F("h_mc_atm_nu_horizontal_mean_z_trig_hits",";vertical position [m];", 160 , -40 , 280 );
TH1F* h_mc_atm_nu_horizontal_mean_z_cher_hits = new TH1F("h_mc_atm_nu_horizontal_mean_z_cher_hits",";vertical position [m];", 160 , -40 , 280 );
TH1F* h_mc_atm_nu_horizontal_mean_z_trig_cher_hits = new TH1F("h_mc_atm_nu_horizontal_mean_z_trig_cher_hits",";vertical position [m];", 160 , -40 , 280 );
TH1F* h_mc_atm_nu_horizontal_ratio_hits_trig_over_all = new TH1F("h_mc_atm_nu_horizontal_ratio_hits_trig_over_all","trig_hits/all_hits", 100 , 0.0 , 1.0 );
TH1F* h_mc_atm_nu_horizontal_ratio_hits_cher_over_all = new TH1F("h_mc_atm_nu_horizontal_ratio_hits_cher_over_all","cher_hits/all_hits", 100 , 0.0 , 1.0 );
TH1F* h_mc_atm_nu_horizontal_ratio_hits_trig_cher_over_all = new TH1F("h_mc_atm_nu_horizontal_ratio_hits_trig_cher_over_all","cher_hits/all_hits", 100 , 0.0 , 1.0 );
TH1F* h_mc_atm_nu_horizontal_Qup_m_Qdn_JGandalf = new TH1F("h_mc_atm_nu_horizontal_Qup_m_Qdn_JGandalf","Qup_m_Qdn_JGandalf;Qup-Qdn;", 250 , 0 , 250 );
TH1F* h_mc_atm_nu_horizontal_max_trig_tot = new TH1F("h_mc_atm_nu_horizontal_max_trig_tot",";tot [ns];", 100 , 0 , 500 );
TH1F* h_mc_atm_nu_horizontal_early_trig_10 = new TH1F("h_mc_atm_nu_horizontal_early_trig_10","", 201 , -0.5 , 200.5 );
TH1F* h_mc_atm_nu_horizontal_Dn_m_Up_hits = new TH1F("h_mc_atm_nu_horizontal_Dn_m_Up_hits","Lower_hits_minus_Upper_hits" , 1500 , -500 , 1000);
TH1F* h_mc_atm_nu_horizontal_Dn_m_Up_trig_hits = new TH1F("h_mc_atm_nu_horizontal_Dn_m_Up_trig_hits","Lower_hits_minus_Upper_hits_trig" , 1500 , -500 , 1000);
TH1F* h_mc_atm_nu_horizontal_Dn_m_Up_cher_hits = new TH1F("h_mc_atm_nu_horizontal_Dn_m_Up_cher_hits","Lower_hits_minus_Upper_hits_cher" , 1500 , -500 , 1000);
TH1F* h_mc_atm_nu_horizontal_Dn_m_Up_trig_cher_hits = new TH1F("h_mc_atm_nu_horizontal_Dn_m_Up_trig_cher_hits","Lower_hits_minus_Upper_hits_trig_cher" , 1500 , -500 , 1000);
TH1F* h_mc_atm_nu_horizontal_diff_energy= new TH1F("h_mc_atm_nu_horizontal_diff_energy",";(E_true-E_reco)/E_true",100,-1,1);
TH2F* h_mc_atm_nu_horizontal_diff_energy_cos_zen= new TH2F("h_mc_atm_nu_horizontal_diff_energy_cos_zen",";zenith [degrees];", 180 , 0.0 , 180.0 , 299 , -2 , 1 );
TH2F* h_mc_atm_nu_horizontal_E_true_zenith_upgoing= new TH2F("h_mc_atm_nu_horizontal_E_true_zenith_upgoing",";zenith [degrees];",30 , 150.0 , 180 , 300 , 0 ,4);
TH2F* h_mc_atm_nu_horizontal_E_true_zenith_horizontal= new TH2F("h_mc_atm_nu_horizontal_E_true_zenith_horizontal",";zenith [degrees];",30 , 0.0 , 30 , 300 , 0 ,4);

//------------------------------- Energy Slices -------------------------------------------------
//-------------------------------- Low Slice ----------------------------------------------------
TH1F* h_mc_atm_nu_horizontal_lslice_no_hits = new TH1F("h_mc_atm_nu_horizontal_lslice_no_hits",";# hits;counts;", 1001 , -0.5 , 1000.5 );
TH1F* h_mc_atm_nu_horizontal_lslice_no_hit_doms = new TH1F("h_mc_atm_nu_horizontal_lslice_no_hit_doms","hit DOMs", 108 , 0.5 , 108.5 );
TH1F* h_mc_atm_nu_horizontal_lslice_no_trig_hits = new TH1F("h_mc_atm_nu_horizontal_lslice_no_trig_hits",";# hits;counts;", 1001 , -0.5 , 1000.5 );
TH1F* h_mc_atm_nu_horizontal_lslice_no_trig_doms = new TH1F("h_mc_atm_nu_horizontal_lslice_no_trig_doms","triggered DOMs", 108 , 0.5 , 108.5 );
TH1F* h_mc_atm_nu_horizontal_lslice_no_cher_hits = new TH1F("h_mc_atm_nu_horizontal_lslice_no_cher_hits","Cherenkov hits", 1001 , -0.5 , 1000.5 );
TH1F* h_mc_atm_nu_horizontal_lslice_no_cher_doms = new TH1F("h_mc_atm_nu_horizontal_lslice_no_cher_doms","Cherenkov doms", 108 , 0.5 , 108.5 );
TH1F* h_mc_atm_nu_horizontal_lslice_no_trig_cher_doms = new TH1F("h_mc_atm_nu_horizontal_lslice_no_trig_cher_doms","Trig & Cherenkov doms", 72 , 0.5 , 72.5 );
TH1F* h_mc_atm_nu_horizontal_lslice_no_trig_dus = new TH1F("h_mc_atm_nu_horizontal_lslice_no_trig_dus"," DUs", 6 , 0.5 , 6.5 );
TH1F* h_mc_atm_nu_horizontal_lslice_no_cher_dus = new TH1F("h_mc_atm_nu_horizontal_lslice_no_cher_dus"," DUs", 6 , 0.5 , 6.5 );
TH1F* h_mc_atm_nu_horizontal_lslice_no_trig_cher_dus = new TH1F("h_mc_atm_nu_horizontal_lslice_no_trig_cher_dus"," DUs", 6 , 0.5 , 6.5 );
TH1F* h_mc_atm_nu_horizontal_lslice_no_trig_cher_hits = new TH1F("h_mc_atm_nu_horizontal_lslice_no_trig_cher_hits","Trig & Cherenkov hits", 1001 , -0.5 , 1000.5 );
TH1F* h_mc_atm_nu_horizontal_lslice_zenith = new TH1F("h_mc_atm_nu_horizontal_lslice_zenith",";reco zenith [deg]", 180 , 0.0 , 180.0 );
TH1F* h_mc_atm_nu_horizontal_lslice_true_zenith = new TH1F("h_mc_atm_nu_horizontal_lslice_true_zenith",";true zenith [deg]", 180 , 0.0 , 180.0 );
TH1F* h_mc_atm_nu_horizontal_lslice_cos_zenith = new TH1F("h_mc_atm_nu_horizontal_lslice_cos_zen",";cos(reco zenith)", 100 , -1.0 , 1.0 );
TH1F* h_mc_atm_nu_horizontal_lslice_true_cos_zen = new TH1F("h_mc_atm_nu_horizontal_lslice_true_cos_zen",";cos(reco zenith)", 100 , -1.0 , 1.0 );
TH1F* h_mc_atm_nu_horizontal_lslice_max_lik_dist = new TH1F("h_mc_atm_nu_horizontal_lslice_max_lik",";L;", 100 , 0 , 2000 );
TH1F* h_mc_atm_nu_horizontal_lslice_log_lik_dist = new TH1F("h_mc_atm_nu_horizontal_lslice_log_lik",";log(L);", 100 , -1.0 , 4.0 );
TH1F* h_mc_atm_nu_horizontal_lslice_true_energy_no_log = new TH1F("h_mc_atm_nu_horizontal_lslice_true_energy_no_log", ";True Energy (GeV);",500,0,5000);
TH1F* h_mc_atm_nu_horizontal_lslice_true_energy = new TH1F("h_mc_atm_nu_horizontal_lslice_true_energy",";log[true/GeV];", 40 , 0 , 4.0 );
TH1F* h_mc_atm_nu_horizontal_lslice_reco_energy = new TH1F("h_mc_atm_nu_horizontal_lslice_reco_energy",";log[E_reco/GeV];", 40 , 0 , 4.0 );
TH2F* h_mc_atm_nu_horizontal_lslice_reco_vertex_pos = new TH2F("h_mc_atm_nu_horizontal_lslice_reco_vertex_pos",";radial position [m];vertical position [m]", 100, 0 , 100 , 160 , -40 , 280 );
TH1F* h_mc_atm_nu_horizontal_lslice_reco_vrtx_r = new TH1F("h_mc_atm_nu_horizontal_lslice_reco_vrtx_r","reco vrtx radial pos.;r [m];", 40 , 0 , 200 );
TH1F* h_mc_atm_nu_horizontal_lslice_reco_vrtx_x = new TH1F("h_mc_atm_nu_horizontal_lslice_reco_vrtx_x","reco vrtx x pos.;x [m];", 40 , 0 , 200 );
TH1F* h_mc_atm_nu_horizontal_lslice_reco_vrtx_y = new TH1F("h_mc_atm_nu_horizontal_lslice_reco_vrtx_y","reco vrtx y pos.;y [m];", 40 , 0 , 200 );
TH1F* h_mc_atm_nu_horizontal_lslice_reco_vrtx_z = new TH1F("h_mc_atm_nu_horizontal_lslice_reco_vrtx_z","reco vrtx z pos.;z [m];", 40 , 0 , 200 );
TH1F* h_mc_atm_nu_horizontal_lslice_Nhits = new TH1F("h_mc_atm_nu_horizontal_lslice_Nhits",";NHits;", 300 , 0.5 , 300.5 );
TH1F* h_mc_atm_nu_horizontal_lslice_beta0 = new TH1F("h_mc_atm_nu_horizontal_lslice_beta0",";beta0;",100,0,1);
TH1F* h_mc_atm_nu_horizontal_lslice_Qhits = new TH1F("h_mc_atm_nu_horizontal_lslice_Qhits",";L/Nhits;",120,0,6);
TH1F* h_mc_atm_nu_horizontal_lslice_trklength = new TH1F("h_mc_atm_nu_horizontal_lslice_trklength",";Track Length [m];", 150 , 0 , 300);
TH1F* h_mc_atm_nu_horizontal_lslice_d_closest = new TH1F("h_mc_atm_nu_horizontal_lslice_d_closest",";d_closest [m];", 15 , 0 , 150 );
TH1F* h_mc_atm_nu_horizontal_lslice_z_closest = new TH1F("h_mc_atm_nu_horizontal_lslice_z_closest",";z_closest [m];", 50 , -100 , 400 );
TH1F* h_mc_atm_nu_horizontal_lslice_mean_z_hits = new TH1F("h_mc_atm_nu_horizontal_lslice_mean_z_hits",";vertical position [m];", 160 , -40 , 280 );
TH1F* h_mc_atm_nu_horizontal_lslice_mean_z_trig_hits = new TH1F("h_mc_atm_nu_horizontal_lslice_mean_z_trig_hits",";vertical position [m];", 160 , -40 , 280 );
TH1F* h_mc_atm_nu_horizontal_lslice_mean_z_cher_hits = new TH1F("h_mc_atm_nu_horizontal_lslice_mean_z_cher_hits",";vertical position [m];", 160 , -40 , 280 );
TH1F* h_mc_atm_nu_horizontal_lslice_mean_z_trig_cher_hits = new TH1F("h_mc_atm_nu_horizontal_lslice_mean_z_trig_cher_hits",";vertical position [m];", 160 , -40 , 280 );
TH1F* h_mc_atm_nu_horizontal_lslice_ratio_hits_trig_over_all = new TH1F("h_mc_atm_nu_horizontal_lslice_ratio_hits_trig_over_all","trig_hits/all_hits", 100 , 0.0 , 1.0 );
TH1F* h_mc_atm_nu_horizontal_lslice_ratio_hits_cher_over_all = new TH1F("h_mc_atm_nu_horizontal_lslice_ratio_hits_cher_over_all","cher_hits/all_hits", 100 , 0.0 , 1.0 );
TH1F* h_mc_atm_nu_horizontal_lslice_ratio_hits_trig_cher_over_all = new TH1F("h_mc_atm_nu_horizontal_lslice_ratio_hits_trig_cher_over_all","cher_hits/all_hits", 100 , 0.0 , 1.0 );
TH1F* h_mc_atm_nu_horizontal_lslice_Qup_m_Qdn_JGandalf = new TH1F("h_mc_atm_nu_horizontal_lslice_Qup_m_Qdn_JGandalf","Qup_m_Qdn_JGandalf;Qup-Qdn;", 250 , 0 , 250 );
TH1F* h_mc_atm_nu_horizontal_lslice_max_trig_tot = new TH1F("h_mc_atm_nu_horizontal_lslice_max_trig_tot",";tot [ns];", 100 , 0 , 500 );
TH1F* h_mc_atm_nu_horizontal_lslice_early_trig_10 = new TH1F("h_mc_atm_nu_horizontal_lslice_early_trig_10","", 201 , -0.5 , 200.5 );
TH1F* h_mc_atm_nu_horizontal_lslice_Dn_m_Up_hits = new TH1F("h_mc_atm_nu_horizontal_lslice_Dn_m_Up_hits","Lower_hits_minus_Upper_hits" , 1500 , -500 , 1000);
TH1F* h_mc_atm_nu_horizontal_lslice_Dn_m_Up_trig_hits = new TH1F("h_mc_atm_nu_horizontal_lslice_Dn_m_Up_trig_hits","Lower_hits_minus_Upper_hits_trig" , 1500 , -500 , 1000);
TH1F* h_mc_atm_nu_horizontal_lslice_Dn_m_Up_cher_hits = new TH1F("h_mc_atm_nu_horizontal_lslice_Dn_m_Up_cher_hits","Lower_hits_minus_Upper_hits_cher" , 1500 , -500 , 1000);
TH1F* h_mc_atm_nu_horizontal_lslice_Dn_m_Up_trig_cher_hits = new TH1F("h_mc_atm_nu_horizontal_lslice_Dn_m_Up_trig_cher_hits","Lower_hits_minus_Upper_hits_trig_cher" , 1500 , -500 , 1000);
TH1F* h_mc_atm_nu_horizontal_lslice_diff_energy= new TH1F("h_mc_atm_nu_horizontal_lslice_diff_energy",";(E_true-E_reco)/E_true",100,-1,1);
TH2F* h_mc_atm_nu_horizontal_lslice_diff_energy_cos_zen= new TH2F("h_mc_atm_nu_horizontal_lslice_diff_energy_cos_zen",";zenith [degrees];", 180 , 0.0 , 180.0 , 299 , -2 , 1 );

TH1F* h_mc_atm_nu_horizontal_lslice_le_mean_z_hits= new TH1F("h_mc_atm_nu_horizontal_lslice_le_mean_z_hits",";vertical position [m];", 160 , -40 , 280 );
TH1F* h_mc_atm_nu_horizontal_lslice_le_reco_vrtx_r = new TH1F("h_mc_atm_nu_horizontal_lslice_le_reco_vrtx_r","reco vrtx radial pos.;r [m];", 40 , 0 , 200 );
TH1F* h_mc_atm_nu_horizontal_lslice_le_trklength = new TH1F("h_mc_atm_nu_horizontal_lslice_le_trklength",";Track Length [m];", 150 , 0 , 300);
TH1F* h_mc_atm_nu_horizontal_lslice_le_zenith = new TH1F("h_mc_atm_nu_horizontal_lslice_le_zenith",";reco zenith [deg]", 180 , 0.0 , 180.0 );
TH1F* h_mc_atm_nu_horizontal_lslice_he_zenith = new TH1F("h_mc_atm_nu_horizontal_lslice_he_zenith",";reco zenith [deg]", 180 , 0.0 , 180.0 );
TH1F* h_mc_atm_nu_horizontal_lslice_le_reco_vrtx_z = new TH1F("h_mc_atm_nu_horizontal_lslice_le_reco_vrtx_z","reco vrtx vertical pos.;r [m];", 40 , 0 , 200 );
TH1F* h_mc_atm_nu_horizontal_lslice_le_no_hit_doms = new TH1F("h_mc_atm_nu_horizontal_lslice_le_no_hit_doms","hit DOMs", 108 , 0.5 , 108.5 );
TH1F* h_mc_atm_nu_horizontal_lslice_le_no_cher_doms = new TH1F("h_mc_atm_nu_horizontal_lslice_le_no_cher_doms","Cherenkov doms", 108 , 0.5 , 108.5 );
TH1F* h_mc_atm_nu_horizontal_lslice_le_Nhits = new TH1F("h_mc_atm_nu_horizontal_lslice_le_Nhits",";NHits;", 300 , 0.5 , 300.5 );
TH1F* h_mc_atm_nu_horizontal_lslice_le_beta0 = new TH1F("h_mc_atm_nu_horizontal_lslice_le_beta0",";beta0;",100,0,1);
TH1F* h_mc_atm_nu_horizontal_lslice_le_Qhits = new TH1F("h_mc_atm_nu_horizontal_lslice_le_Qhits",";L/Nhits;",120,0,6);
TH1F* h_mc_atm_nu_horizontal_lslice_le_true_phi = new TH1F("h_mc_atm_nu_horizontal_lslice_le_true_phi",";true_phi;",36,-180,180);
TH1F* h_mc_atm_nu_horizontal_lslice_le_reco_phi = new TH1F("h_mc_atm_nu_horizontal_lslice_le_reco_phi",";reco_phi;",36,-180,180);
TH1F* h_mc_atm_nu_horizontal_lslice_le_bjorken_y = new TH1F("h_mc_atm_nu_horizontal_lslice_le_bjorken_y",";bjorken_y;",100,0,1);
TH1F* h_mc_atm_nu_horizontal_lslice_le_d_closest = new TH1F("h_mc_atm_nu_horizontal_lslice_le_d_closest",";d_closest [m];", 15 , 0 , 150 );
TH1F* h_mc_atm_nu_horizontal_lslice_le_z_closest = new TH1F("h_mc_atm_nu_horizontal_lslice_le_z_closest",";z_closest [m];", 50 , -100 , 400 );

TH1F* h_mc_atm_nu_horizontal_lslice_he_d_closest = new TH1F("h_mc_atm_nu_horizontal_lslice_he_d_closest",";d_closest [m];", 15 , 0 , 150 );
TH1F* h_mc_atm_nu_horizontal_lslice_he_z_closest = new TH1F("h_mc_atm_nu_horizontal_lslice_he_z_closest",";z_closest [m];", 50 , -100 , 400 );
TH1F* h_mc_atm_nu_horizontal_lslice_he_true_phi = new TH1F("h_mc_atm_nu_horizontal_lslice_he_true_phi",";true_phi;",36,-180,180);
TH1F* h_mc_atm_nu_horizontal_lslice_he_reco_phi = new TH1F("h_mc_atm_nu_horizontal_lslice_he_reco_phi",";reco_phi;",36,-180,180);
TH1F* h_mc_atm_nu_horizontal_lslice_he_bjorken_y = new TH1F("h_mc_atm_nu_horizontal_lslice_he_bjorken_y",";bjorken_y;",100,0,1);
TH1F* h_mc_atm_nu_horizontal_lslice_he_no_hit_doms = new TH1F("h_mc_atm_nu_horizontal_lslice_he_no_hit_doms","hit DOMs", 108 , 0.5 , 108.5 );
TH1F* h_mc_atm_nu_horizontal_lslice_he_no_cher_doms = new TH1F("h_mc_atm_nu_horizontal_lslice_he_no_cher_doms","Cherenkov doms", 108 , 0.5 , 108.5 );
TH1F* h_mc_atm_nu_horizontal_lslice_he_Nhits = new TH1F("h_mc_atm_nu_horizontal_lslice_he_Nhits",";NHits;", 300 , 0.5 , 300.5 );
TH1F* h_mc_atm_nu_horizontal_lslice_he_beta0 = new TH1F("h_mc_atm_nu_horizontal_lslice_he_beta0",";beta0;",100,0,1);
TH1F* h_mc_atm_nu_horizontal_lslice_he_Qhits = new TH1F("h_mc_atm_nu_horizontal_lslice_he_Qhits",";L/Nhits;",120,0,6);
TH1F* h_mc_atm_nu_horizontal_lslice_he_reco_vrtx_z = new TH1F("h_mc_atm_nu_horizontal_lslice_he_reco_vrtx_z","reco vrtx vertical pos.;r [m];", 40 , 0 , 200 );
TH2F* h_mc_atm_nu_horizontal_lslice_he_reco_vertex_pos = new TH2F("h_mc_atm_nu_horizontal_lslice_he_reco_vertex_pos",";radial position [m];vertical position [m]", 100, 0 , 100 , 160 , -40 , 280 );
TH1F* h_mc_atm_nu_horizontal_lslice_he_trklength = new TH1F("h_mc_atm_nu_horizontal_lslice_he_trklength",";Track Length [m];", 150 , 0 , 300);
TH1F* h_mc_atm_nu_horizontal_lslice_he_reco_vrtx_r = new TH1F("h_mc_atm_nu_horizontal_lslice_he_reco_vrtx_r","reco vrtx radial pos.;r [m];", 40 , 0 , 200 );
TH1F* h_mc_atm_nu_horizontal_lslice_he_mean_z_hits= new TH1F("h_mc_atm_nu_horizontal_lslice_he_mean_z_hits",";vertical position [m];", 160 , -40 , 280 );


//--------------------------------- Medium Slice ------------------------------------------------
TH1F* h_mc_atm_nu_horizontal_mslice_no_hits = new TH1F("h_mc_atm_nu_horizontal_mslice_no_hits",";# hits;counts;", 1001 , -0.5 , 1000.5 );
TH1F* h_mc_atm_nu_horizontal_mslice_no_hit_doms = new TH1F("h_mc_atm_nu_horizontal_mslice_no_hit_doms","hit DOMs", 108 , 0.5 , 108.5 );
TH1F* h_mc_atm_nu_horizontal_mslice_no_trig_hits = new TH1F("h_mc_atm_nu_horizontal_mslice_no_trig_hits",";# hits;counts;", 1001 , -0.5 , 1000.5 );
TH1F* h_mc_atm_nu_horizontal_mslice_no_trig_doms = new TH1F("h_mc_atm_nu_horizontal_mslice_no_trig_doms","triggered DOMs", 108 , 0.5 , 108.5 );
TH1F* h_mc_atm_nu_horizontal_mslice_no_cher_hits = new TH1F("h_mc_atm_nu_horizontal_mslice_no_cher_hits","Cherenkov hits", 1001 , -0.5 , 1000.5 );
TH1F* h_mc_atm_nu_horizontal_mslice_no_cher_doms = new TH1F("h_mc_atm_nu_horizontal_mslice_no_cher_doms","Cherenkov doms", 108 , 0.5 , 108.5 );
TH1F* h_mc_atm_nu_horizontal_mslice_no_trig_cher_doms = new TH1F("h_mc_atm_nu_horizontal_mslice_no_trig_cher_doms","Trig & Cherenkov doms", 72 , 0.5 , 72.5 );
TH1F* h_mc_atm_nu_horizontal_mslice_no_trig_dus = new TH1F("h_mc_atm_nu_horizontal_mslice_no_trig_dus"," DUs", 6 , 0.5 , 6.5 );
TH1F* h_mc_atm_nu_horizontal_mslice_no_cher_dus = new TH1F("h_mc_atm_nu_horizontal_mslice_no_cher_dus"," DUs", 6 , 0.5 , 6.5 );
TH1F* h_mc_atm_nu_horizontal_mslice_no_trig_cher_dus = new TH1F("h_mc_atm_nu_horizontal_mslice_no_trig_cher_dus"," DUs", 6 , 0.5 , 6.5 );
TH1F* h_mc_atm_nu_horizontal_mslice_no_trig_cher_hits = new TH1F("h_mc_atm_nu_horizontal_mslice_no_trig_cher_hits","Trig & Cherenkov hits", 1001 , -0.5 , 1000.5 );
TH1F* h_mc_atm_nu_horizontal_mslice_zenith = new TH1F("h_mc_atm_nu_horizontal_mslice_zenith",";reco zenith [deg]", 180 , 0.0 , 180.0 );
TH1F* h_mc_atm_nu_horizontal_mslice_true_zenith = new TH1F("h_mc_atm_nu_horizontal_mslice_true_zenith",";true zenith [deg]", 180 , 0.0 , 180.0 );
TH1F* h_mc_atm_nu_horizontal_mslice_cos_zenith = new TH1F("h_mc_atm_nu_horizontal_mslice_cos_zen",";cos(reco zenith)", 100 , -1.0 , 1.0 );
TH1F* h_mc_atm_nu_horizontal_mslice_true_cos_zen = new TH1F("h_mc_atm_nu_horizontal_mslice_true_cos_zen",";cos(reco zenith)", 100 , -1.0 , 1.0 );
TH1F* h_mc_atm_nu_horizontal_mslice_max_lik_dist = new TH1F("h_mc_atm_nu_horizontal_mslice_max_lik",";L;", 100 , 0 , 2000 );
TH1F* h_mc_atm_nu_horizontal_mslice_log_lik_dist = new TH1F("h_mc_atm_nu_horizontal_mslice_log_lik",";log(L);", 100 , -1.0 , 4.0 );
TH1F* h_mc_atm_nu_horizontal_mslice_true_energy_no_log = new TH1F("h_mc_atm_nu_horizontal_mslice_true_energy_no_log", ";True Energy (GeV);",500,0,5000);
TH1F* h_mc_atm_nu_horizontal_mslice_true_energy = new TH1F("h_mc_atm_nu_horizontal_mslice_true_energy",";log[true/GeV];", 40 , 0 , 4.0 );
TH1F* h_mc_atm_nu_horizontal_mslice_reco_energy = new TH1F("h_mc_atm_nu_horizontal_mslice_reco_energy",";log[E_reco/GeV];", 40 , 0 , 4.0 );
TH2F* h_mc_atm_nu_horizontal_mslice_reco_vertex_pos = new TH2F("h_mc_atm_nu_horizontal_mslice_reco_vertex_pos",";radial position [m];vertical position [m]", 100, 0 , 100 , 160 , -40 , 280 );
TH1F* h_mc_atm_nu_horizontal_mslice_reco_vrtx_r = new TH1F("h_mc_atm_nu_horizontal_mslice_reco_vrtx_r","reco vrtx radial pos.;r [m];", 40 , 0 , 200 );
TH1F* h_mc_atm_nu_horizontal_mslice_reco_vrtx_x = new TH1F("h_mc_atm_nu_horizontal_mslice_reco_vrtx_x","reco vrtx x pos.;x [m];", 40 , 0 , 200 );
TH1F* h_mc_atm_nu_horizontal_mslice_reco_vrtx_y = new TH1F("h_mc_atm_nu_horizontal_mslice_reco_vrtx_y","reco vrtx y pos.;y [m];", 40 , 0 , 200 );
TH1F* h_mc_atm_nu_horizontal_mslice_reco_vrtx_z = new TH1F("h_mc_atm_nu_horizontal_mslice_reco_vrtx_z","reco vrtx z pos.;z [m];", 40 , 0 , 200 );
TH1F* h_mc_atm_nu_horizontal_mslice_Nhits = new TH1F("h_mc_atm_nu_horizontal_mslice_Nhits",";NHits;", 300 , 0.5 , 300.5 ); 
TH1F* h_mc_atm_nu_horizontal_mslice_beta0 = new TH1F("h_mc_atm_nu_horizontal_mslice_beta0",";beta0;",100,0,1);
TH1F* h_mc_atm_nu_horizontal_mslice_Qhits = new TH1F("h_mc_atm_nu_horizontal_mslice_Qhits",";L/Nhits;",120,0,6);
TH1F* h_mc_atm_nu_horizontal_mslice_trklength = new TH1F("h_mc_atm_nu_horizontal_mslice_trklength",";Track Length [m];", 150 , 0 , 300);
TH1F* h_mc_atm_nu_horizontal_mslice_d_closest = new TH1F("h_mc_atm_nu_horizontal_mslice_d_closest",";d_closest [m];", 15 , 0 , 150 );
TH1F* h_mc_atm_nu_horizontal_mslice_z_closest = new TH1F("h_mc_atm_nu_horizontal_mslice_z_closest",";z_closest [m];", 50 , -100 , 400 );
TH1F* h_mc_atm_nu_horizontal_mslice_mean_z_hits = new TH1F("h_mc_atm_nu_horizontal_mslice_mean_z_hits",";vertical position [m];", 160 , -40 , 280 );
TH1F* h_mc_atm_nu_horizontal_mslice_mean_z_trig_hits = new TH1F("h_mc_atm_nu_horizontal_mslice_mean_z_trig_hits",";vertical position [m];", 160 , -40 , 280 );
TH1F* h_mc_atm_nu_horizontal_mslice_mean_z_cher_hits = new TH1F("h_mc_atm_nu_horizontal_mslice_mean_z_cher_hits",";vertical position [m];", 160 , -40 , 280 );
TH1F* h_mc_atm_nu_horizontal_mslice_mean_z_trig_cher_hits = new TH1F("h_mc_atm_nu_horizontal_mslice_mean_z_trig_cher_hits",";vertical position [m];", 160 , -40 , 280 );
TH1F* h_mc_atm_nu_horizontal_mslice_ratio_hits_trig_over_all = new TH1F("h_mc_atm_nu_horizontal_mslice_ratio_hits_trig_over_all","trig_hits/all_hits", 100 , 0.0 , 1.0 );
TH1F* h_mc_atm_nu_horizontal_mslice_ratio_hits_cher_over_all = new TH1F("h_mc_atm_nu_horizontal_mslice_ratio_hits_cher_over_all","cher_hits/all_hits", 100 , 0.0 , 1.0 );
TH1F* h_mc_atm_nu_horizontal_mslice_ratio_hits_trig_cher_over_all = new TH1F("h_mc_atm_nu_horizontal_mslice_ratio_hits_trig_cher_over_all","cher_hits/all_hits", 100 , 0.0 , 1.0 );
TH1F* h_mc_atm_nu_horizontal_mslice_Qup_m_Qdn_JGandalf = new TH1F("h_mc_atm_nu_horizontal_mslice_Qup_m_Qdn_JGandalf","Qup_m_Qdn_JGandalf;Qup-Qdn;", 250 , 0 , 250 );
TH1F* h_mc_atm_nu_horizontal_mslice_max_trig_tot = new TH1F("h_mc_atm_nu_horizontal_mslice_max_trig_tot",";tot [ns];", 100 , 0 , 500 );
TH1F* h_mc_atm_nu_horizontal_mslice_early_trig_10 = new TH1F("h_mc_atm_nu_horizontal_mslice_early_trig_10","", 201 , -0.5 , 200.5 );
TH1F* h_mc_atm_nu_horizontal_mslice_Dn_m_Up_hits = new TH1F("h_mc_atm_nu_horizontal_mslice_Dn_m_Up_hits","Lower_hits_minus_Upper_hits" , 1500 , -500 , 1000);
TH1F* h_mc_atm_nu_horizontal_mslice_Dn_m_Up_trig_hits = new TH1F("h_mc_atm_nu_horizontal_mslice_Dn_m_Up_trig_hits","Lower_hits_minus_Upper_hits_trig" , 1500 , -500 , 1000);
TH1F* h_mc_atm_nu_horizontal_mslice_Dn_m_Up_cher_hits = new TH1F("h_mc_atm_nu_horizontal_mslice_Dn_m_Up_cher_hits","Lower_hits_minus_Upper_hits_cher" , 1500 , -500 , 1000);
TH1F* h_mc_atm_nu_horizontal_mslice_Dn_m_Up_trig_cher_hits = new TH1F("h_mc_atm_nu_horizontal_mslice_Dn_m_Up_trig_cher_hits","Lower_hits_minus_Upper_hits_trig_cher" , 1500 , -500 , 1000);
TH1F* h_mc_atm_nu_horizontal_mslice_diff_energy= new TH1F("h_mc_atm_nu_horizontal_mslice_diff_energy",";(E_true-E_reco)/E_true",100,-1,1);
TH2F* h_mc_atm_nu_horizontal_mslice_diff_energy_cos_zen= new TH2F("h_mc_atm_nu_horizontal_mslice_diff_energy_cos_zen",";zenith [degrees];", 180 , 0.0 , 180.0 , 299 , -2 , 1 );

TH1F* h_mc_atm_nu_horizontal_mslice_le_no_hit_doms = new TH1F("h_mc_atm_nu_horizontal_mslice_le_no_hit_doms","hit DOMs", 108 , 0.5 , 108.5 );
TH1F* h_mc_atm_nu_horizontal_mslice_le_no_cher_doms = new TH1F("h_mc_atm_nu_horizontal_mslice_le_no_cher_doms","Cherenkov doms", 108 , 0.5 , 108.5 );
TH1F* h_mc_atm_nu_horizontal_mslice_le_Nhits = new TH1F("h_mc_atm_nu_horizontal_mslice_le_Nhits",";NHits;", 300 , 0.5 , 300.5 );
TH1F* h_mc_atm_nu_horizontal_mslice_le_beta0 = new TH1F("h_mc_atm_nu_horizontal_mslice_le_beta0",";beta0;",100,0,1);
TH1F* h_mc_atm_nu_horizontal_mslice_le_Qhits = new TH1F("h_mc_atm_nu_horizontal_mslice_le_Qhits",";L/Nhits;",120,0,6);
TH1F* h_mc_atm_nu_horizontal_mslice_le_true_phi = new TH1F("h_mc_atm_nu_horizontal_mslice_le_true_phi",";true_phi;",36,-180,180);
TH1F* h_mc_atm_nu_horizontal_mslice_le_reco_phi = new TH1F("h_mc_atm_nu_horizontal_mslice_le_reco_phi",";reco_phi;",36,-180,180);
TH1F* h_mc_atm_nu_horizontal_mslice_le_bjorken_y = new TH1F("h_mc_atm_nu_horizontal_mslice_le_bjorken_y",";bjorken_y;",100,0,1);
TH1F* h_mc_atm_nu_horizontal_mslice_le_d_closest = new TH1F("h_mc_atm_nu_horizontal_mslice_le_d_closest",";d_closest [m];", 15 , 0 , 150 );
TH1F* h_mc_atm_nu_horizontal_mslice_le_z_closest = new TH1F("h_mc_atm_nu_horizontal_mslice_le_z_closest",";z_closest [m];", 50 , -100 , 400 );
TH1F* h_mc_atm_nu_horizontal_mslice_le_mean_z_hits= new TH1F("h_mc_atm_nu_ mslice_le_mean_z_hits",";vertical position [m];", 160 , -40 , 280 );
TH1F* h_mc_atm_nu_horizontal_mslice_le_reco_vrtx_r = new TH1F("h_mc_atm_nu_horizontal_mslice_le_reco_vrtx_r","reco vrtx radial pos.;r [m];", 40 , 0 , 200 );
TH1F* h_mc_atm_nu_horizontal_mslice_le_trklength = new TH1F("h_mc_atm_nu_horizontal_mslice_le_trklength",";Track Length [m];", 150 , 0 , 300);
TH1F* h_mc_atm_nu_horizontal_mslice_le_zenith = new TH1F("h_mc_atm_nu_horizontal_mslice_le_zenith",";reco zenith [deg]", 180 , 0.0 , 180.0 );
TH1F* h_mc_atm_nu_horizontal_mslice_le_reco_vrtx_z = new TH1F("h_mc_atm_nu_horizontal_mslice_le_reco_vrtx_z","reco vrtx vertical pos.;r [m];", 40 , 0 , 200 );


TH1F* h_mc_atm_nu_horizontal_mslice_me_d_closest = new TH1F("h_mc_atm_nu_horizontal_mslice_me_d_closest",";d_closest [m];", 15 , 0 , 150 );
TH1F* h_mc_atm_nu_horizontal_mslice_me_z_closest = new TH1F("h_mc_atm_nu_horizontal_mslice_me_z_closest",";z_closest [m];", 50 , -100 , 400 );
TH1F* h_mc_atm_nu_horizontal_mslice_me_true_phi = new TH1F("h_mc_atm_nu_horizontal_mslice_me_true_phi",";true_phi;",36,-180,180);
TH1F* h_mc_atm_nu_horizontal_mslice_me_reco_phi = new TH1F("h_mc_atm_nu_horizontal_mslice_me_reco_phi",";reco_phi;",36,-180,180);
TH1F* h_mc_atm_nu_horizontal_mslice_me_bjorken_y = new TH1F("h_mc_atm_nu_horizontal_mslice_me_bjorken_y",";bjorken_y;",100,0,1);
TH1F* h_mc_atm_nu_horizontal_mslice_me_no_hit_doms = new TH1F("h_mc_atm_nu_horizontal_mslice_me_no_hit_doms","hit DOMs", 108 , 0.5 , 108.5 );
TH1F* h_mc_atm_nu_horizontal_mslice_me_no_cher_doms = new TH1F("h_mc_atm_nu_horizontal_mslice_me_no_cher_doms","Cmerenkov doms", 108 , 0.5 , 108.5 );
TH1F* h_mc_atm_nu_horizontal_mslice_me_Nhits = new TH1F("h_mc_atm_nu_horizontal_mslice_me_Nhits",";NHits;", 300 , 0.5 , 300.5 );
TH1F* h_mc_atm_nu_horizontal_mslice_me_beta0 = new TH1F("h_mc_atm_nu_horizontal_mslice_me_beta0",";beta0;",100,0,1);
TH1F* h_mc_atm_nu_horizontal_mslice_me_Qhits = new TH1F("h_mc_atm_nu_horizontal_mslice_me_Qhits",";L/Nhits;",120,0,6);
TH1F* h_mc_atm_nu_horizontal_mslice_me_reco_vrtx_z = new TH1F("h_mc_atm_nu_horizontal_mslice_me_reco_vrtx_z","reco vrtx vertical pos.;r [m];", 40 , 0 , 200 );
TH1F* h_mc_atm_nu_horizontal_mslice_me_zenith = new TH1F("h_mc_atm_nu_horizontal_mslice_me_zenith",";reco zenith [deg]", 180 , 0.0 , 180.0 );
TH2F* h_mc_atm_nu_horizontal_mslice_me_reco_vertex_pos = new TH2F("h_mc_atm_nu_horizontal_mslice_me_reco_vertex_pos",";radial position [m];vertical position [m]", 100, 0 , 100 , 160 , -40 , 280 );
TH1F* h_mc_atm_nu_horizontal_mslice_me_trklength = new TH1F("h_mc_atm_nu_horizontal_mslice_me_trklength",";Track Length [m];", 150 , 0 , 300);
TH1F* h_mc_atm_nu_horizontal_mslice_me_mean_z_hits= new TH1F("h_mc_atm_nu_horizontal_mslice_me_mean_z_hits",";vertical position [m];", 160 , -40 , 280 );
TH1F* h_mc_atm_nu_horizontal_mslice_me_reco_vrtx_r = new TH1F("h_mc_atm_nu_horizontal_mslice_me_reco_vrtx_r","reco vrtx radial pos.;r [m];", 40 , 0 , 200 );


TH1F* h_mc_atm_nu_horizontal_mslice_he_d_closest = new TH1F("h_mc_atm_nu_horizontal_mslice_he_d_closest",";d_closest [m];", 15 , 0 , 150 );
TH1F* h_mc_atm_nu_horizontal_mslice_he_z_closest = new TH1F("h_mc_atm_nu_horizontal_mslice_he_z_closest",";z_closest [m];", 50 , -100 , 400 );
TH1F* h_mc_atm_nu_horizontal_mslice_he_true_phi = new TH1F("h_mc_atm_nu_horizontal_mslice_he_true_phi",";true_phi;",36,-180,180);
TH1F* h_mc_atm_nu_horizontal_mslice_he_reco_phi = new TH1F("h_mc_atm_nu_horizontal_mslice_he_reco_phi",";reco_phi;",36,-180,180);
TH1F* h_mc_atm_nu_horizontal_mslice_he_bjorken_y = new TH1F("h_mc_atm_nu_horizontal_mslice_he_bjorken_y",";bjorken_y;",100,0,1);
TH1F* h_mc_atm_nu_horizontal_mslice_he_no_hit_doms = new TH1F("h_mc_atm_nu_horizontal_mslice_he_no_hit_doms","hit DOMs", 108 , 0.5 , 108.5 );
TH1F* h_mc_atm_nu_horizontal_mslice_he_no_cher_doms = new TH1F("h_mc_atm_nu_horizontal_mslice_he_no_cher_doms","Cherenkov doms", 108 , 0.5 , 108.5 );
TH1F* h_mc_atm_nu_horizontal_mslice_he_Nhits = new TH1F("h_mc_atm_nu_horizontal_mslice_he_Nhits",";NHits;", 300 , 0.5 , 300.5 );
TH1F* h_mc_atm_nu_horizontal_mslice_he_beta0 = new TH1F("h_mc_atm_nu_horizontal_mslice_he_beta0",";beta0;",100,0,1);
TH1F* h_mc_atm_nu_horizontal_mslice_he_Qhits = new TH1F("h_mc_atm_nu_horizontal_mslice_he_Qhits",";L/Nhits;",120,0,6);
TH1F* h_mc_atm_nu_horizontal_mslice_he_reco_vrtx_z = new TH1F("h_mc_atm_nu_horizontal_mslice_he_reco_vrtx_z","reco vrtx vertical pos.;r [m];", 40 , 0 , 200 );
TH1F* h_mc_atm_nu_horizontal_mslice_he_zenith = new TH1F("h_mc_atm_nu_horizontal_mslice_he_zenith",";reco zenith [deg]", 180 , 0.0 , 180.0 );
TH2F* h_mc_atm_nu_horizontal_mslice_he_reco_vertex_pos = new TH2F("h_mc_atm_nu_horizontal_mslice_he_reco_vertex_pos",";radial position [m];vertical position [m]", 100, 0 , 100 , 160 , -40 , 280 );
TH1F* h_mc_atm_nu_horizontal_mslice_he_trklength = new TH1F("h_mc_atm_nu_horizontal_mslice_he_trklength",";Track Length [m];", 150 , 0 , 300);
TH1F* h_mc_atm_nu_horizontal_mslice_he_mean_z_hits= new TH1F("h_mc_atm_nu_mslice_he_mean_z_hits",";vertical position [m];", 160 , -40 , 280 );
TH1F* h_mc_atm_nu_horizontal_mslice_he_reco_vrtx_r = new TH1F("h_mc_atm_nu_horizontal_mslice_he_reco_vrtx_r","reco vrtx radial pos.;r [m];", 40 , 0 , 200 );

//--------------------------------- High Slice --------------------------------------------------
TH1F* h_mc_atm_nu_horizontal_hslice_no_hits = new TH1F("h_mc_atm_nu_horizontal_hslice_no_hits",";# hits;counts;", 1001 , -0.5 , 1000.5 );
TH1F* h_mc_atm_nu_horizontal_hslice_no_hit_doms = new TH1F("h_mc_atm_nu_horizontal_hslice_no_hit_doms","hit DOMs", 108 , 0.5 , 108.5 );
TH1F* h_mc_atm_nu_horizontal_hslice_no_trig_hits = new TH1F("h_mc_atm_nu_horizontal_hslice_no_trig_hits",";# hits;counts;", 1001 , -0.5 , 1000.5 );
TH1F* h_mc_atm_nu_horizontal_hslice_no_trig_doms = new TH1F("h_mc_atm_nu_horizontal_hslice_no_trig_doms","triggered DOMs", 108 , 0.5 , 108.5 );
TH1F* h_mc_atm_nu_horizontal_hslice_no_cher_hits = new TH1F("h_mc_atm_nu_horizontal_hslice_no_cher_hits","Cherenkov hits", 1001 , -0.5 , 1000.5 );
TH1F* h_mc_atm_nu_horizontal_hslice_no_cher_doms = new TH1F("h_mc_atm_nu_horizontal_hslice_no_cher_doms","Cherenkov doms", 108 , 0.5 , 108.5 );
TH1F* h_mc_atm_nu_horizontal_hslice_no_trig_cher_doms = new TH1F("h_mc_atm_nu_horizontal_hslice_no_trig_cher_doms","Trig & Cherenkov doms", 72 , 0.5 , 72.5 );
TH1F* h_mc_atm_nu_horizontal_hslice_no_trig_dus = new TH1F("h_mc_atm_nu_horizontal_hslice_no_trig_dus"," DUs", 6 , 0.5 , 6.5 );
TH1F* h_mc_atm_nu_horizontal_hslice_no_cher_dus = new TH1F("h_mc_atm_nu_horizontal_hslice_no_cher_dus"," DUs", 6 , 0.5 , 6.5 );
TH1F* h_mc_atm_nu_horizontal_hslice_no_trig_cher_dus = new TH1F("h_mc_atm_nu_horizontal_hslice_no_trig_cher_dus"," DUs", 6 , 0.5 , 6.5 );
TH1F* h_mc_atm_nu_horizontal_hslice_no_trig_cher_hits = new TH1F("h_mc_atm_nu_horizontal_hslice_no_trig_cher_hits","Trig & Cherenkov hits", 1001 , -0.5 , 1000.5 );
TH1F* h_mc_atm_nu_horizontal_hslice_zenith = new TH1F("h_mc_atm_nu_horizontal_hslice_zenith",";reco zenith [deg]", 180 , 0.0 , 180.0 );
TH1F* h_mc_atm_nu_horizontal_hslice_true_zenith = new TH1F("h_mc_atm_nu_horizontal_hslice_true_zenith",";true zenith [deg]", 180 , 0.0 , 180.0 );
TH1F* h_mc_atm_nu_horizontal_hslice_cos_zenith = new TH1F("h_mc_atm_nu_horizontal_hslice_cos_zen",";cos(reco zenith)", 100 , -1.0 , 1.0 );
TH1F* h_mc_atm_nu_horizontal_hslice_true_cos_zen = new TH1F("h_mc_atm_nu_horizontal_hslice_true_cos_zen",";cos(reco zenith)", 100 , -1.0 , 1.0 );
TH1F* h_mc_atm_nu_horizontal_hslice_max_lik_dist = new TH1F("h_mc_atm_nu_horizontal_hslice_max_lik",";L;", 100 , 0 , 2000 );
TH1F* h_mc_atm_nu_horizontal_hslice_log_lik_dist = new TH1F("h_mc_atm_nu_horizontal_hslice_log_lik",";log(L);", 100 , -1.0 , 4.0 );
TH1F* h_mc_atm_nu_horizontal_hslice_true_energy_no_log = new TH1F("h_mc_atm_nu_horizontal_hslice_true_energy_no_log", ";True Energy (GeV);",500,0,5000);
TH1F* h_mc_atm_nu_horizontal_hslice_true_energy = new TH1F("h_mc_atm_nu_horizontal_hslice_true_energy",";log[true/GeV];", 40 , 0 , 4.0 );
TH1F* h_mc_atm_nu_horizontal_hslice_reco_energy = new TH1F("h_mc_atm_nu_horizontal_hslice_reco_energy",";log[E_reco/GeV];", 40 , 0 , 4.0 );
TH2F* h_mc_atm_nu_horizontal_hslice_reco_vertex_pos = new TH2F("h_mc_atm_nu_horizontal_hslice_reco_vertex_pos",";radial position [m];vertical position [m]", 100, 0 , 100 , 160 , -40 , 280 );
TH1F* h_mc_atm_nu_horizontal_hslice_reco_vrtx_r = new TH1F("h_mc_atm_nu_horizontal_hslice_reco_vrtx_r","reco vrtx radial pos.;r [m];", 40 , 0 , 200 );
TH1F* h_mc_atm_nu_horizontal_hslice_reco_vrtx_x = new TH1F("h_mc_atm_nu_horizontal_hslice_reco_vrtx_x","reco vrtx x pos.;x [m];", 40 , 0 , 200 );
TH1F* h_mc_atm_nu_horizontal_hslice_reco_vrtx_y = new TH1F("h_mc_atm_nu_horizontal_hslice_reco_vrtx_y","reco vrtx y pos.;y [m];", 40 , 0 , 200 );
TH1F* h_mc_atm_nu_horizontal_hslice_reco_vrtx_z = new TH1F("h_mc_atm_nu_horizontal_hslice_reco_vrtx_z","reco vrtx z pos.;z [m];", 40 , 0 , 200 );
TH1F* h_mc_atm_nu_horizontal_hslice_Nhits = new TH1F("h_mc_atm_nu_horizontal_hslice_Nhits",";NHits;", 300 , 0.5 , 300.5 );
TH1F* h_mc_atm_nu_horizontal_hslice_beta0 = new TH1F("h_mc_atm_nu_horizontal_hslice_beta0",";beta0;",100,0,1);
TH1F* h_mc_atm_nu_horizontal_hslice_Qhits = new TH1F("h_mc_atm_nu_horizontal_hslice_Qhits",";L/Nhits;",120,0,6);
TH1F* h_mc_atm_nu_horizontal_hslice_trklength = new TH1F("h_mc_atm_nu_horizontal_hslice_trklength",";Track Length [m];", 150 , 0 , 300);
TH1F* h_mc_atm_nu_horizontal_hslice_d_closest = new TH1F("h_mc_atm_nu_horizontal_hslice_d_closest",";d_closest [m];", 15 , 0 , 150 );
TH1F* h_mc_atm_nu_horizontal_hslice_z_closest = new TH1F("h_mc_atm_nu_horizontal_hslice_z_closest",";z_closest [m];", 50 , -100 , 400 );
TH1F* h_mc_atm_nu_horizontal_hslice_mean_z_hits = new TH1F("h_mc_atm_nu_horizontal_hslice_mean_z_hits",";vertical position [m];", 160 , -40 , 280 );
TH1F* h_mc_atm_nu_horizontal_hslice_mean_z_trig_hits = new TH1F("h_mc_atm_nu_horizontal_hslice_mean_z_trig_hits",";vertical position [m];", 160 , -40 , 280 );
TH1F* h_mc_atm_nu_horizontal_hslice_mean_z_cher_hits = new TH1F("h_mc_atm_nu_horizontal_hslice_mean_z_cher_hits",";vertical position [m];", 160 , -40 , 280 );
TH1F* h_mc_atm_nu_horizontal_hslice_mean_z_trig_cher_hits = new TH1F("h_mc_atm_nu_horizontal_hslice_mean_z_trig_cher_hits",";vertical position [m];", 160 , -40 , 280 );
TH1F* h_mc_atm_nu_horizontal_hslice_ratio_hits_trig_over_all = new TH1F("h_mc_atm_nu_horizontal_hslice_ratio_hits_trig_over_all","trig_hits/all_hits", 100 , 0.0 , 1.0 );
TH1F* h_mc_atm_nu_horizontal_hslice_ratio_hits_cher_over_all = new TH1F("h_mc_atm_nu_horizontal_hslice_ratio_hits_cher_over_all","cher_hits/all_hits", 100 , 0.0 , 1.0 );
TH1F* h_mc_atm_nu_horizontal_hslice_ratio_hits_trig_cher_over_all = new TH1F("h_mc_atm_nu_horizontal_hslice_ratio_hits_trig_cher_over_all","cher_hits/all_hits", 100 , 0.0 , 1.0 );
TH1F* h_mc_atm_nu_horizontal_hslice_Qup_m_Qdn_JGandalf = new TH1F("h_mc_atm_nu_horizontal_hslice_Qup_m_Qdn_JGandalf","Qup_m_Qdn_JGandalf;Qup-Qdn;", 250 , 0 , 250 );
TH1F* h_mc_atm_nu_horizontal_hslice_max_trig_tot = new TH1F("h_mc_atm_nu_horizontal_hslice_max_trig_tot",";tot [ns];", 100 , 0 , 500 );
TH1F* h_mc_atm_nu_horizontal_hslice_early_trig_10 = new TH1F("h_mc_atm_nu_horizontal_hslice_early_trig_10","", 201 , -0.5 , 200.5 );
TH1F* h_mc_atm_nu_horizontal_hslice_Dn_m_Up_hits = new TH1F("h_mc_atm_nu_horizontal_hslice_Dn_m_Up_hits","Lower_hits_minus_Upper_hits" , 1500 , -500 , 1000);
TH1F* h_mc_atm_nu_horizontal_hslice_Dn_m_Up_trig_hits = new TH1F("h_mc_atm_nu_horizontal_hslice_Dn_m_Up_trig_hits","Lower_hits_minus_Upper_hits_trig" , 1500 , -500 , 1000);
TH1F* h_mc_atm_nu_horizontal_hslice_Dn_m_Up_cher_hits = new TH1F("h_mc_atm_nu_horizontal_hslice_Dn_m_Up_cher_hits","Lower_hits_minus_Upper_hits_cher" , 1500 , -500 , 1000);
TH1F* h_mc_atm_nu_horizontal_hslice_Dn_m_Up_trig_cher_hits = new TH1F("h_mc_atm_nu_horizontal_hslice_Dn_m_Up_trig_cher_hits","Lower_hits_minus_Upper_hits_trig_cher" , 1500 , -500 , 1000);
TH1F* h_mc_atm_nu_horizontal_hslice_diff_energy= new TH1F("h_mc_atm_nu_horizontal_hslice_diff_energy",";(E_true-E_reco)/E_true",100,-1,1);
TH2F* h_mc_atm_nu_horizontal_hslice_diff_energy_cos_zen= new TH2F("h_mc_atm_nu_horizontal_hslice_diff_energy_cos_zen",";zenith [degrees];", 180 , 0.0 , 180.0 , 299 , -2 , 1 );

TH1F* h_mc_atm_nu_horizontal_hslice_le_no_hit_doms = new TH1F("h_mc_atm_nu_horizontal_hslice_le_no_hit_doms","hit DOMs", 108 , 0.5 , 108.5 );
TH1F* h_mc_atm_nu_horizontal_hslice_le_no_cher_doms = new TH1F("h_mc_atm_nu_horizontal_hslice_le_no_cher_doms","Cherenkov doms", 108 , 0.5 , 108.5 );
TH1F* h_mc_atm_nu_horizontal_hslice_le_Nhits = new TH1F("h_mc_atm_nu_horizontal_hslice_le_Nhits",";NHits;", 300 , 0.5 , 300.5 );
TH1F* h_mc_atm_nu_horizontal_hslice_le_beta0 = new TH1F("h_mc_atm_nu_horizontal_hslice_le_beta0",";beta0;",100,0,1);
TH1F* h_mc_atm_nu_horizontal_hslice_le_Qhits = new TH1F("h_mc_atm_nu_horizontal_hslice_le_Qhits",";L/Nhits;",120,0,6);
TH1F* h_mc_atm_nu_horizontal_hslice_le_true_phi = new TH1F("h_mc_atm_nu_horizontal_hslice_le_true_phi",";true_phi;",36,-180,180);
TH1F* h_mc_atm_nu_horizontal_hslice_le_reco_phi = new TH1F("h_mc_atm_nu_horizontal_hslice_le_reco_phi",";reco_phi;",36,-180,180);
TH1F* h_mc_atm_nu_horizontal_hslice_le_bjorken_y = new TH1F("h_mc_atm_nu_horizontal_hslice_le_bjorken_y",";bjorken_y;",100,0,1);
TH1F* h_mc_atm_nu_horizontal_hslice_le_d_closest = new TH1F("h_mc_atm_nu_horizontal_hslice_le_d_closest",";d_closest [m];", 15 , 0 , 150 );
TH1F* h_mc_atm_nu_horizontal_hslice_le_z_closest = new TH1F("h_mc_atm_nu_horizontal_hslice_le_z_closest",";z_closest [m];", 50 , -100 , 400 );
TH1F* h_mc_atm_nu_horizontal_hslice_le_mean_z_hits= new TH1F("h_mc_atm_nu_ hslice_le_mean_z_hits",";vertical position [m];", 160 , -40 , 280 );
TH1F* h_mc_atm_nu_horizontal_hslice_le_reco_vrtx_r = new TH1F("h_mc_atm_nu_horizontal_hslice_le_reco_vrtx_r","reco vrtx radial pos.;r [m];", 40 , 0 , 200 );
TH1F* h_mc_atm_nu_horizontal_hslice_le_trklength = new TH1F("h_mc_atm_nu_horizontal_hslice_le_trklength",";Track Length [m];", 150 , 0 , 300);
TH1F* h_mc_atm_nu_horizontal_hslice_le_zenith = new TH1F("h_mc_atm_nu_horizontal_hslice_le_zenith",";reco zenith [deg]", 180 , 0.0 , 180.0 );
TH1F* h_mc_atm_nu_horizontal_hslice_le_reco_vrtx_z = new TH1F("h_mc_atm_nu_horizontal_hslice_le_reco_vrtx_z","reco vrtx vertical pos.;r [m];", 40 , 0 , 200 );

TH1F* h_mc_atm_nu_horizontal_hslice_he_d_closest = new TH1F("h_mc_atm_nu_horizontal_hslice_he_d_closest",";d_closest [m];", 15 , 0 , 150 );
TH1F* h_mc_atm_nu_horizontal_hslice_he_z_closest = new TH1F("h_mc_atm_nu_horizontal_hslice_he_z_closest",";z_closest [m];", 50 , -100 , 400 );
TH1F* h_mc_atm_nu_horizontal_hslice_he_true_phi = new TH1F("h_mc_atm_nu_horizontal_hslice_he_true_phi",";true_phi;",36,-180,180);
TH1F* h_mc_atm_nu_horizontal_hslice_he_reco_phi = new TH1F("h_mc_atm_nu_horizontal_hslice_he_reco_phi",";reco_phi;",36,-180,180);
TH1F* h_mc_atm_nu_horizontal_hslice_he_bjorken_y = new TH1F("h_mc_atm_nu_horizontal_hslice_he_bjorken_y",";bjorken_y;",100,0,1);
TH1F* h_mc_atm_nu_horizontal_hslice_he_no_hit_doms = new TH1F("h_mc_atm_nu_horizontal_hslice_he_no_hit_doms","hit DOMs", 108 , 0.5 , 108.5 );
TH1F* h_mc_atm_nu_horizontal_hslice_he_no_cher_doms = new TH1F("h_mc_atm_nu_horizontal_hslice_he_no_cher_doms","Cherenkov doms", 108 , 0.5 , 108.5 );
TH1F* h_mc_atm_nu_horizontal_hslice_he_Nhits = new TH1F("h_mc_atm_nu_horizontal_hslice_he_Nhits",";NHits;", 300 , 0.5 , 300.5 );
TH1F* h_mc_atm_nu_horizontal_hslice_he_beta0 = new TH1F("h_mc_atm_nu_horizontal_hslice_he_beta0",";beta0;",100,0,1);
TH1F* h_mc_atm_nu_horizontal_hslice_he_Qhits = new TH1F("h_mc_atm_nu_horizontal_hslice_he_Qhits",";L/Nhits;",120,0,6);
TH1F* h_mc_atm_nu_horizontal_hslice_he_reco_vrtx_z = new TH1F("h_mc_atm_nu_horizontal_hslice_he_reco_vrtx_z","reco vrtx vertical pos.;r [m];", 40 , 0 , 200 );
TH1F* h_mc_atm_nu_horizontal_hslice_he_zenith = new TH1F("h_mc_atm_nu_horizontal_hslice_he_zenith",";reco zenith [deg]", 180 , 0.0 , 180.0 );
TH2F* h_mc_atm_nu_horizontal_hslice_he_reco_vertex_pos = new TH2F("h_mc_atm_nu_horizontal_hslice_he_reco_vertex_pos",";radial position [m];vertical position [m]", 100, 0 , 100 , 160 , -40 , 280 );
TH1F* h_mc_atm_nu_horizontal_hslice_he_trklength = new TH1F("h_mc_atm_nu_horizontal_hslice_he_trklength",";Track Length [m];", 150 , 0 , 300);
TH1F* h_mc_atm_nu_horizontal_hslice_he_mean_z_hits= new TH1F("h_mc_atm_nu_hslice_he_mean_z_hits",";vertical position [m];", 160 , -40 , 280 );
TH1F* h_mc_atm_nu_horizontal_hslice_he_reco_vrtx_r = new TH1F("h_mc_atm_nu_horizontal_hslice_he_reco_vrtx_r","reco vrtx radial pos.;r [m];", 40 , 0 , 200 );





//For the upgoing 
TH1F* h_mc_atm_nu_upgoing_no_hits = new TH1F("h_mc_atm_nu_upgoing_no_hits",";# hits;counts;", 1001 , -0.5 , 1000.5 );
TH1F* h_mc_atm_nu_upgoing_no_hit_doms = new TH1F("h_mc_atm_nu_upgoing_no_hit_doms","hit DOMs", 108 , 0.5 , 108.5 );
TH1F* h_mc_atm_nu_upgoing_no_trig_hits = new TH1F("h_mc_atm_nu_upgoing_no_trig_hits",";# hits;counts;", 1001 , -0.5 , 1000.5 );
TH1F* h_mc_atm_nu_upgoing_no_trig_doms = new TH1F("h_mc_atm_nu_upgoing_no_trig_doms","triggered DOMs", 108 , 0.5 , 108.5 );
TH1F* h_mc_atm_nu_upgoing_no_cher_hits = new TH1F("h_mc_atm_nu_upgoing_no_cher_hits","Cherenkov hits", 1001 , -0.5 , 1000.5 );
TH1F* h_mc_atm_nu_upgoing_no_cher_doms = new TH1F("h_mc_atm_nu_upgoing_no_cher_doms","Cherenkov doms", 108 , 0.5 , 108.5 );
TH1F* h_mc_atm_nu_upgoing_no_trig_cher_doms = new TH1F("h_mc_atm_nu_upgoing_no_trig_cher_doms","Trig & Cherenkov doms", 72 , 0.5 , 72.5 );
TH1F* h_mc_atm_nu_upgoing_no_trig_dus = new TH1F("h_mc_atm_nu_upgoing_no_trig_dus"," DUs", 6 , 0.5 , 6.5 );
TH1F* h_mc_atm_nu_upgoing_no_cher_dus = new TH1F("h_mc_atm_nu_upgoing_no_cher_dus"," DUs", 6 , 0.5 , 6.5 );
TH1F* h_mc_atm_nu_upgoing_no_trig_cher_dus = new TH1F("h_mc_atm_nu_upgoing_no_trig_cher_dus"," DUs", 6 , 0.5 , 6.5 );
TH1F* h_mc_atm_nu_upgoing_no_trig_cher_hits = new TH1F("h_mc_atm_nu_upgoing_no_trig_cher_hits","Trig & Cherenkov hits", 1001 , -0.5 , 1000.5 );
TH1F* h_mc_atm_nu_upgoing_zenith = new TH1F("h_mc_atm_nu_upgoing_zenith",";reco zenith [deg]", 180 , 0.0 , 180.0 );
TH1F* h_mc_atm_nu_upgoing_true_zenith = new TH1F("h_mc_atm_nu_upgoing_true_zenith",";true zenith [deg]", 180 , 0.0 , 180.0 );
TH1F* h_mc_atm_nu_upgoing_cos_zenith = new TH1F("h_mc_atm_nu_upgoing_cos_zen",";cos(reco zenith)", 100 , -1.0 , 1.0 );
TH1F* h_mc_atm_nu_upgoing_true_cos_zen = new TH1F("h_mc_atm_nu_upgoing_true_cos_zen",";cos(reco zenith)", 100 , -1.0 , 1.0 );
TH1F* h_mc_atm_nu_upgoing_max_lik_dist = new TH1F("h_mc_atm_nu_upgoing_max_lik",";L;", 100 , 0 , 2000 );
TH1F* h_mc_atm_nu_upgoing_log_lik_dist = new TH1F("h_mc_atm_nu_upgoing_log_lik",";log(L);", 100 , -1.0 , 4.0 );
TH1F* h_mc_atm_nu_upgoing_true_energy_no_log = new TH1F("h_mc_atm_nu_upgoing_true_energy_no_log", ";True Energy (GeV);",500,0,5000);
TH1F* h_mc_atm_nu_upgoing_true_energy = new TH1F("h_mc_atm_nu_upgoing_true_energy",";log[true/GeV];", 40 , 0 , 4.0 );
TH1F* h_mc_atm_nu_upgoing_reco_energy = new TH1F("h_mc_atm_nu_upgoing_reco_energy",";log[E_reco/GeV];", 40 , 0 , 4.0 );
TH1F* h_mc_atm_nu_upgoing_Nhits = new TH1F("h_mc_atm_nu_upgoing_Nhits",";NHits;", 300 , 0.5 , 300.5 ); 
TH2F* h_mc_atm_nu_upgoing_E_reco_E_true_rec_zen_all = new TH2F("h_mc_atm_nu_upgoing_E_reco_E_true_rec_zen_all",";log[E_true/GeV];log[E_reco/GeV]", 300 , 0 , 4.0 , 300 , 0 , 4.0 );
TH2F* h_mc_atm_nu_upgoing_E_reco_E_true_rec_zen_30_all = new TH2F("h_mc_atm_nu_upgoing_E_reco_E_true_rec_zen_30_all",";log[E_true/GeV];log[E_reco/GeV]", 300 , 0 , 4.0 , 300 , 0 , 4.0 );
TH2F* h_mc_atm_nu_upgoing_E_reco_E_true_rec_zen_120_all = new TH2F("h_mc_atm_nu_upgoing_E_reco_E_true_rec_zen_120_all",";log[E_true/GeV];log[E_reco/GeV]", 300 , 0 , 4.0 , 300 , 0 , 4.0 );
TH2F* h_mc_atm_nu_upgoing_E_reco_E_true_rec_zen_150_all = new TH2F("h_mc_atm_nu_upgoing_E_reco_E_true_rec_zen_150_all",";log[E_true/GeV];log[E_reco/GeV]",300 , 0 , 4.0 , 300 , 0 , 4.0 );
TH2F* h_mc_atm_nu_upgoing_reco_vertex_pos = new TH2F("h_mc_atm_nu_upgoing_reco_vertex_pos",";radial position [m];vertical position [m]", 100, 0 , 100 , 160 , -40 , 280 );
TH1F* h_mc_atm_nu_upgoing_reco_vrtx_r = new TH1F("h_mc_atm_nu_upgoing_reco_vrtx_r","reco vrtx radial pos.;r [m];", 40 , 0 , 200 );
TH1F* h_mc_atm_nu_upgoing_reco_vrtx_x = new TH1F("h_mc_atm_nu_upgoing_reco_vrtx_x","reco vrtx x pos.;x [m];", 40 , 0 , 200 );
TH1F* h_mc_atm_nu_upgoing_reco_vrtx_y = new TH1F("h_mc_atm_nu_upgoing_reco_vrtx_y","reco vrtx y pos.;y [m];", 40 , 0 , 200 );
TH1F* h_mc_atm_nu_upgoing_reco_vrtx_z = new TH1F("h_mc_atm_nu_upgoing_reco_vrtx_z","reco vrtx z pos.;z [m];", 40 , 0 , 200 ); 
TH1F* h_mc_atm_nu_upgoing_beta0 = new TH1F("h_mc_atm_nu_upgoing_beta0",";beta0;",100,0,1);
TH1F* h_mc_atm_nu_upgoing_Qhits = new TH1F("h_mc_atm_nu_upgoing_Qhits",";L/Nhits;",120,0,6);
TH1F* h_mc_atm_nu_upgoing_trklength = new TH1F("h_mc_atm_nu_upgoing_trklength","", 150 , 0 , 300);
TH1F* h_mc_atm_nu_upgoing_d_closest = new TH1F("h_mc_atm_nu_upgoing_d_closest",";d_closest [m];", 15 , 0 , 150 );
TH1F* h_mc_atm_nu_upgoing_z_closest = new TH1F("h_mc_atm_nu_upgoing_z_closest",";z_closest [m];", 50 , -100 , 400 );
TH1F* h_mc_atm_nu_upgoing_mean_z_hits = new TH1F("h_mc_atm_nu_upgoing_mean_z_hits",";vertical position [m];", 160 , -40 , 280 );
TH1F* h_mc_atm_nu_upgoing_mean_z_trig_hits = new TH1F("h_mc_atm_nu_upgoing_mean_z_trig_hits",";vertical position [m];", 160 , -40 , 280 );
TH1F* h_mc_atm_nu_upgoing_mean_z_cher_hits = new TH1F("h_mc_atm_nu_upgoing_mean_z_cher_hits",";vertical position [m];", 160 , -40 , 280 );
TH1F* h_mc_atm_nu_upgoing_mean_z_trig_cher_hits = new TH1F("h_mc_atm_nu_upgoing_mean_z_trig_cher_hits",";vertical position [m];", 160 , -40 , 280 );
TH1F* h_mc_atm_nu_upgoing_ratio_hits_trig_over_all = new TH1F("h_mc_atm_nu_upgoing_ratio_hits_trig_over_all","trig_hits/all_hits", 100 , 0.0 , 1.0 );
TH1F* h_mc_atm_nu_upgoing_ratio_hits_cher_over_all = new TH1F("h_mc_atm_nu_upgoing_ratio_hits_cher_over_all","cher_hits/all_hits", 100 , 0.0 , 1.0 );
TH1F* h_mc_atm_nu_upgoing_ratio_hits_trig_cher_over_all = new TH1F("h_mc_atm_nu_upgoing_ratio_hits_trig_cher_over_all","cher_hits/all_hits", 100 , 0.0 , 1.0 );
TH1F* h_mc_atm_nu_upgoing_Qup_m_Qdn_JGandalf = new TH1F("h_mc_atm_nu_upgoing_Qup_m_Qdn_JGandalf","Qup_m_Qdn_JGandalf;Qup-Qdn;", 250 , 0 , 250 );
TH1F* h_mc_atm_nu_upgoing_max_trig_tot = new TH1F("h_mc_atm_nu_upgoing_max_trig_tot",";tot [ns];", 100 , 0 , 500 );
TH1F* h_mc_atm_nu_upgoing_early_trig_10 = new TH1F("h_mc_atm_nu_upgoing_early_trig_10","", 201 , -0.5 , 200.5 );
TH1F* h_mc_atm_nu_upgoing_Dn_m_Up_hits = new TH1F("h_mc_atm_nu_upgoing_Dn_m_Up_hits","Lower_hits_minus_Upper_hits" , 1500 , -500 , 1000);
TH1F* h_mc_atm_nu_upgoing_Dn_m_Up_trig_hits = new TH1F("h_mc_atm_nu_upgoing_Dn_m_Up_trig_hits","Lower_hits_minus_Upper_hits_trig" , 1500 , -500 , 1000);
TH1F* h_mc_atm_nu_upgoing_Dn_m_Up_cher_hits = new TH1F("h_mc_atm_nu_upgoing_Dn_m_Up_cher_hits","Lower_hits_minus_Upper_hits_cher" , 1500 , -500 , 1000);
TH1F* h_mc_atm_nu_upgoing_Dn_m_Up_trig_cher_hits = new TH1F("h_mc_atm_nu_upgoing_Dn_m_Up_trig_cher_hits","Lower_hits_minus_Upper_hits_trig_cher" , 1500 , -500 , 1000);
TH1F* h_mc_atm_nu_upgoing_diff_energy= new TH1F("h_mc_atm_nu_upgoing_diff_energy",";(E_true-E_reco)/E_true",100,-1,1);
TH2F* h_mc_atm_nu_upgoing_diff_energy_cos_zen= new TH2F("h_mc_atm_nu_upgoing_diff_energy_cos_zen",";zenith [degrees];", 180 , 0.0 , 180.0 , 299 , -2 , 1 );
TH2F* h_mc_atm_nu_upgoing_E_true_zenith_upgoing= new TH2F("h_mc_atm_nu_upgoing_E_true_zenith_upgoing",";zenith [degrees];",30 , 150.0 , 180 , 300 , 0 ,4);
TH2F* h_mc_atm_nu_upgoing_E_true_zenith_horizontal= new TH2F("h_mc_atm_nu_upgoing_E_true_zenith_horizontal",";zenith [degrees];",30 , 0.0 , 30 , 300 , 0 ,4);

//------------------------------- Energy Slices -------------------------------------------------
//-------------------------------- Low Slice ----------------------------------------------------
TH1F* h_mc_atm_nu_upgoing_lslice_no_hits = new TH1F("h_mc_atm_nu_upgoing_lslice_no_hits",";# hits;counts;", 1001 , -0.5 , 1000.5 );
TH1F* h_mc_atm_nu_upgoing_lslice_no_hit_doms = new TH1F("h_mc_atm_nu_upgoing_lslice_no_hit_doms","hit DOMs", 108 , 0.5 , 108.5 );
TH1F* h_mc_atm_nu_upgoing_lslice_no_trig_hits = new TH1F("h_mc_atm_nu_upgoing_lslice_no_trig_hits",";# hits;counts;", 1001 , -0.5 , 1000.5 );
TH1F* h_mc_atm_nu_upgoing_lslice_no_trig_doms = new TH1F("h_mc_atm_nu_upgoing_lslice_no_trig_doms","triggered DOMs", 108 , 0.5 , 108.5 );
TH1F* h_mc_atm_nu_upgoing_lslice_no_cher_hits = new TH1F("h_mc_atm_nu_upgoing_lslice_no_cher_hits","Cherenkov hits", 1001 , -0.5 , 1000.5 );
TH1F* h_mc_atm_nu_upgoing_lslice_no_cher_doms = new TH1F("h_mc_atm_nu_upgoing_lslice_no_cher_doms","Cherenkov doms", 108 , 0.5 , 108.5 );
TH1F* h_mc_atm_nu_upgoing_lslice_no_trig_cher_doms = new TH1F("h_mc_atm_nu_upgoing_lslice_no_trig_cher_doms","Trig & Cherenkov doms", 72 , 0.5 , 72.5 );
TH1F* h_mc_atm_nu_upgoing_lslice_no_trig_dus = new TH1F("h_mc_atm_nu_upgoing_lslice_no_trig_dus"," DUs", 6 , 0.5 , 6.5 );
TH1F* h_mc_atm_nu_upgoing_lslice_no_cher_dus = new TH1F("h_mc_atm_nu_upgoing_lslice_no_cher_dus"," DUs", 6 , 0.5 , 6.5 );
TH1F* h_mc_atm_nu_upgoing_lslice_no_trig_cher_dus = new TH1F("h_mc_atm_nu_upgoing_lslice_no_trig_cher_dus"," DUs", 6 , 0.5 , 6.5 );
TH1F* h_mc_atm_nu_upgoing_lslice_no_trig_cher_hits = new TH1F("h_mc_atm_nu_upgoing_lslice_no_trig_cher_hits","Trig & Cherenkov hits", 1001 , -0.5 , 1000.5 );
TH1F* h_mc_atm_nu_upgoing_lslice_zenith = new TH1F("h_mc_atm_nu_upgoing_lslice_zenith",";reco zenith [deg]", 180 , 0.0 , 180.0 );
TH1F* h_mc_atm_nu_upgoing_lslice_true_zenith = new TH1F("h_mc_atm_nu_upgoing_lslice_true_zenith",";true zenith [deg]", 180 , 0.0 , 180.0 );
TH1F* h_mc_atm_nu_upgoing_lslice_cos_zenith = new TH1F("h_mc_atm_nu_upgoing_lslice_cos_zen",";cos(reco zenith)", 100 , -1.0 , 1.0 );
TH1F* h_mc_atm_nu_upgoing_lslice_true_cos_zen = new TH1F("h_mc_atm_nu_upgoing_lslice_true_cos_zen",";cos(reco zenith)", 100 , -1.0 , 1.0 );
TH1F* h_mc_atm_nu_upgoing_lslice_max_lik_dist = new TH1F("h_mc_atm_nu_upgoing_lslice_max_lik",";L;", 100 , 0 , 2000 );
TH1F* h_mc_atm_nu_upgoing_lslice_log_lik_dist = new TH1F("h_mc_atm_nu_upgoing_lslice_log_lik",";log(L);", 100 , -1.0 , 4.0 );
TH1F* h_mc_atm_nu_upgoing_lslice_true_energy_no_log = new TH1F("h_mc_atm_nu_upgoing_lslice_true_energy_no_log", ";True Energy (GeV);",500,0,5000);
TH1F* h_mc_atm_nu_upgoing_lslice_true_energy = new TH1F("h_mc_atm_nu_upgoing_lslice_true_energy",";log[true/GeV];", 40 , 0 , 4.0 );
TH1F* h_mc_atm_nu_upgoing_lslice_reco_energy = new TH1F("h_mc_atm_nu_upgoing_lslice_reco_energy",";log[E_reco/GeV];", 40 , 0 , 4.0 );
TH2F* h_mc_atm_nu_upgoing_lslice_reco_vertex_pos = new TH2F("h_mc_atm_nu_upgoing_lslice_reco_vertex_pos",";radial position [m];vertical position [m]", 100, 0 , 100 , 160 , -40 , 280 );
TH1F* h_mc_atm_nu_upgoing_lslice_reco_vrtx_r = new TH1F("h_mc_atm_nu_upgoing_lslice_reco_vrtx_r","reco vrtx radial pos.;r [m];", 40 , 0 , 200 );
TH1F* h_mc_atm_nu_upgoing_lslice_reco_vrtx_x = new TH1F("h_mc_atm_nu_upgoing_lslice_reco_vrtx_x","reco vrtx x pos.;x [m];", 40 , 0 , 200 );
TH1F* h_mc_atm_nu_upgoing_lslice_reco_vrtx_y = new TH1F("h_mc_atm_nu_upgoing_lslice_reco_vrtx_y","reco vrtx y pos.;y [m];", 40 , 0 , 200 );
TH1F* h_mc_atm_nu_upgoing_lslice_reco_vrtx_z = new TH1F("h_mc_atm_nu_upgoing_lslice_reco_vrtx_z","reco vrtx z pos.;z [m];", 40 , 0 , 200 );
TH1F* h_mc_atm_nu_upgoing_lslice_Nhits = new TH1F("h_mc_atm_nu_upgoing_lslice_Nhits",";NHits;", 300 , 0.5 , 300.5 );
TH1F* h_mc_atm_nu_upgoing_lslice_beta0 = new TH1F("h_mc_atm_nu_upgoing_lslice_beta0",";beta0;",100,0,1);
TH1F* h_mc_atm_nu_upgoing_lslice_Qhits = new TH1F("h_mc_atm_nu_upgoing_lslice_Qhits",";L/Nhits;",120,0,6);
TH1F* h_mc_atm_nu_upgoing_lslice_trklength = new TH1F("h_mc_atm_nu_upgoing_lslice_trklength",";Track Length [m];", 150 , 0 , 300);
TH1F* h_mc_atm_nu_upgoing_lslice_d_closest = new TH1F("h_mc_atm_nu_upgoing_lslice_d_closest",";d_closest [m];", 15 , 0 , 150 );
TH1F* h_mc_atm_nu_upgoing_lslice_z_closest = new TH1F("h_mc_atm_nu_upgoing_lslice_z_closest",";z_closest [m];", 50 , -100 , 400 );
TH1F* h_mc_atm_nu_upgoing_lslice_mean_z_hits = new TH1F("h_mc_atm_nu_upgoing_lslice_mean_z_hits",";vertical position [m];", 160 , -40 , 280 );
TH1F* h_mc_atm_nu_upgoing_lslice_mean_z_trig_hits = new TH1F("h_mc_atm_nu_upgoing_lslice_mean_z_trig_hits",";vertical position [m];", 160 , -40 , 280 );
TH1F* h_mc_atm_nu_upgoing_lslice_mean_z_cher_hits = new TH1F("h_mc_atm_nu_upgoing_lslice_mean_z_cher_hits",";vertical position [m];", 160 , -40 , 280 );
TH1F* h_mc_atm_nu_upgoing_lslice_mean_z_trig_cher_hits = new TH1F("h_mc_atm_nu_upgoing_lslice_mean_z_trig_cher_hits",";vertical position [m];", 160 , -40 , 280 );
TH1F* h_mc_atm_nu_upgoing_lslice_ratio_hits_trig_over_all = new TH1F("h_mc_atm_nu_upgoing_lslice_ratio_hits_trig_over_all","trig_hits/all_hits", 100 , 0.0 , 1.0 );
TH1F* h_mc_atm_nu_upgoing_lslice_ratio_hits_cher_over_all = new TH1F("h_mc_atm_nu_upgoing_lslice_ratio_hits_cher_over_all","cher_hits/all_hits", 100 , 0.0 , 1.0 );
TH1F* h_mc_atm_nu_upgoing_lslice_ratio_hits_trig_cher_over_all = new TH1F("h_mc_atm_nu_upgoing_lslice_ratio_hits_trig_cher_over_all","cher_hits/all_hits", 100 , 0.0 , 1.0 );
TH1F* h_mc_atm_nu_upgoing_lslice_Qup_m_Qdn_JGandalf = new TH1F("h_mc_atm_nu_upgoing_lslice_Qup_m_Qdn_JGandalf","Qup_m_Qdn_JGandalf;Qup-Qdn;", 250 , 0 , 250 );
TH1F* h_mc_atm_nu_upgoing_lslice_max_trig_tot = new TH1F("h_mc_atm_nu_upgoing_lslice_max_trig_tot",";tot [ns];", 100 , 0 , 500 );
TH1F* h_mc_atm_nu_upgoing_lslice_early_trig_10 = new TH1F("h_mc_atm_nu_upgoing_lslice_early_trig_10","", 201 , -0.5 , 200.5 );
TH1F* h_mc_atm_nu_upgoing_lslice_Dn_m_Up_hits = new TH1F("h_mc_atm_nu_upgoing_lslice_Dn_m_Up_hits","Lower_hits_minus_Upper_hits" , 1500 , -500 , 1000);
TH1F* h_mc_atm_nu_upgoing_lslice_Dn_m_Up_trig_hits = new TH1F("h_mc_atm_nu_upgoing_lslice_Dn_m_Up_trig_hits","Lower_hits_minus_Upper_hits_trig" , 1500 , -500 , 1000);
TH1F* h_mc_atm_nu_upgoing_lslice_Dn_m_Up_cher_hits = new TH1F("h_mc_atm_nu_upgoing_lslice_Dn_m_Up_cher_hits","Lower_hits_minus_Upper_hits_cher" , 1500 , -500 , 1000);
TH1F* h_mc_atm_nu_upgoing_lslice_Dn_m_Up_trig_cher_hits = new TH1F("h_mc_atm_nu_upgoing_lslice_Dn_m_Up_trig_cher_hits","Lower_hits_minus_Upper_hits_trig_cher" , 1500 , -500 , 1000);
TH1F* h_mc_atm_nu_upgoing_lslice_diff_energy= new TH1F("h_mc_atm_nu_upgoing_lslice_diff_energy",";(E_true-E_reco)/E_true",100,-1,1);
TH2F* h_mc_atm_nu_upgoing_lslice_diff_energy_cos_zen= new TH2F("h_mc_atm_nu_upgoing_lslice_diff_energy_cos_zen",";zenith [degrees];", 180 , 0.0 , 180.0 , 299 , -2 , 1 );

TH1F* h_mc_atm_nu_upgoing_lslice_le_no_hit_doms = new TH1F("h_mc_atm_nu_upgoing_lslice_le_no_hit_doms","hit DOMs", 108 , 0.5 , 108.5 );
TH1F* h_mc_atm_nu_upgoing_lslice_le_no_cher_doms = new TH1F("h_mc_atm_nu_upgoing_lslice_le_no_cher_doms","Cherenkov doms", 108 , 0.5 , 108.5 );
TH1F* h_mc_atm_nu_upgoing_lslice_le_Nhits = new TH1F("h_mc_atm_nu_upgoing_lslice_le_Nhits",";NHits;", 300 , 0.5 , 300.5 );
TH1F* h_mc_atm_nu_upgoing_lslice_le_beta0 = new TH1F("h_mc_atm_nu_upgoing_lslice_le_beta0",";beta0;",100,0,1);
TH1F* h_mc_atm_nu_upgoing_lslice_le_Qhits = new TH1F("h_mc_atm_nu_upgoing_lslice_le_Qhits",";L/Nhits;",120,0,6);
TH1F* h_mc_atm_nu_upgoing_lslice_le_true_phi = new TH1F("h_mc_atm_nu_upgoing_lslice_le_true_phi",";true_phi;",36,-180,180);
TH1F* h_mc_atm_nu_upgoing_lslice_le_reco_phi = new TH1F("h_mc_atm_nu_upgoing_lslice_le_reco_phi",";reco_phi;",36,-180,180);
TH1F* h_mc_atm_nu_upgoing_lslice_le_bjorken_y = new TH1F("h_mc_atm_nu_upgoing_lslice_le_bjorken_y",";bjorken_y;",100,0,1);
TH1F* h_mc_atm_nu_upgoing_lslice_le_d_closest = new TH1F("h_mc_atm_nu_upgoing_lslice_le_d_closest",";d_closest [m];", 15 , 0 , 150 );
TH1F* h_mc_atm_nu_upgoing_lslice_le_z_closest = new TH1F("h_mc_atm_nu_upgoing_lslice_le_z_closest",";z_closest [m];", 50 , -100 , 400 );
TH1F* h_mc_atm_nu_upgoing_lslice_le_mean_z_hits= new TH1F("h_mc_atm_nu_ lslice_le_mean_z_hits",";vertical position [m];", 160 , -40 , 280 );
TH1F* h_mc_atm_nu_upgoing_lslice_le_reco_vrtx_r = new TH1F("h_mc_atm_nu_upgoing_lslice_le_reco_vrtx_r","reco vrtx radial pos.;r [m];", 40 , 0 , 200 );
TH1F* h_mc_atm_nu_upgoing_lslice_le_trklength = new TH1F("h_mc_atm_nu_upgoing_lslice_le_trklength",";Track Length [m];", 150 , 0 , 300);
TH1F* h_mc_atm_nu_upgoing_lslice_le_zenith = new TH1F("h_mc_atm_nu_upgoing_lslice_le_zenith",";reco zenith [deg]", 180 , 0.0 , 180.0 );
TH1F* h_mc_atm_nu_upgoing_lslice_le_reco_vrtx_z = new TH1F("h_mc_atm_nu_upgoing_lslice_le_reco_vrtx_z","reco vrtx vertical pos.;r [m];", 40 , 0 , 200 );

TH1F* h_mc_atm_nu_upgoing_lslice_he_d_closest = new TH1F("h_mc_atm_nu_upgoing_lslice_he_d_closest",";d_closest [m];", 15 , 0 , 150 );
TH1F* h_mc_atm_nu_upgoing_lslice_he_z_closest = new TH1F("h_mc_atm_nu_upgoing_lslice_he_z_closest",";z_closest [m];", 50 , -100 , 400 );
TH1F* h_mc_atm_nu_upgoing_lslice_he_true_phi = new TH1F("h_mc_atm_nu_upgoing_lslice_he_true_phi",";true_phi;",36,-180,180);
TH1F* h_mc_atm_nu_upgoing_lslice_he_reco_phi = new TH1F("h_mc_atm_nu_upgoing_lslice_he_reco_phi",";reco_phi;",36,-180,180);
TH1F* h_mc_atm_nu_upgoing_lslice_he_bjorken_y = new TH1F("h_mc_atm_nu_upgoing_lslice_he_bjorken_y",";bjorken_y;",100,0,1);
TH1F* h_mc_atm_nu_upgoing_lslice_he_no_hit_doms = new TH1F("h_mc_atm_nu_upgoing_lslice_he_no_hit_doms","hit DOMs", 108 , 0.5 , 108.5 );
TH1F* h_mc_atm_nu_upgoing_lslice_he_no_cher_doms = new TH1F("h_mc_atm_nu_upgoing_lslice_he_no_cher_doms","Cherenkov doms", 108 , 0.5 , 108.5 );
TH1F* h_mc_atm_nu_upgoing_lslice_he_Nhits = new TH1F("h_mc_atm_nu_upgoing_lslice_he_Nhits",";NHits;", 300 , 0.5 , 300.5 );
TH1F* h_mc_atm_nu_upgoing_lslice_he_beta0 = new TH1F("h_mc_atm_nu_upgoing_lslice_he_beta0",";beta0;",100,0,1);
TH1F* h_mc_atm_nu_upgoing_lslice_he_Qhits = new TH1F("h_mc_atm_nu_upgoing_lslice_he_Qhits",";L/Nhits;",120,0,6);
TH1F* h_mc_atm_nu_upgoing_lslice_he_reco_vrtx_z = new TH1F("h_mc_atm_nu_upgoing_lslice_he_reco_vrtx_z","reco vrtx vertical pos.;r [m];", 40 , 0 , 200 );
TH1F* h_mc_atm_nu_upgoing_lslice_he_zenith = new TH1F("h_mc_atm_nu_upgoing_lslice_he_zenith",";reco zenith [deg]", 180 , 0.0 , 180.0 );
TH2F* h_mc_atm_nu_upgoing_lslice_he_reco_vertex_pos = new TH2F("h_mc_atm_nu_upgoing_lslice_he_reco_vertex_pos",";radial position [m];vertical position [m]", 100, 0 , 100 , 160 , -40 , 280 );
TH1F* h_mc_atm_nu_upgoing_lslice_he_trklength = new TH1F("h_mc_atm_nu_upgoing_lslice_he_trklength",";Track Length [m];", 150 , 0 , 300);
TH1F* h_mc_atm_nu_upgoing_lslice_he_mean_z_hits= new TH1F("h_mc_atm_nu_lslice_he_mean_z_hits",";vertical position [m];", 160 , -40 , 280 );
TH1F* h_mc_atm_nu_upgoing_lslice_he_reco_vrtx_r = new TH1F("h_mc_atm_nu_upgoing_lslice_he_reco_vrtx_r","reco vrtx radial pos.;r [m];", 40 , 0 , 200 );





//--------------------------------- Medium Slice ------------------------------------------------
TH1F* h_mc_atm_nu_upgoing_mslice_no_hits = new TH1F("h_mc_atm_nu_upgoing_mslice_no_hits",";# hits;counts;", 1001 , -0.5 , 1000.5 );
TH1F* h_mc_atm_nu_upgoing_mslice_no_hit_doms = new TH1F("h_mc_atm_nu_upgoing_mslice_no_hit_doms","hit DOMs", 108 , 0.5 , 108.5 );
TH1F* h_mc_atm_nu_upgoing_mslice_no_trig_hits = new TH1F("h_mc_atm_nu_upgoing_mslice_no_trig_hits",";# hits;counts;", 1001 , -0.5 , 1000.5 );
TH1F* h_mc_atm_nu_upgoing_mslice_no_trig_doms = new TH1F("h_mc_atm_nu_upgoing_mslice_no_trig_doms","triggered DOMs", 108 , 0.5 , 108.5 );
TH1F* h_mc_atm_nu_upgoing_mslice_no_cher_hits = new TH1F("h_mc_atm_nu_upgoing_mslice_no_cher_hits","Cherenkov hits", 1001 , -0.5 , 1000.5 );
TH1F* h_mc_atm_nu_upgoing_mslice_no_cher_doms = new TH1F("h_mc_atm_nu_upgoing_mslice_no_cher_doms","Cherenkov doms", 108 , 0.5 , 108.5 );
TH1F* h_mc_atm_nu_upgoing_mslice_no_trig_cher_doms = new TH1F("h_mc_atm_nu_upgoing_mslice_no_trig_cher_doms","Trig & Cherenkov doms", 72 , 0.5 , 72.5 );
TH1F* h_mc_atm_nu_upgoing_mslice_no_trig_dus = new TH1F("h_mc_atm_nu_upgoing_mslice_no_trig_dus"," DUs", 6 , 0.5 , 6.5 );
TH1F* h_mc_atm_nu_upgoing_mslice_no_cher_dus = new TH1F("h_mc_atm_nu_upgoing_mslice_no_cher_dus"," DUs", 6 , 0.5 , 6.5 );
TH1F* h_mc_atm_nu_upgoing_mslice_no_trig_cher_dus = new TH1F("h_mc_atm_nu_upgoing_mslice_no_trig_cher_dus"," DUs", 6 , 0.5 , 6.5 );
TH1F* h_mc_atm_nu_upgoing_mslice_no_trig_cher_hits = new TH1F("h_mc_atm_nu_upgoing_mslice_no_trig_cher_hits","Trig & Cherenkov hits", 1001 , -0.5 , 1000.5 );
TH1F* h_mc_atm_nu_upgoing_mslice_zenith = new TH1F("h_mc_atm_nu_upgoing_mslice_zenith",";reco zenith [deg]", 180 , 0.0 , 180.0 );
TH1F* h_mc_atm_nu_upgoing_mslice_true_zenith = new TH1F("h_mc_atm_nu_upgoing_mslice_true_zenith",";true zenith [deg]", 180 , 0.0 , 180.0 );
TH1F* h_mc_atm_nu_upgoing_mslice_cos_zenith = new TH1F("h_mc_atm_nu_upgoing_mslice_cos_zen",";cos(reco zenith)", 100 , -1.0 , 1.0 );
TH1F* h_mc_atm_nu_upgoing_mslice_true_cos_zen = new TH1F("h_mc_atm_nu_upgoing_mslice_true_cos_zen",";cos(reco zenith)", 100 , -1.0 , 1.0 );
TH1F* h_mc_atm_nu_upgoing_mslice_max_lik_dist = new TH1F("h_mc_atm_nu_upgoing_mslice_max_lik",";L;", 100 , 0 , 2000 );
TH1F* h_mc_atm_nu_upgoing_mslice_log_lik_dist = new TH1F("h_mc_atm_nu_upgoing_mslice_log_lik",";log(L);", 100 , -1.0 , 4.0 );
TH1F* h_mc_atm_nu_upgoing_mslice_true_energy_no_log = new TH1F("h_mc_atm_nu_upgoing_mslice_true_energy_no_log", ";True Energy (GeV);",500,0,5000);
TH1F* h_mc_atm_nu_upgoing_mslice_true_energy = new TH1F("h_mc_atm_nu_upgoing_mslice_true_energy",";log[true/GeV];", 40 , 0 , 4.0 );
TH1F* h_mc_atm_nu_upgoing_mslice_reco_energy = new TH1F("h_mc_atm_nu_upgoing_mslice_reco_energy",";log[E_reco/GeV];", 40 , 0 , 4.0 );
TH2F* h_mc_atm_nu_upgoing_mslice_reco_vertex_pos = new TH2F("h_mc_atm_nu_upgoing_mslice_reco_vertex_pos",";radial position [m];vertical position [m]", 100, 0 , 100 , 160 , -40 , 280 );
TH1F* h_mc_atm_nu_upgoing_mslice_reco_vrtx_r = new TH1F("h_mc_atm_nu_upgoing_mslice_reco_vrtx_r","reco vrtx radial pos.;r [m];", 40 , 0 , 200 );
TH1F* h_mc_atm_nu_upgoing_mslice_reco_vrtx_x = new TH1F("h_mc_atm_nu_upgoing_mslice_reco_vrtx_x","reco vrtx x pos.;x [m];", 40 , 0 , 200 );
TH1F* h_mc_atm_nu_upgoing_mslice_reco_vrtx_y = new TH1F("h_mc_atm_nu_upgoing_mslice_reco_vrtx_y","reco vrtx y pos.;y [m];", 40 , 0 , 200 );
TH1F* h_mc_atm_nu_upgoing_mslice_reco_vrtx_z = new TH1F("h_mc_atm_nu_upgoing_mslice_reco_vrtx_z","reco vrtx z pos.;z [m];", 40 , 0 , 200 );
TH1F* h_mc_atm_nu_upgoing_mslice_Nhits = new TH1F("h_mc_atm_nu_upgoing_mslice_Nhits",";NHits;", 300 , 0.5 , 300.5 ); 
TH1F* h_mc_atm_nu_upgoing_mslice_beta0 = new TH1F("h_mc_atm_nu_upgoing_mslice_beta0",";beta0;",100,0,1);
TH1F* h_mc_atm_nu_upgoing_mslice_Qhits = new TH1F("h_mc_atm_nu_upgoing_mslice_Qhits",";L/Nhits;",120,0,6);
TH1F* h_mc_atm_nu_upgoing_mslice_trklength = new TH1F("h_mc_atm_nu_upgoing_mslice_trklength",";Track Length [m];", 150 , 0 , 300);
TH1F* h_mc_atm_nu_upgoing_mslice_d_closest = new TH1F("h_mc_atm_nu_upgoing_mslice_d_closest",";d_closest [m];", 15 , 0 , 150 );
TH1F* h_mc_atm_nu_upgoing_mslice_z_closest = new TH1F("h_mc_atm_nu_upgoing_mslice_z_closest",";z_closest [m];", 50 , -100 , 400 );
TH1F* h_mc_atm_nu_upgoing_mslice_mean_z_hits = new TH1F("h_mc_atm_nu_upgoing_mslice_mean_z_hits",";vertical position [m];", 160 , -40 , 280 );
TH1F* h_mc_atm_nu_upgoing_mslice_mean_z_trig_hits = new TH1F("h_mc_atm_nu_upgoing_mslice_mean_z_trig_hits",";vertical position [m];", 160 , -40 , 280 );
TH1F* h_mc_atm_nu_upgoing_mslice_mean_z_cher_hits = new TH1F("h_mc_atm_nu_upgoing_mslice_mean_z_cher_hits",";vertical position [m];", 160 , -40 , 280 );
TH1F* h_mc_atm_nu_upgoing_mslice_mean_z_trig_cher_hits = new TH1F("h_mc_atm_nu_upgoing_mslice_mean_z_trig_cher_hits",";vertical position [m];", 160 , -40 , 280 );
TH1F* h_mc_atm_nu_upgoing_mslice_ratio_hits_trig_over_all = new TH1F("h_mc_atm_nu_upgoing_mslice_ratio_hits_trig_over_all","trig_hits/all_hits", 100 , 0.0 , 1.0 );
TH1F* h_mc_atm_nu_upgoing_mslice_ratio_hits_cher_over_all = new TH1F("h_mc_atm_nu_upgoing_mslice_ratio_hits_cher_over_all","cher_hits/all_hits", 100 , 0.0 , 1.0 );
TH1F* h_mc_atm_nu_upgoing_mslice_ratio_hits_trig_cher_over_all = new TH1F("h_mc_atm_nu_upgoing_mslice_ratio_hits_trig_cher_over_all","cher_hits/all_hits", 100 , 0.0 , 1.0 );
TH1F* h_mc_atm_nu_upgoing_mslice_Qup_m_Qdn_JGandalf = new TH1F("h_mc_atm_nu_upgoing_mslice_Qup_m_Qdn_JGandalf","Qup_m_Qdn_JGandalf;Qup-Qdn;", 250 , 0 , 250 );
TH1F* h_mc_atm_nu_upgoing_mslice_max_trig_tot = new TH1F("h_mc_atm_nu_upgoing_mslice_max_trig_tot",";tot [ns];", 100 , 0 , 500 );
TH1F* h_mc_atm_nu_upgoing_mslice_early_trig_10 = new TH1F("h_mc_atm_nu_upgoing_mslice_early_trig_10","", 201 , -0.5 , 200.5 );
TH1F* h_mc_atm_nu_upgoing_mslice_Dn_m_Up_hits = new TH1F("h_mc_atm_nu_upgoing_mslice_Dn_m_Up_hits","Lower_hits_minus_Upper_hits" , 1500 , -500 , 1000);
TH1F* h_mc_atm_nu_upgoing_mslice_Dn_m_Up_trig_hits = new TH1F("h_mc_atm_nu_upgoing_mslice_Dn_m_Up_trig_hits","Lower_hits_minus_Upper_hits_trig" , 1500 , -500 , 1000);
TH1F* h_mc_atm_nu_upgoing_mslice_Dn_m_Up_cher_hits = new TH1F("h_mc_atm_nu_upgoing_mslice_Dn_m_Up_cher_hits","Lower_hits_minus_Upper_hits_cher" , 1500 , -500 , 1000);
TH1F* h_mc_atm_nu_upgoing_mslice_Dn_m_Up_trig_cher_hits = new TH1F("h_mc_atm_nu_upgoing_mslice_Dn_m_Up_trig_cher_hits","Lower_hits_minus_Upper_hits_trig_cher" , 1500 , -500 , 1000);
TH1F* h_mc_atm_nu_upgoing_mslice_diff_energy= new TH1F("h_mc_atm_nu_upgoing_mslice_diff_energy",";(E_true-E_reco)/E_true",100,-1,1);
TH2F* h_mc_atm_nu_upgoing_mslice_diff_energy_cos_zen= new TH2F("h_mc_atm_nu_upgoing_mslice_diff_energy_cos_zen",";zenith [degrees];", 180 , 0.0 , 180.0 , 299 , -2 , 1 );

TH1F* h_mc_atm_nu_upgoing_mslice_le_mean_z_hits= new TH1F("h_mc_atm_nu_upgoing_mslice_le_mean_z_hits",";vertical position [m];", 160 , -40 , 280 );
TH1F* h_mc_atm_nu_upgoing_mslice_le_reco_vrtx_r = new TH1F("h_mc_atm_nu_upgoing_mslice_le_reco_vrtx_r","reco vrtx radial pos.;r [m];", 40 , 0 , 200 );
TH1F* h_mc_atm_nu_upgoing_mslice_le_no_hit_doms = new TH1F("h_mc_atm_nu_upgoing_mslice_le_no_hit_doms","hit DOMs", 108 , 0.5 , 108.5 );
TH1F* h_mc_atm_nu_upgoing_mslice_le_no_cher_doms = new TH1F("h_mc_atm_nu_upgoing_mslice_le_no_cher_doms","Cherenkov doms", 108 , 0.5 , 108.5 );
TH1F* h_mc_atm_nu_upgoing_mslice_le_Nhits = new TH1F("h_mc_atm_nu_upgoing_mslice_le_Nhits",";NHits;", 300 , 0.5 , 300.5 );
TH1F* h_mc_atm_nu_upgoing_mslice_le_beta0 = new TH1F("h_mc_atm_nu_upgoing_mslice_le_beta0",";beta0;",100,0,1);
TH1F* h_mc_atm_nu_upgoing_mslice_le_Qhits = new TH1F("h_mc_atm_nu_upgoing_mslice_le_Qhits",";L/Nhits;",120,0,6);
TH1F* h_mc_atm_nu_upgoing_mslice_le_true_phi = new TH1F("h_mc_atm_nu_upgoing_mslice_le_true_phi",";true_phi;",36,-180,180);
TH1F* h_mc_atm_nu_upgoing_mslice_le_reco_phi = new TH1F("h_mc_atm_nu_upgoing_mslice_le_reco_phi",";reco_phi;",36,-180,180);
TH1F* h_mc_atm_nu_upgoing_mslice_le_bjorken_y = new TH1F("h_mc_atm_nu_upgoing_mslice_le_bjorken_y",";bjorken_y;",100,0,1);
TH1F* h_mc_atm_nu_upgoing_mslice_le_d_closest = new TH1F("h_mc_atm_nu_upgoing_mslice_le_d_closest",";d_closest [m];", 15 , 0 , 150 );
TH1F* h_mc_atm_nu_upgoing_mslice_le_z_closest = new TH1F("h_mc_atm_nu_upgoing_mslice_le_z_closest",";z_closest [m];", 50 , -100 , 400 );
TH1F* h_mc_atm_nu_upgoing_mslice_le_trklength = new TH1F("h_mc_atm_nu_upgoing_mslice_le_trklength",";Track Length [m];", 150 , 0 , 300);
TH1F* h_mc_atm_nu_upgoing_mslice_le_zenith = new TH1F("h_mc_atm_nu_upgoing_mslice_le_zenith",";reco zenith [deg]", 180 , 0.0 , 180.0 );
TH1F* h_mc_atm_nu_upgoing_mslice_le_reco_vrtx_z = new TH1F("h_mc_atm_nu_upgoing_mslice_le_reco_vrtx_z","reco vrtx vertical pos.;r [m];", 40 , 0 , 200 );


TH1F* h_mc_atm_nu_upgoing_mslice_me_d_closest = new TH1F("h_mc_atm_nu_upgoing_mslice_me_d_closest",";d_closest [m];", 15 , 0 , 150 );
TH1F* h_mc_atm_nu_upgoing_mslice_me_z_closest = new TH1F("h_mc_atm_nu_upgoing_mslice_me_z_closest",";z_closest [m];", 50 , -100 , 400 );
TH1F* h_mc_atm_nu_upgoing_mslice_me_true_phi = new TH1F("h_mc_atm_nu_upgoing_mslice_me_true_phi",";true_phi;",36,-180,180);
TH1F* h_mc_atm_nu_upgoing_mslice_me_reco_phi = new TH1F("h_mc_atm_nu_upgoing_mslice_me_reco_phi",";reco_phi;",36,-180,180);
TH1F* h_mc_atm_nu_upgoing_mslice_me_bjorken_y = new TH1F("h_mc_atm_nu_upgoing_mslice_me_bjorken_y",";bjorken_y;",100,0,1);
TH1F* h_mc_atm_nu_upgoing_mslice_me_no_hit_doms = new TH1F("h_mc_atm_nu_upgoing_mslice_me_no_hit_doms","hit DOMs", 108 , 0.5 , 108.5 );
TH1F* h_mc_atm_nu_upgoing_mslice_me_no_cher_doms = new TH1F("h_mc_atm_nu_upgoing_mslice_me_no_cher_doms","Cherenkov doms", 108 , 0.5 , 108.5 );
TH1F* h_mc_atm_nu_upgoing_mslice_me_Nhits = new TH1F("h_mc_atm_nu_upgoing_mslice_me_Nhits",";NHits;", 300 , 0.5 , 300.5 );
TH1F* h_mc_atm_nu_upgoing_mslice_me_beta0 = new TH1F("h_mc_atm_nu_upgoing_mslice_me_beta0",";beta0;",100,0,1);
TH1F* h_mc_atm_nu_upgoing_mslice_me_Qhits = new TH1F("h_mc_atm_nu_upgoing_mslice_me_Qhits",";L/Nhits;",120,0,6);
TH1F* h_mc_atm_nu_upgoing_mslice_me_reco_vrtx_z = new TH1F("h_mc_atm_nu_upgoing_mslice_me_reco_vrtx_z","reco vrtx vertical pos.;r [m];", 40 , 0 , 200 );
TH1F* h_mc_atm_nu_upgoing_mslice_me_zenith = new TH1F("h_mc_atm_nu_upgoing_mslice_me_zenith",";reco zenith [deg]", 180 , 0.0 , 180.0 );
TH2F* h_mc_atm_nu_upgoing_mslice_me_reco_vertex_pos = new TH2F("h_mc_atm_nu_upgoing_mslice_me_reco_vertex_pos",";radial position [m];vertical position [m]", 100, 0 , 100 , 160 , -40 , 280 );
TH1F* h_mc_atm_nu_upgoing_mslice_me_trklength = new TH1F("h_mc_atm_nu_upgoing_mslice_me_trklength",";Track Length [m];", 150 , 0 , 300);
TH1F* h_mc_atm_nu_upgoing_mslice_me_mean_z_hits= new TH1F("h_mc_atm_nu_upgoing_mslice_me_mean_z_hits",";vertical position [m];", 160 , -40 , 280 );
TH1F* h_mc_atm_nu_upgoing_mslice_me_reco_vrtx_r = new TH1F("h_mc_atm_nu_upgoing_mslice_me_reco_vrtx_r","reco vrtx radial pos.;r [m];", 40 , 0 , 200 );

TH1F* h_mc_atm_nu_upgoing_mslice_he_d_closest = new TH1F("h_mc_atm_nu_upgoing_mslice_he_d_closest",";d_closest [m];", 15 , 0 , 150 );
TH1F* h_mc_atm_nu_upgoing_mslice_he_z_closest = new TH1F("h_mc_atm_nu_upgoing_mslice_he_z_closest",";z_closest [m];", 50 , -100 , 400 );
TH1F* h_mc_atm_nu_upgoing_mslice_he_true_phi = new TH1F("h_mc_atm_nu_upgoing_mslice_he_true_phi",";true_phi;",36,-180,180);
TH1F* h_mc_atm_nu_upgoing_mslice_he_reco_phi = new TH1F("h_mc_atm_nu_upgoing_mslice_he_reco_phi",";reco_phi;",36,-180,180);
TH1F* h_mc_atm_nu_upgoing_mslice_he_bjorken_y = new TH1F("h_mc_atm_nu_upgoing_mslice_he_bjorken_y",";bjorken_y;",100,0,1);
TH1F* h_mc_atm_nu_upgoing_mslice_he_no_hit_doms = new TH1F("h_mc_atm_nu_upgoing_mslice_he_no_hit_doms","hit DOMs", 108 , 0.5 , 108.5 );
TH1F* h_mc_atm_nu_upgoing_mslice_he_no_cher_doms = new TH1F("h_mc_atm_nu_upgoing_mslice_he_no_cher_doms","Cherenkov doms", 108 , 0.5 , 108.5 );
TH1F* h_mc_atm_nu_upgoing_mslice_he_Nhits = new TH1F("h_mc_atm_nu_upgoing_mslice_he_Nhits",";NHits;", 300 , 0.5 , 300.5 );
TH1F* h_mc_atm_nu_upgoing_mslice_he_beta0 = new TH1F("h_mc_atm_nu_upgoing_mslice_he_beta0",";beta0;",100,0,1);
TH1F* h_mc_atm_nu_upgoing_mslice_he_Qhits = new TH1F("h_mc_atm_nu_upgoing_mslice_he_Qhits",";L/Nhits;",120,0,6);
TH1F* h_mc_atm_nu_upgoing_mslice_he_mean_z_hits= new TH1F("h_mc_atm_nu_upgoing_mslice_he_mean_z_hits",";vertical position [m];", 160 , -40 , 280 );
TH1F* h_mc_atm_nu_upgoing_mslice_he_reco_vrtx_r = new TH1F("h_mc_atm_nu_upgoing_mslice_he_reco_vrtx_r","reco vrtx radial pos.;r [m];", 40 , 0 , 200 );
TH2F* h_mc_atm_nu_upgoing_mslice_he_reco_vertex_pos = new TH2F("h_mc_atm_nu_upgoing_mslice_he_reco_vertex_pos",";radial position [m];vertical position [m]", 100, 0 , 100 , 160 , -40 , 280 );
TH1F* h_mc_atm_nu_upgoing_mslice_he_trklength = new TH1F("h_mc_atm_nu_upgoing_mslice_he_trklength",";Track Length [m];", 150 , 0 , 300);
TH1F* h_mc_atm_nu_upgoing_mslice_he_zenith = new TH1F("h_mc_atm_nu_upgoing_mslice_he_zenith",";reco zenith [deg]", 180 , 0.0 , 180.0 );
TH1F* h_mc_atm_nu_upgoing_mslice_he_reco_vrtx_z = new TH1F("h_mc_atm_nu_upgoing_mslice_he_reco_vrtx_z","reco vrtx vertical pos.;r [m];", 40 , 0 , 200 );

//--------------------------------- High Slice --------------------------------------------------
TH1F* h_mc_atm_nu_upgoing_hslice_no_hits = new TH1F("h_mc_atm_nu_upgoing_hslice_no_hits",";# hits;counts;", 1001 , -0.5 , 1000.5 );
TH1F* h_mc_atm_nu_upgoing_hslice_no_hit_doms = new TH1F("h_mc_atm_nu_upgoing_hslice_no_hit_doms","hit DOMs", 108 , 0.5 , 108.5 );
TH1F* h_mc_atm_nu_upgoing_hslice_no_trig_hits = new TH1F("h_mc_atm_nu_upgoing_hslice_no_trig_hits",";# hits;counts;", 1001 , -0.5 , 1000.5 );
TH1F* h_mc_atm_nu_upgoing_hslice_no_trig_doms = new TH1F("h_mc_atm_nu_upgoing_hslice_no_trig_doms","triggered DOMs", 108 , 0.5 , 108.5 );
TH1F* h_mc_atm_nu_upgoing_hslice_no_cher_hits = new TH1F("h_mc_atm_nu_upgoing_hslice_no_cher_hits","Cherenkov hits", 1001 , -0.5 , 1000.5 );
TH1F* h_mc_atm_nu_upgoing_hslice_no_cher_doms = new TH1F("h_mc_atm_nu_upgoing_hslice_no_cher_doms","Cherenkov doms", 108 , 0.5 , 108.5 );
TH1F* h_mc_atm_nu_upgoing_hslice_no_trig_cher_doms = new TH1F("h_mc_atm_nu_upgoing_hslice_no_trig_cher_doms","Trig & Cherenkov doms", 72 , 0.5 , 72.5 );
TH1F* h_mc_atm_nu_upgoing_hslice_no_trig_dus = new TH1F("h_mc_atm_nu_upgoing_hslice_no_trig_dus"," DUs", 6 , 0.5 , 6.5 );
TH1F* h_mc_atm_nu_upgoing_hslice_no_cher_dus = new TH1F("h_mc_atm_nu_upgoing_hslice_no_cher_dus"," DUs", 6 , 0.5 , 6.5 );
TH1F* h_mc_atm_nu_upgoing_hslice_no_trig_cher_dus = new TH1F("h_mc_atm_nu_upgoing_hslice_no_trig_cher_dus"," DUs", 6 , 0.5 , 6.5 );
TH1F* h_mc_atm_nu_upgoing_hslice_no_trig_cher_hits = new TH1F("h_mc_atm_nu_upgoing_hslice_no_trig_cher_hits","Trig & Cherenkov hits", 1001 , -0.5 , 1000.5 );
TH1F* h_mc_atm_nu_upgoing_hslice_zenith = new TH1F("h_mc_atm_nu_upgoing_hslice_zenith",";reco zenith [deg]", 180 , 0.0 , 180.0 );
TH1F* h_mc_atm_nu_upgoing_hslice_true_zenith = new TH1F("h_mc_atm_nu_upgoing_hslice_true_zenith",";true zenith [deg]", 180 , 0.0 , 180.0 );
TH1F* h_mc_atm_nu_upgoing_hslice_cos_zenith = new TH1F("h_mc_atm_nu_upgoing_hslice_cos_zen",";cos(reco zenith)", 100 , -1.0 , 1.0 );
TH1F* h_mc_atm_nu_upgoing_hslice_true_cos_zen = new TH1F("h_mc_atm_nu_upgoing_hslice_true_cos_zen",";cos(reco zenith)", 100 , -1.0 , 1.0 );
TH1F* h_mc_atm_nu_upgoing_hslice_max_lik_dist = new TH1F("h_mc_atm_nu_upgoing_hslice_max_lik",";L;", 100 , 0 , 2000 );
TH1F* h_mc_atm_nu_upgoing_hslice_log_lik_dist = new TH1F("h_mc_atm_nu_upgoing_hslice_log_lik",";log(L);", 100 , -1.0 , 4.0 );
TH1F* h_mc_atm_nu_upgoing_hslice_true_energy_no_log = new TH1F("h_mc_atm_nu_upgoing_hslice_true_energy_no_log", ";True Energy (GeV);",500,0,5000);
TH1F* h_mc_atm_nu_upgoing_hslice_true_energy = new TH1F("h_mc_atm_nu_upgoing_hslice_true_energy",";log[true/GeV];", 40 , 0 , 4.0 );
TH1F* h_mc_atm_nu_upgoing_hslice_reco_energy = new TH1F("h_mc_atm_nu_upgoing_hslice_reco_energy",";log[E_reco/GeV];", 40 , 0 , 4.0 );
TH2F* h_mc_atm_nu_upgoing_hslice_reco_vertex_pos = new TH2F("h_mc_atm_nu_upgoing_hslice_reco_vertex_pos",";radial position [m];vertical position [m]", 100, 0 , 100 , 160 , -40 , 280 );
TH1F* h_mc_atm_nu_upgoing_hslice_reco_vrtx_r = new TH1F("h_mc_atm_nu_upgoing_hslice_reco_vrtx_r","reco vrtx radial pos.;r [m];", 40 , 0 , 200 );
TH1F* h_mc_atm_nu_upgoing_hslice_reco_vrtx_x = new TH1F("h_mc_atm_nu_upgoing_hslice_reco_vrtx_x","reco vrtx x pos.;x [m];", 40 , 0 , 200 );
TH1F* h_mc_atm_nu_upgoing_hslice_reco_vrtx_y = new TH1F("h_mc_atm_nu_upgoing_hslice_reco_vrtx_y","reco vrtx y pos.;y [m];", 40 , 0 , 200 );
TH1F* h_mc_atm_nu_upgoing_hslice_reco_vrtx_z = new TH1F("h_mc_atm_nu_upgoing_hslice_reco_vrtx_z","reco vrtx z pos.;z [m];", 40 , 0 , 200 );
TH1F* h_mc_atm_nu_upgoing_hslice_Nhits = new TH1F("h_mc_atm_nu_upgoing_hslice_Nhits",";NHits;", 300 , 0.5 , 300.5 );
TH1F* h_mc_atm_nu_upgoing_hslice_beta0 = new TH1F("h_mc_atm_nu_upgoing_hslice_beta0",";beta0;",100,0,1);
TH1F* h_mc_atm_nu_upgoing_hslice_Qhits = new TH1F("h_mc_atm_nu_upgoing_hslice_Qhits",";L/Nhits;",120,0,6);
TH1F* h_mc_atm_nu_upgoing_hslice_trklength = new TH1F("h_mc_atm_nu_upgoing_hslice_trklength",";Track Length [m];", 150 , 0 , 300);
TH1F* h_mc_atm_nu_upgoing_hslice_d_closest = new TH1F("h_mc_atm_nu_upgoing_hslice_d_closest",";d_closest [m];", 15 , 0 , 150 );
TH1F* h_mc_atm_nu_upgoing_hslice_z_closest = new TH1F("h_mc_atm_nu_upgoing_hslice_z_closest",";z_closest [m];", 50 , -100 , 400 );
TH1F* h_mc_atm_nu_upgoing_hslice_mean_z_hits = new TH1F("h_mc_atm_nu_upgoing_hslice_mean_z_hits",";vertical position [m];", 160 , -40 , 280 );
TH1F* h_mc_atm_nu_upgoing_hslice_mean_z_trig_hits = new TH1F("h_mc_atm_nu_upgoing_hslice_mean_z_trig_hits",";vertical position [m];", 160 , -40 , 280 );
TH1F* h_mc_atm_nu_upgoing_hslice_mean_z_cher_hits = new TH1F("h_mc_atm_nu_upgoing_hslice_mean_z_cher_hits",";vertical position [m];", 160 , -40 , 280 );
TH1F* h_mc_atm_nu_upgoing_hslice_mean_z_trig_cher_hits = new TH1F("h_mc_atm_nu_upgoing_hslice_mean_z_trig_cher_hits",";vertical position [m];", 160 , -40 , 280 );
TH1F* h_mc_atm_nu_upgoing_hslice_ratio_hits_trig_over_all = new TH1F("h_mc_atm_nu_upgoing_hslice_ratio_hits_trig_over_all","trig_hits/all_hits", 100 , 0.0 , 1.0 );
TH1F* h_mc_atm_nu_upgoing_hslice_ratio_hits_cher_over_all = new TH1F("h_mc_atm_nu_upgoing_hslice_ratio_hits_cher_over_all","cher_hits/all_hits", 100 , 0.0 , 1.0 );
TH1F* h_mc_atm_nu_upgoing_hslice_ratio_hits_trig_cher_over_all = new TH1F("h_mc_atm_nu_upgoing_hslice_ratio_hits_trig_cher_over_all","cher_hits/all_hits", 100 , 0.0 , 1.0 );
TH1F* h_mc_atm_nu_upgoing_hslice_Qup_m_Qdn_JGandalf = new TH1F("h_mc_atm_nu_upgoing_hslice_Qup_m_Qdn_JGandalf","Qup_m_Qdn_JGandalf;Qup-Qdn;", 250 , 0 , 250 );
TH1F* h_mc_atm_nu_upgoing_hslice_max_trig_tot = new TH1F("h_mc_atm_nu_upgoing_hslice_max_trig_tot",";tot [ns];", 100 , 0 , 500 );
TH1F* h_mc_atm_nu_upgoing_hslice_early_trig_10 = new TH1F("h_mc_atm_nu_upgoing_hslice_early_trig_10","", 201 , -0.5 , 200.5 );
TH1F* h_mc_atm_nu_upgoing_hslice_Dn_m_Up_hits = new TH1F("h_mc_atm_nu_upgoing_hslice_Dn_m_Up_hits","Lower_hits_minus_Upper_hits" , 1500 , -500 , 1000);
TH1F* h_mc_atm_nu_upgoing_hslice_Dn_m_Up_trig_hits = new TH1F("h_mc_atm_nu_upgoing_hslice_Dn_m_Up_trig_hits","Lower_hits_minus_Upper_hits_trig" , 1500 , -500 , 1000);
TH1F* h_mc_atm_nu_upgoing_hslice_Dn_m_Up_cher_hits = new TH1F("h_mc_atm_nu_upgoing_hslice_Dn_m_Up_cher_hits","Lower_hits_minus_Upper_hits_cher" , 1500 , -500 , 1000);
TH1F* h_mc_atm_nu_upgoing_hslice_Dn_m_Up_trig_cher_hits = new TH1F("h_mc_atm_nu_upgoing_hslice_Dn_m_Up_trig_cher_hits","Lower_hits_minus_Upper_hits_trig_cher" , 1500 , -500 , 1000);
TH1F* h_mc_atm_nu_upgoing_hslice_diff_energy= new TH1F("h_mc_atm_nu_upgoing_hslice_diff_energy",";(E_true-E_reco)/E_true",100,-1,1);
TH2F* h_mc_atm_nu_upgoing_hslice_diff_energy_cos_zen= new TH2F("h_mc_atm_nu_upgoing_hslice_diff_energy_cos_zen",";zenith [degrees];", 180 , 0.0 , 180.0 , 299 , -2 , 1 );


TH1F* h_mc_atm_nu_upgoing_hslice_le_no_hit_doms = new TH1F("h_mc_atm_nu_upgoing_hslice_le_no_hit_doms","hit DOMs", 108 , 0.5 , 108.5 );
TH1F* h_mc_atm_nu_upgoing_hslice_le_no_cher_doms = new TH1F("h_mc_atm_nu_upgoing_hslice_le_no_cher_doms","Cherenkov doms", 108 , 0.5 , 108.5 );
TH1F* h_mc_atm_nu_upgoing_hslice_le_Nhits = new TH1F("h_mc_atm_nu_upgoing_hslice_le_Nhits",";NHits;", 300 , 0.5 , 300.5 );
TH1F* h_mc_atm_nu_upgoing_hslice_le_beta0 = new TH1F("h_mc_atm_nu_upgoing_hslice_le_beta0",";beta0;",100,0,1);
TH1F* h_mc_atm_nu_upgoing_hslice_le_Qhits = new TH1F("h_mc_atm_nu_upgoing_hslice_le_Qhits",";L/Nhits;",120,0,6);
TH1F* h_mc_atm_nu_upgoing_hslice_le_true_phi = new TH1F("h_mc_atm_nu_upgoing_hslice_le_true_phi",";true_phi;",36,-180,180);
TH1F* h_mc_atm_nu_upgoing_hslice_le_reco_phi = new TH1F("h_mc_atm_nu_upgoing_hslice_le_reco_phi",";reco_phi;",36,-180,180);
TH1F* h_mc_atm_nu_upgoing_hslice_le_bjorken_y = new TH1F("h_mc_atm_nu_upgoing_hslice_le_bjorken_y",";bjorken_y;",100,0,1);
TH1F* h_mc_atm_nu_upgoing_hslice_le_d_closest = new TH1F("h_mc_atm_nu_upgoing_hslice_le_d_closest",";d_closest [m];", 15 , 0 , 150 );
TH1F* h_mc_atm_nu_upgoing_hslice_le_z_closest = new TH1F("h_mc_atm_nu_upgoing_hslice_le_z_closest",";z_closest [m];", 50 , -100 , 400 );
TH1F* h_mc_atm_nu_upgoing_hslice_le_mean_z_hits= new TH1F("h_mc_atm_nu_ hslice_le_mean_z_hits",";vertical position [m];", 160 , -40 , 280 );
TH1F* h_mc_atm_nu_upgoing_hslice_le_reco_vrtx_r = new TH1F("h_mc_atm_nu_upgoing_hslice_le_reco_vrtx_r","reco vrtx radial pos.;r [m];", 40 , 0 , 200 );
TH1F* h_mc_atm_nu_upgoing_hslice_le_trklength = new TH1F("h_mc_atm_nu_upgoing_hslice_le_trklength",";Track Length [m];", 150 , 0 , 300);
TH1F* h_mc_atm_nu_upgoing_hslice_le_zenith = new TH1F("h_mc_atm_nu_upgoing_hslice_le_zenith",";reco zenith [deg]", 180 , 0.0 , 180.0 );
TH1F* h_mc_atm_nu_upgoing_hslice_le_reco_vrtx_z = new TH1F("h_mc_atm_nu_upgoing_hslice_le_reco_vrtx_z","reco vrtx vertical pos.;r [m];", 40 , 0 , 200 );


TH1F* h_mc_atm_nu_upgoing_hslice_me_d_closest = new TH1F("h_mc_atm_nu_upgoing_hslice_me_d_closest",";d_closest [m];", 15 , 0 , 150 );
TH1F* h_mc_atm_nu_upgoing_hslice_me_z_closest = new TH1F("h_mc_atm_nu_upgoing_hslice_me_z_closest",";z_closest [m];", 50 , -100 , 400 );
TH1F* h_mc_atm_nu_upgoing_hslice_me_true_phi = new TH1F("h_mc_atm_nu_upgoing_hslice_me_true_phi",";true_phi;",36,-180,180);
TH1F* h_mc_atm_nu_upgoing_hslice_me_reco_phi = new TH1F("h_mc_atm_nu_upgoing_hslice_me_reco_phi",";reco_phi;",36,-180,180);
TH1F* h_mc_atm_nu_upgoing_hslice_me_bjorken_y = new TH1F("h_mc_atm_nu_upgoing_hslice_me_bjorken_y",";bjorken_y;",100,0,1);
TH1F* h_mc_atm_nu_upgoing_hslice_me_no_hit_doms = new TH1F("h_mc_atm_nu_upgoing_hslice_me_no_hit_doms","hit DOMs", 108 , 0.5 , 108.5 );
TH1F* h_mc_atm_nu_upgoing_hslice_me_no_cher_doms = new TH1F("h_mc_atm_nu_upgoing_hslice_me_no_cher_doms","Cmerenkov doms", 108 , 0.5 , 108.5 );
TH1F* h_mc_atm_nu_upgoing_hslice_me_Nhits = new TH1F("h_mc_atm_nu_upgoing_hslice_me_Nhits",";NHits;", 300 , 0.5 , 300.5 );
TH1F* h_mc_atm_nu_upgoing_hslice_me_beta0 = new TH1F("h_mc_atm_nu_upgoing_hslice_me_beta0",";beta0;",100,0,1);
TH1F* h_mc_atm_nu_upgoing_hslice_me_Qhits = new TH1F("h_mc_atm_nu_upgoing_hslice_me_Qhits",";L/Nhits;",120,0,6);
TH1F* h_mc_atm_nu_upgoing_hslice_me_reco_vrtx_z = new TH1F("h_mc_atm_nu_upgoing_hslice_me_reco_vrtx_z","reco vrtx vertical pos.;r [m];", 40 , 0 , 200 );
TH1F* h_mc_atm_nu_upgoing_hslice_me_zenith = new TH1F("h_mc_atm_nu_upgoing_hslice_me_zenith",";reco zenith [deg]", 180 , 0.0 , 180.0 );
TH2F* h_mc_atm_nu_upgoing_hslice_me_reco_vertex_pos = new TH2F("h_mc_atm_nu_upgoing_hslice_me_reco_vertex_pos",";radial position [m];vertical position [m]", 100, 0 , 100 , 160 , -40 , 280 );
TH1F* h_mc_atm_nu_upgoing_hslice_me_trklength = new TH1F("h_mc_atm_nu_upgoing_hslice_me_trklength",";Track Length [m];", 150 , 0 , 300);
TH1F* h_mc_atm_nu_upgoing_hslice_me_mean_z_hits= new TH1F("h_mc_atm_nu_upgoing_hslice_me_mean_z_hits",";vertical position [m];", 160 , -40 , 280 );
TH1F* h_mc_atm_nu_upgoing_hslice_me_reco_vrtx_r = new TH1F("h_mc_atm_nu_upgoing_hslice_me_reco_vrtx_r","reco vrtx radial pos.;r [m];", 40 , 0 , 200 );


TH1F* h_mc_atm_nu_upgoing_hslice_he_d_closest = new TH1F("h_mc_atm_nu_upgoing_hslice_he_d_closest",";d_closest [m];", 15 , 0 , 150 );
TH1F* h_mc_atm_nu_upgoing_hslice_he_z_closest = new TH1F("h_mc_atm_nu_upgoing_hslice_he_z_closest",";z_closest [m];", 50 , -100 , 400 );
TH1F* h_mc_atm_nu_upgoing_hslice_he_true_phi = new TH1F("h_mc_atm_nu_upgoing_hslice_he_true_phi",";true_phi;",36,-180,180);
TH1F* h_mc_atm_nu_upgoing_hslice_he_reco_phi = new TH1F("h_mc_atm_nu_upgoing_hslice_he_reco_phi",";reco_phi;",36,-180,180);
TH1F* h_mc_atm_nu_upgoing_hslice_he_bjorken_y = new TH1F("h_mc_atm_nu_upgoing_hslice_he_bjorken_y",";bjorken_y;",100,0,1);
TH1F* h_mc_atm_nu_upgoing_hslice_he_no_hit_doms = new TH1F("h_mc_atm_nu_upgoing_hslice_he_no_hit_doms","hit DOMs", 108 , 0.5 , 108.5 );
TH1F* h_mc_atm_nu_upgoing_hslice_he_no_cher_doms = new TH1F("h_mc_atm_nu_upgoing_hslice_he_no_cher_doms","Cherenkov doms", 108 , 0.5 , 108.5 );
TH1F* h_mc_atm_nu_upgoing_hslice_he_Nhits = new TH1F("h_mc_atm_nu_upgoing_hslice_he_Nhits",";NHits;", 300 , 0.5 , 300.5 );
TH1F* h_mc_atm_nu_upgoing_hslice_he_beta0 = new TH1F("h_mc_atm_nu_upgoing_hslice_he_beta0",";beta0;",100,0,1);
TH1F* h_mc_atm_nu_upgoing_hslice_he_Qhits = new TH1F("h_mc_atm_nu_upgoing_hslice_he_Qhits",";L/Nhits;",120,0,6);
TH1F* h_mc_atm_nu_upgoing_hslice_he_reco_vrtx_z = new TH1F("h_mc_atm_nu_upgoing_hslice_he_reco_vrtx_z","reco vrtx vertical pos.;r [m];", 40 , 0 , 200 );
TH1F* h_mc_atm_nu_upgoing_hslice_he_zenith = new TH1F("h_mc_atm_nu_upgoing_hslice_he_zenith",";reco zenith [deg]", 180 , 0.0 , 180.0 );
TH2F* h_mc_atm_nu_upgoing_hslice_he_reco_vertex_pos = new TH2F("h_mc_atm_nu_upgoing_hslice_he_reco_vertex_pos",";radial position [m];vertical position [m]", 100, 0 , 100 , 160 , -40 , 280 );
TH1F* h_mc_atm_nu_upgoing_hslice_he_trklength = new TH1F("h_mc_atm_nu_upgoing_hslice_he_trklength",";Track Length [m];", 150 , 0 , 300);
TH1F* h_mc_atm_nu_upgoing_hslice_he_mean_z_hits= new TH1F("h_mc_atm_nu_hslice_he_mean_z_hits",";vertical position [m];", 160 , -40 , 280 );
TH1F* h_mc_atm_nu_upgoing_hslice_he_reco_vrtx_r = new TH1F("h_mc_atm_nu_upgoing_hslice_he_reco_vrtx_r","reco vrtx radial pos.;r [m];", 40 , 0 , 200 );


//index for finding the index and run of a certain particles intended for the Event Display () 
//std::list<std::integer> indexes_horizontal[6]={0,0,0,0,0,0}; 
//std::list<std::integer> indexes_upgoing[6]={0,0,0,0,0,0}; 
int indexes_horizontal[6]={0,0,0,0,0,0}; 
int indexes_upgoing[6]={0,0,0,0,0,0}; 
//std::list<int> indexes_horizontal = {0,0,0,0,0,0}; 
//std::list<int> indexes_upgoing = {0,0,0,0,0,0}; 

 //--------------- Loop for the histograms of all cases (all neutrino,low,medium,high) --------------------------------------
for( int i=0 ; i<mc_atm_nu_events->GetEntries() ; i++ ){
mc_atm_nu_events->GetEntry(i); // get i-th event parameters


//cuts
//if( (cos_zen<0) && (max_tot_trig<220) && (early_trig_10<5) && (no_doms_cher_hit>5) && (cher_hits_over_all>0.28) && (Dn_m_Up_trig_cher_hits>0) && (Dn_m_Up_cher_hits>5) && (mean_z_cher_hits>55) && (log_lik>1.7) && (Qhits>2.0) && (Nhits>20) && (Qup_m_Qdn_JGandalf>10) && (max_lik/TrkLength>1.5) && (reco_vrtx_r<45.0) && (reco_vrtx_y>-38.0) && (reco_vrtx_y<38.0) && (z_closest<185) ){
//if ((reco_vrtx_r<50)&&(d_closest<20)){
//if(()&&(log_lik>1.7) ){
 
//Conditions used!
// (1)  condition for good reconstruction
// (2)  For the upgoing
// (3) flavor for specific leptons  //for electrons flav= +-12 muons flav=+-14 tau flav=+-16 

if (((abs(zenith-true_zenith)<10))&& ((flav==14) || (flav==-14))){
if ((zenith>=150)&&(zenith<=180)){
  
  /////////////////////////////////////////////////////////////////////////////////////////////
  //                           Event Data Display                                            //
  /////////////////////////////////////////////////////////////////////////////////////////////
 
  //if ( i>= 2000000){
  if (((reco_energy)<31)&&(true_energy>=10) && (true_energy<=13)&&(indexes_upgoing[0]<1)){
    cout << "For particle inside the lslice for upgoing events, the following identifications" << endl;
    cout << "With exact True Energy:" << true_energy << endl; 
    cout << "Low Energy Particle with Ereco="<< reco_energy << "\t Zenith Variation:" << abs(zenith-true_zenith) << "\t Omega Variation:" << abs(reco_phi-true_phi) <<endl; // << "\t Nhits:" << no_hits 3
    cout << "Run: " << run << "\t Event ID:" << event_id << "\t Index:" << index << "\t Flav:" << flav << "\t Interaction Type:"<< int(interaction_type)<< "\t Cos_Zen:" << cos_zen << "\n" << endl;
    indexes_upgoing[0]=indexes_upgoing[0]+1;}
  else if (((reco_energy)>31)&&(true_energy>=10) && (true_energy<=13)&&(indexes_upgoing[1]<1)){
    cout << "For particle inside the lslice for upgoing events, the following identifications" << endl;
    cout << "With exact True Energy:" << true_energy << endl;      
    cout << "Low Energy Particle with Ereco="<< reco_energy << "\t Zenith Variation:" << abs(zenith-true_zenith) << "\t Omega Variation:" << abs(reco_phi-true_phi) <<endl; // << "\t Nhits:" << no_hits 
    cout << "Run: " << run << "\t Event ID:" << event_id << "\t Index:" << index << "\t Flav:" << flav << "\t Interaction Type:"<< int(interaction_type)<< "\t Cos_Zen:" << cos_zen << "\n" << endl;
    indexes_upgoing[1]=indexes_upgoing[1]+1;}
  else if (((reco_energy)<31)&&(true_energy>=100) && (true_energy<=126)&&(indexes_upgoing[2]<1)){
    cout << "For particle inside the mslice for upgoing events, the following identifications:" << endl;
    cout << "With exact True Energy:" << true_energy << endl; 
    cout << "Medium Energy Particle with Ereco="<< reco_energy << "\t Zenith Variation:" << abs(zenith-true_zenith) << "\t Omega Variation:" << abs(reco_phi-true_phi) <<endl; // << "\t Nhits:" << no_hits 
    cout << "Run: " << run << "\t Event ID:" << event_id << "\t Index:" << index << "\t Flav:" << flav << "\t Interaction Type:"<< int(interaction_type)<< "\t Cos_Zen:" << cos_zen << "\n" << endl;
    indexes_upgoing[2]=indexes_upgoing[2]+1;}
  else if (((reco_energy)>31)&&(true_energy>=100) && (true_energy<=126)&&(indexes_upgoing[3]<1)){
    cout << "For particle inside the mslice for upgoing events, the following identifications:" << endl;
    cout << "With exact True Energy:" << true_energy << endl; 
    cout << "Medium Energy Particle with Ereco="<< reco_energy << "\t Zenith Variation:" << abs(zenith-true_zenith) << "\t Omega Variation:" << abs(reco_phi-true_phi) <<endl; // << "\t Nhits:" << no_hits 
    cout << "Run: " << run << "\t Event ID:" << event_id << "\t Index:" << index << "\t Flav:" << flav << "\t Interaction Type:"<< int(interaction_type)<< "\t Cos_Zen:" << cos_zen << "\n" << endl;
    indexes_upgoing[3]=indexes_upgoing[3]+1;}
  else if (((reco_energy)<31)&&(true_energy>=1000) && (true_energy<=1260)&&(indexes_upgoing[4]<1)){
    cout << "For particle inside the hslice for upgoing events, the following identifications:" << endl;
    cout << "With exact True Energy:" << true_energy << endl; 
    cout << "High Energy Particle with Ereco="<< reco_energy << "\t Zenith Variation:" << abs(zenith-true_zenith) << "\t Omega Variation:" << abs(reco_phi-true_phi) <<endl; // << "\t Nhits:" << no_hits 
    cout << "Run: " << run << "\t Event ID:" << event_id << "\t Index:" << index << "\t Flav:" << flav << "\t Interaction Type:"<< int(interaction_type)<<  "\t Cos_Zen:" << cos_zen << "\n" << endl;
    indexes_upgoing[4]=indexes_upgoing[4]+1;}
  else if (((reco_energy)>31)&&(true_energy>=1000) && (true_energy<=1260)&&(indexes_upgoing[5]<1)){
    cout << "For particle inside the hslice for upgoing events, the following identifications:" << endl;
    cout << "With exact True Energy:" << true_energy << endl; 
    cout << "High Energy Particle with Ereco="<< reco_energy << "\t Zenith Variation:" << abs(zenith-true_zenith) << "\t Omega Variation:" << abs(reco_phi-true_phi) <<endl; // << "\t Nhits:" << no_hits 
    cout << "Run: " << run << "\t Event ID:" << event_id << "\t Index:" << index << "\t Flav:" << flav << "\t Interaction Type:"<< int(interaction_type)<<  "\t Cos_Zen:" << cos_zen << "\n" << endl;
    indexes_upgoing[5]=indexes_upgoing[5]+1;} //}



diff_energy= (true_energy-reco_energy)/true_energy;
h_mc_atm_nu_upgoing_diff_energy-> Fill(diff_energy,w3_osci);
h_mc_atm_nu_upgoing_diff_energy_cos_zen ->Fill(zenith,diff_energy,w3_osci);
h_mc_atm_nu_upgoing_no_hits->Fill(no_hits,w3_osci);
h_mc_atm_nu_upgoing_no_trig_hits->Fill(no_trig_hits,w3_osci);
h_mc_atm_nu_upgoing_no_cher_hits->Fill(no_cher_hits,w3_osci);
h_mc_atm_nu_upgoing_no_trig_cher_hits->Fill(no_trig_cher_hits,w3_osci); 
h_mc_atm_nu_upgoing_no_hit_doms->Fill(no_doms_hit,w3_osci); 
h_mc_atm_nu_upgoing_no_trig_doms->Fill(no_doms_trig_hit,w3_osci); 
h_mc_atm_nu_upgoing_no_cher_doms->Fill(no_doms_cher_hit,w3_osci);
h_mc_atm_nu_upgoing_no_trig_cher_doms->Fill(no_doms_trig_cher_hit,w3_osci);
h_mc_atm_nu_upgoing_no_trig_dus->Fill(no_dus_trig_hit,w3_osci);
h_mc_atm_nu_upgoing_no_cher_dus->Fill(no_dus_cher_hit,w3_osci);
h_mc_atm_nu_upgoing_no_trig_cher_dus->Fill(no_dus_trig_cher_hit,w3_osci);
h_mc_atm_nu_upgoing_zenith->Fill(zenith,w3_osci);
h_mc_atm_nu_upgoing_true_zenith->Fill(true_zenith,w3_osci);
h_mc_atm_nu_upgoing_cos_zenith->Fill(cos_zen,w3_osci);
h_mc_atm_nu_upgoing_true_cos_zen->Fill(true_cos_zen,w3_osci);
h_mc_atm_nu_upgoing_max_lik_dist->Fill(max_lik,w3_osci);
h_mc_atm_nu_upgoing_log_lik_dist->Fill(log_lik,w3_osci);
h_mc_atm_nu_upgoing_true_energy->Fill(TMath::Log10(true_energy),w3_osci);
h_mc_atm_nu_upgoing_true_energy_no_log->Fill(true_energy,w3_osci);
h_mc_atm_nu_upgoing_reco_energy->Fill(TMath::Log10(reco_energy),w3_osci);
h_mc_atm_nu_upgoing_E_reco_E_true_rec_zen_all ->Fill(TMath::Log10(true_energy),TMath::Log10(reco_energy),w3_osci);
/*if (zenith<30){
h_mc_atm_nu_upgoing_E_reco_E_true_rec_zen_30_all ->Fill(TMath::Log10(true_energy),TMath::Log10(reco_energy),w3_osci);
}
else if ((zenith)>60 && (zenith<120)){
h_mc_atm_nu_upgoing_E_reco_E_true_rec_zen_120_all ->Fill(TMath::Log10(true_energy),TMath::Log10(reco_energy),w3_osci);
}
else if (zenith>150){
h_mc_atm_nu_upgoing_E_reco_E_true_rec_zen_150_all -> Fill (TMath::Log10(true_energy),TMath::Log10(reco_energy),w3_osci);
}*/
h_mc_atm_nu_upgoing_reco_vertex_pos->Fill(reco_vrtx_r,reco_vrtx_z,w3_osci);
h_mc_atm_nu_upgoing_reco_vrtx_r->Fill(reco_vrtx_r,w3_osci);
h_mc_atm_nu_upgoing_reco_vrtx_x->Fill(reco_vrtx_x,w3_osci);
h_mc_atm_nu_upgoing_reco_vrtx_y->Fill(reco_vrtx_y,w3_osci);
h_mc_atm_nu_upgoing_reco_vrtx_z->Fill(reco_vrtx_z,w3_osci);
h_mc_atm_nu_upgoing_Nhits->Fill(Nhits,w3_osci);
h_mc_atm_nu_upgoing_beta0->Fill(beta0,w3_osci);
h_mc_atm_nu_upgoing_Qhits->Fill(Qhits,w3_osci);
h_mc_atm_nu_upgoing_trklength->Fill(TrkLength,w3_osci);
h_mc_atm_nu_upgoing_d_closest->Fill(d_closest,w3_osci);
h_mc_atm_nu_upgoing_z_closest->Fill(z_closest,w3_osci);
h_mc_atm_nu_upgoing_mean_z_hits->Fill(mean_z_hits,w3_osci);
h_mc_atm_nu_upgoing_mean_z_trig_hits->Fill(mean_z_trig_hits,w3_osci);
h_mc_atm_nu_upgoing_mean_z_cher_hits->Fill(mean_z_cher_hits,w3_osci);
h_mc_atm_nu_upgoing_mean_z_trig_cher_hits->Fill(mean_z_trig_cher_hits,w3_osci);
h_mc_atm_nu_upgoing_ratio_hits_trig_over_all->Fill(trig_hits_over_all,w3_osci);
h_mc_atm_nu_upgoing_ratio_hits_cher_over_all->Fill(cher_hits_over_all,w3_osci);
h_mc_atm_nu_upgoing_ratio_hits_trig_cher_over_all->Fill(trig_cher_hits_over_all,w3_osci);
h_mc_atm_nu_upgoing_Qup_m_Qdn_JGandalf->Fill(Qup_m_Qdn_JGandalf,w3_osci);
h_mc_atm_nu_upgoing_max_trig_tot->Fill(max_tot_trig,w3_osci);
h_mc_atm_nu_upgoing_early_trig_10->Fill(early_trig_10,w3_osci);
h_mc_atm_nu_upgoing_Dn_m_Up_hits->Fill(Dn_m_Up_hits,w3_osci);
h_mc_atm_nu_upgoing_Dn_m_Up_trig_hits->Fill(Dn_m_Up_trig_hits,w3_osci);
h_mc_atm_nu_upgoing_Dn_m_Up_cher_hits->Fill(Dn_m_Up_cher_hits,w3_osci);
h_mc_atm_nu_upgoing_Dn_m_Up_trig_cher_hits->Fill(Dn_m_Up_trig_cher_hits,w3_osci);
//Energy Slicies Section
//----------------- Reco Slice Section ------------------
//----------------- True Energy Section----------------
if ((true_energy)>10 && (true_energy)<13){
if (reco_energy<31) {
h_mc_atm_nu_upgoing_lslice_le_mean_z_hits-> Fill(mean_z_hits,w3_osci);
h_mc_atm_nu_upgoing_lslice_le_reco_vrtx_r -> Fill(reco_vrtx_r,w3_osci);
h_mc_atm_nu_upgoing_lslice_le_trklength ->Fill(TrkLength,w3_osci);
h_mc_atm_nu_upgoing_lslice_le_zenith -> Fill(zenith,w3_osci);
h_mc_atm_nu_upgoing_lslice_le_reco_vrtx_z -> Fill(reco_vrtx_z,w3_osci);
h_mc_atm_nu_upgoing_lslice_le_reco_vertex_pos->Fill(reco_vrtx_r,reco_vrtx_z,w3_osci);
h_mc_atm_nu_upgoing_lslice_le_no_hit_doms -> Fill(no_doms_hit,w3_osci);
h_mc_atm_nu_upgoing_lslice_le_no_cher_doms -> Fill(no_doms_cher_hit,w3_osci);
h_mc_atm_nu_upgoing_lslice_le_Nhits-> Fill(Nhits,w3_osci);
h_mc_atm_nu_upgoing_lslice_le_beta0 -> Fill(beta0,w3_osci);
h_mc_atm_nu_upgoing_lslice_le_Qhits -> Fill(Qhits,w3_osci);
h_mc_atm_nu_upgoing_lslice_le_reco_vrtx_z -> Fill(reco_vrtx_z,w3_osci);
h_mc_atm_nu_upgoing_lslice_le_true_phi -> Fill(true_phi, w3_osci);
h_mc_atm_nu_upgoing_lslice_le_reco_phi -> Fill(reco_phi, w3_osci);
h_mc_atm_nu_upgoing_lslice_le_bjorken_y -> Fill(bjorken_y, w3_osci);
h_mc_atm_nu_upgoing_lslice_le_d_closest -> Fill(d_closest,w3_osci);
h_mc_atm_nu_upgoing_lslice_le_z_closest -> Fill(z_closest,w3_osci);

}
else if (reco_energy>31){
h_mc_atm_nu_upgoing_lslice_he_mean_z_hits-> Fill(mean_z_hits,w3_osci);
h_mc_atm_nu_upgoing_lslice_he_reco_vrtx_r-> Fill(reco_vrtx_r,w3_osci);
h_mc_atm_nu_upgoing_lslice_he_reco_vertex_pos->Fill(reco_vrtx_r,reco_vrtx_z,w3_osci);
h_mc_atm_nu_upgoing_lslice_he_trklength ->Fill(TrkLength,w3_osci);
h_mc_atm_nu_upgoing_lslice_he_zenith -> Fill(zenith,w3_osci);
h_mc_atm_nu_upgoing_lslice_he_reco_vrtx_z -> Fill(reco_vrtx_z,w3_osci);
h_mc_atm_nu_upgoing_lslice_he_no_hit_doms -> Fill(no_doms_hit,w3_osci);
h_mc_atm_nu_upgoing_lslice_he_no_cher_doms -> Fill(no_doms_cher_hit,w3_osci);
h_mc_atm_nu_upgoing_lslice_he_Nhits-> Fill(Nhits,w3_osci);
h_mc_atm_nu_upgoing_lslice_he_beta0 -> Fill(beta0,w3_osci);
h_mc_atm_nu_upgoing_lslice_he_Qhits -> Fill(Qhits,w3_osci);
h_mc_atm_nu_upgoing_lslice_he_reco_vrtx_z -> Fill(reco_vrtx_z,w3_osci);
h_mc_atm_nu_upgoing_lslice_he_true_phi -> Fill(true_phi, w3_osci);
h_mc_atm_nu_upgoing_lslice_he_reco_phi -> Fill(reco_phi, w3_osci);
h_mc_atm_nu_upgoing_lslice_he_bjorken_y -> Fill(bjorken_y, w3_osci);
h_mc_atm_nu_upgoing_lslice_he_true_phi -> Fill(true_phi, w3_osci);
h_mc_atm_nu_upgoing_lslice_he_reco_phi -> Fill(reco_phi, w3_osci);
h_mc_atm_nu_upgoing_lslice_he_bjorken_y -> Fill(bjorken_y, w3_osci);
h_mc_atm_nu_upgoing_lslice_he_d_closest -> Fill(d_closest,w3_osci);
h_mc_atm_nu_upgoing_lslice_he_z_closest -> Fill(z_closest,w3_osci);
}

h_mc_atm_nu_upgoing_lslice_diff_energy-> Fill(diff_energy,w3_osci);
h_mc_atm_nu_upgoing_lslice_diff_energy_cos_zen ->Fill(zenith,diff_energy,w3_osci);
h_mc_atm_nu_upgoing_lslice_no_hits->Fill(no_hits,w3_osci);
h_mc_atm_nu_upgoing_lslice_no_trig_hits->Fill(no_trig_hits,w3_osci);
h_mc_atm_nu_upgoing_lslice_no_cher_hits->Fill(no_cher_hits,w3_osci);
h_mc_atm_nu_upgoing_lslice_no_trig_cher_hits->Fill(no_trig_cher_hits,w3_osci); 
h_mc_atm_nu_upgoing_lslice_no_hit_doms->Fill(no_doms_hit,w3_osci); 
h_mc_atm_nu_upgoing_lslice_no_trig_doms->Fill(no_doms_trig_hit,w3_osci); 
h_mc_atm_nu_upgoing_lslice_no_cher_doms->Fill(no_doms_cher_hit,w3_osci);
h_mc_atm_nu_upgoing_lslice_no_trig_cher_doms->Fill(no_doms_trig_cher_hit,w3_osci);
h_mc_atm_nu_upgoing_lslice_no_trig_dus->Fill(no_dus_trig_hit,w3_osci);
h_mc_atm_nu_upgoing_lslice_no_cher_dus->Fill(no_dus_cher_hit,w3_osci);
h_mc_atm_nu_upgoing_lslice_no_trig_cher_dus->Fill(no_dus_trig_cher_hit,w3_osci);
h_mc_atm_nu_upgoing_lslice_zenith->Fill(zenith,w3_osci);
h_mc_atm_nu_upgoing_lslice_true_zenith->Fill(true_zenith,w3_osci);
h_mc_atm_nu_upgoing_lslice_cos_zenith->Fill(cos_zen,w3_osci);
h_mc_atm_nu_upgoing_lslice_true_cos_zen->Fill(true_cos_zen,w3_osci);
h_mc_atm_nu_upgoing_lslice_max_lik_dist->Fill(max_lik,w3_osci);
h_mc_atm_nu_upgoing_lslice_log_lik_dist->Fill(log_lik,w3_osci);
h_mc_atm_nu_upgoing_lslice_true_energy->Fill(TMath::Log10(true_energy),w3_osci);
h_mc_atm_nu_upgoing_lslice_true_energy_no_log->Fill(true_energy,w3_osci);
h_mc_atm_nu_upgoing_lslice_reco_energy->Fill(TMath::Log10(reco_energy),w3_osci);
h_mc_atm_nu_upgoing_lslice_reco_vertex_pos->Fill(reco_vrtx_r,reco_vrtx_z,w3_osci);
h_mc_atm_nu_upgoing_lslice_reco_vrtx_r->Fill(reco_vrtx_r,w3_osci);
h_mc_atm_nu_upgoing_lslice_reco_vrtx_x->Fill(reco_vrtx_x,w3_osci);
h_mc_atm_nu_upgoing_lslice_reco_vrtx_y->Fill(reco_vrtx_y,w3_osci);
h_mc_atm_nu_upgoing_lslice_reco_vrtx_z->Fill(reco_vrtx_z,w3_osci);
h_mc_atm_nu_upgoing_lslice_Nhits->Fill(Nhits,w3_osci);
h_mc_atm_nu_upgoing_lslice_beta0->Fill(beta0,w3_osci);
h_mc_atm_nu_upgoing_lslice_Qhits->Fill(Qhits,w3_osci);
h_mc_atm_nu_upgoing_lslice_trklength->Fill(TrkLength,w3_osci);
h_mc_atm_nu_upgoing_lslice_d_closest->Fill(d_closest,w3_osci);
h_mc_atm_nu_upgoing_lslice_z_closest->Fill(z_closest,w3_osci);
h_mc_atm_nu_upgoing_lslice_mean_z_hits->Fill(mean_z_hits,w3_osci);
h_mc_atm_nu_upgoing_lslice_mean_z_trig_hits->Fill(mean_z_trig_hits,w3_osci);
h_mc_atm_nu_upgoing_lslice_mean_z_cher_hits->Fill(mean_z_cher_hits,w3_osci);
h_mc_atm_nu_upgoing_lslice_mean_z_trig_cher_hits->Fill(mean_z_trig_cher_hits,w3_osci);
h_mc_atm_nu_upgoing_lslice_ratio_hits_trig_over_all->Fill(trig_hits_over_all,w3_osci);
h_mc_atm_nu_upgoing_lslice_ratio_hits_cher_over_all->Fill(cher_hits_over_all,w3_osci);
h_mc_atm_nu_upgoing_lslice_ratio_hits_trig_cher_over_all->Fill(trig_cher_hits_over_all,w3_osci);
h_mc_atm_nu_upgoing_lslice_Qup_m_Qdn_JGandalf->Fill(Qup_m_Qdn_JGandalf,w3_osci);
h_mc_atm_nu_upgoing_lslice_max_trig_tot->Fill(max_tot_trig,w3_osci);
h_mc_atm_nu_upgoing_lslice_early_trig_10->Fill(early_trig_10,w3_osci);
h_mc_atm_nu_upgoing_lslice_Dn_m_Up_hits->Fill(Dn_m_Up_hits,w3_osci);
h_mc_atm_nu_upgoing_lslice_Dn_m_Up_trig_hits->Fill(Dn_m_Up_trig_hits,w3_osci);
h_mc_atm_nu_upgoing_lslice_Dn_m_Up_cher_hits->Fill(Dn_m_Up_cher_hits,w3_osci);
h_mc_atm_nu_upgoing_lslice_Dn_m_Up_trig_cher_hits->Fill(Dn_m_Up_trig_cher_hits,w3_osci);
}
if ((true_energy)>100 && (true_energy)<126){
if (reco_energy<31) {
h_mc_atm_nu_upgoing_mslice_le_mean_z_hits-> Fill(mean_z_hits,w3_osci);
h_mc_atm_nu_upgoing_mslice_le_reco_vrtx_r -> Fill(reco_vrtx_r,w3_osci);
h_mc_atm_nu_upgoing_mslice_le_trklength ->Fill(TrkLength,w3_osci);
h_mc_atm_nu_upgoing_mslice_le_zenith -> Fill(zenith,w3_osci);
h_mc_atm_nu_upgoing_mslice_le_no_hit_doms -> Fill(no_doms_hit,w3_osci);
h_mc_atm_nu_upgoing_mslice_le_no_cher_doms -> Fill(no_doms_cher_hit,w3_osci);
h_mc_atm_nu_upgoing_mslice_le_Nhits-> Fill(Nhits,w3_osci);
h_mc_atm_nu_upgoing_mslice_le_beta0 -> Fill(beta0,w3_osci);
h_mc_atm_nu_upgoing_mslice_le_Qhits -> Fill(Qhits,w3_osci);
h_mc_atm_nu_upgoing_mslice_le_reco_vrtx_z -> Fill(reco_vrtx_z,w3_osci);
h_mc_atm_nu_upgoing_mslice_le_true_phi -> Fill(true_phi, w3_osci);
h_mc_atm_nu_upgoing_mslice_le_reco_phi -> Fill(reco_phi, w3_osci);
h_mc_atm_nu_upgoing_mslice_le_bjorken_y -> Fill(bjorken_y, w3_osci);
}
else if ((reco_energy>31)&&(reco_energy<65)){
h_mc_atm_nu_upgoing_mslice_me_mean_z_hits-> Fill(mean_z_hits,w3_osci);
h_mc_atm_nu_upgoing_mslice_me_reco_vrtx_r-> Fill(reco_vrtx_r,w3_osci);
h_mc_atm_nu_upgoing_mslice_me_reco_vertex_pos->Fill(reco_vrtx_r,reco_vrtx_z,w3_osci);
h_mc_atm_nu_upgoing_mslice_me_trklength ->Fill(TrkLength,w3_osci);
h_mc_atm_nu_upgoing_mslice_me_zenith -> Fill(zenith,w3_osci);
h_mc_atm_nu_upgoing_mslice_me_no_hit_doms -> Fill(no_doms_hit,w3_osci);
h_mc_atm_nu_upgoing_mslice_me_no_cher_doms -> Fill(no_doms_cher_hit,w3_osci);
h_mc_atm_nu_upgoing_mslice_me_Nhits-> Fill(Nhits,w3_osci);
h_mc_atm_nu_upgoing_mslice_me_beta0 -> Fill(beta0,w3_osci);
h_mc_atm_nu_upgoing_mslice_me_Qhits -> Fill(Qhits,w3_osci);
h_mc_atm_nu_upgoing_mslice_me_reco_vrtx_z -> Fill(reco_vrtx_z,w3_osci);
h_mc_atm_nu_upgoing_mslice_me_true_phi -> Fill(true_phi, w3_osci);
h_mc_atm_nu_upgoing_mslice_me_reco_phi -> Fill(reco_phi, w3_osci);
h_mc_atm_nu_upgoing_mslice_me_bjorken_y -> Fill(bjorken_y, w3_osci);
h_mc_atm_nu_upgoing_mslice_me_d_closest -> Fill(d_closest,w3_osci);
h_mc_atm_nu_upgoing_mslice_me_z_closest -> Fill(z_closest,w3_osci);
}
else {
h_mc_atm_nu_upgoing_mslice_he_mean_z_hits-> Fill(mean_z_hits,w3_osci);
h_mc_atm_nu_upgoing_mslice_he_reco_vrtx_r-> Fill(reco_vrtx_r,w3_osci);
h_mc_atm_nu_upgoing_mslice_he_reco_vertex_pos->Fill(reco_vrtx_r,reco_vrtx_z,w3_osci);
h_mc_atm_nu_upgoing_mslice_he_trklength ->Fill(TrkLength,w3_osci);
h_mc_atm_nu_upgoing_mslice_he_zenith -> Fill(zenith,w3_osci);
h_mc_atm_nu_upgoing_mslice_he_no_hit_doms -> Fill(no_doms_hit,w3_osci);
h_mc_atm_nu_upgoing_mslice_he_no_cher_doms -> Fill(no_doms_cher_hit,w3_osci);
h_mc_atm_nu_upgoing_mslice_he_Nhits-> Fill(Nhits,w3_osci);
h_mc_atm_nu_upgoing_mslice_he_beta0 -> Fill(beta0,w3_osci);
h_mc_atm_nu_upgoing_mslice_he_Qhits -> Fill(Qhits,w3_osci);
h_mc_atm_nu_upgoing_mslice_he_reco_vrtx_z -> Fill(reco_vrtx_z,w3_osci);
h_mc_atm_nu_upgoing_mslice_he_true_phi -> Fill(true_phi, w3_osci);
h_mc_atm_nu_upgoing_mslice_he_reco_phi -> Fill(reco_phi, w3_osci);
h_mc_atm_nu_upgoing_mslice_he_bjorken_y -> Fill(bjorken_y, w3_osci);
h_mc_atm_nu_upgoing_mslice_he_d_closest -> Fill(d_closest,w3_osci);
h_mc_atm_nu_upgoing_mslice_he_z_closest -> Fill(z_closest,w3_osci);
}

h_mc_atm_nu_upgoing_mslice_diff_energy-> Fill(diff_energy,w3_osci);
h_mc_atm_nu_upgoing_mslice_diff_energy_cos_zen ->Fill(zenith,diff_energy,w3_osci);
h_mc_atm_nu_upgoing_mslice_no_hits->Fill(no_hits,w3_osci);
h_mc_atm_nu_upgoing_mslice_no_trig_hits->Fill(no_trig_hits,w3_osci);
h_mc_atm_nu_upgoing_mslice_no_cher_hits->Fill(no_cher_hits,w3_osci);
h_mc_atm_nu_upgoing_mslice_no_trig_cher_hits->Fill(no_trig_cher_hits,w3_osci); 
h_mc_atm_nu_upgoing_mslice_no_hit_doms->Fill(no_doms_hit,w3_osci); 
h_mc_atm_nu_upgoing_mslice_no_trig_doms->Fill(no_doms_trig_hit,w3_osci); 
h_mc_atm_nu_upgoing_mslice_no_cher_doms->Fill(no_doms_cher_hit,w3_osci);
h_mc_atm_nu_upgoing_mslice_no_trig_cher_doms->Fill(no_doms_trig_cher_hit,w3_osci);
h_mc_atm_nu_upgoing_mslice_no_trig_dus->Fill(no_dus_trig_hit,w3_osci);
h_mc_atm_nu_upgoing_mslice_no_cher_dus->Fill(no_dus_cher_hit,w3_osci);
h_mc_atm_nu_upgoing_mslice_no_trig_cher_dus->Fill(no_dus_trig_cher_hit,w3_osci);
h_mc_atm_nu_upgoing_mslice_zenith->Fill(zenith,w3_osci);
h_mc_atm_nu_upgoing_mslice_true_zenith->Fill(true_zenith,w3_osci);
h_mc_atm_nu_upgoing_mslice_cos_zenith->Fill(cos_zen,w3_osci);
h_mc_atm_nu_upgoing_mslice_true_cos_zen->Fill(true_cos_zen,w3_osci);
h_mc_atm_nu_upgoing_mslice_max_lik_dist->Fill(max_lik,w3_osci);
h_mc_atm_nu_upgoing_mslice_log_lik_dist->Fill(log_lik,w3_osci);
h_mc_atm_nu_upgoing_mslice_true_energy->Fill(TMath::Log10(true_energy),w3_osci);
h_mc_atm_nu_upgoing_mslice_true_energy_no_log->Fill(true_energy,w3_osci);
h_mc_atm_nu_upgoing_mslice_reco_energy->Fill(TMath::Log10(reco_energy),w3_osci);
h_mc_atm_nu_upgoing_mslice_reco_vertex_pos->Fill(reco_vrtx_r,reco_vrtx_z,w3_osci);
h_mc_atm_nu_upgoing_mslice_reco_vrtx_r->Fill(reco_vrtx_r,w3_osci);
h_mc_atm_nu_upgoing_mslice_reco_vrtx_x->Fill(reco_vrtx_x,w3_osci);
h_mc_atm_nu_upgoing_mslice_reco_vrtx_y->Fill(reco_vrtx_y,w3_osci);
h_mc_atm_nu_upgoing_mslice_reco_vrtx_z->Fill(reco_vrtx_z,w3_osci);
h_mc_atm_nu_upgoing_mslice_Nhits->Fill(Nhits,w3_osci);
h_mc_atm_nu_upgoing_mslice_beta0->Fill(beta0,w3_osci);
h_mc_atm_nu_upgoing_mslice_Qhits->Fill(Qhits,w3_osci);
h_mc_atm_nu_upgoing_mslice_trklength->Fill(TrkLength,w3_osci);
h_mc_atm_nu_upgoing_mslice_d_closest->Fill(d_closest,w3_osci);
h_mc_atm_nu_upgoing_mslice_z_closest->Fill(z_closest,w3_osci);
h_mc_atm_nu_upgoing_mslice_mean_z_hits->Fill(mean_z_hits,w3_osci);
h_mc_atm_nu_upgoing_mslice_mean_z_trig_hits->Fill(mean_z_trig_hits,w3_osci);
h_mc_atm_nu_upgoing_mslice_mean_z_cher_hits->Fill(mean_z_cher_hits,w3_osci);
h_mc_atm_nu_upgoing_mslice_mean_z_trig_cher_hits->Fill(mean_z_trig_cher_hits,w3_osci);
h_mc_atm_nu_upgoing_mslice_ratio_hits_trig_over_all->Fill(trig_hits_over_all,w3_osci);
h_mc_atm_nu_upgoing_mslice_ratio_hits_cher_over_all->Fill(cher_hits_over_all,w3_osci);
h_mc_atm_nu_upgoing_mslice_ratio_hits_trig_cher_over_all->Fill(trig_cher_hits_over_all,w3_osci);
h_mc_atm_nu_upgoing_mslice_Qup_m_Qdn_JGandalf->Fill(Qup_m_Qdn_JGandalf,w3_osci);
h_mc_atm_nu_upgoing_mslice_max_trig_tot->Fill(max_tot_trig,w3_osci);
h_mc_atm_nu_upgoing_mslice_early_trig_10->Fill(early_trig_10,w3_osci);
h_mc_atm_nu_upgoing_mslice_Dn_m_Up_hits->Fill(Dn_m_Up_hits,w3_osci);
h_mc_atm_nu_upgoing_mslice_Dn_m_Up_trig_hits->Fill(Dn_m_Up_trig_hits,w3_osci);
h_mc_atm_nu_upgoing_mslice_Dn_m_Up_cher_hits->Fill(Dn_m_Up_cher_hits,w3_osci);
h_mc_atm_nu_upgoing_mslice_Dn_m_Up_trig_cher_hits->Fill(Dn_m_Up_trig_cher_hits,w3_osci);
}
if ((true_energy)>1000 && (true_energy)<1260){
if (reco_energy<31) { //100
h_mc_atm_nu_upgoing_hslice_le_mean_z_hits-> Fill(mean_z_hits,w3_osci);
h_mc_atm_nu_upgoing_hslice_le_reco_vrtx_r -> Fill(reco_vrtx_r,w3_osci);
h_mc_atm_nu_upgoing_hslice_le_trklength ->Fill(TrkLength,w3_osci);
h_mc_atm_nu_upgoing_hslice_le_zenith -> Fill(zenith,w3_osci);
h_mc_atm_nu_upgoing_hslice_le_no_hit_doms -> Fill(no_doms_hit,w3_osci);
h_mc_atm_nu_upgoing_hslice_le_no_cher_doms -> Fill(no_doms_cher_hit,w3_osci);
h_mc_atm_nu_upgoing_hslice_le_Nhits-> Fill(Nhits,w3_osci);
h_mc_atm_nu_upgoing_hslice_le_beta0 -> Fill(beta0,w3_osci);
h_mc_atm_nu_upgoing_hslice_le_Qhits -> Fill(Qhits,w3_osci);
h_mc_atm_nu_upgoing_hslice_le_reco_vrtx_z -> Fill(reco_vrtx_z,w3_osci);
h_mc_atm_nu_upgoing_hslice_le_true_phi -> Fill(true_phi, w3_osci);
h_mc_atm_nu_upgoing_hslice_le_reco_phi -> Fill(reco_phi, w3_osci);
h_mc_atm_nu_upgoing_hslice_le_bjorken_y -> Fill(bjorken_y, w3_osci);
h_mc_atm_nu_upgoing_hslice_le_d_closest -> Fill(d_closest,w3_osci);
h_mc_atm_nu_upgoing_hslice_le_z_closest -> Fill(z_closest,w3_osci);

}
else {
h_mc_atm_nu_upgoing_hslice_he_mean_z_hits-> Fill(mean_z_hits,w3_osci);
h_mc_atm_nu_upgoing_hslice_he_reco_vrtx_r-> Fill(reco_vrtx_r,w3_osci);
h_mc_atm_nu_upgoing_hslice_he_reco_vertex_pos->Fill(reco_vrtx_r,reco_vrtx_z,w3_osci);
h_mc_atm_nu_upgoing_hslice_he_trklength ->Fill(TrkLength,w3_osci);
h_mc_atm_nu_upgoing_hslice_he_zenith -> Fill(zenith,w3_osci);
h_mc_atm_nu_upgoing_hslice_he_no_hit_doms -> Fill(no_doms_hit,w3_osci);
h_mc_atm_nu_upgoing_hslice_he_no_cher_doms -> Fill(no_doms_cher_hit,w3_osci);
h_mc_atm_nu_upgoing_hslice_he_Nhits-> Fill(Nhits,w3_osci);
h_mc_atm_nu_upgoing_hslice_he_beta0 -> Fill(beta0,w3_osci);
h_mc_atm_nu_upgoing_hslice_he_Qhits -> Fill(Qhits,w3_osci);
h_mc_atm_nu_upgoing_hslice_he_reco_vrtx_z -> Fill(reco_vrtx_z,w3_osci);
h_mc_atm_nu_upgoing_hslice_he_true_phi -> Fill(true_phi, w3_osci);
h_mc_atm_nu_upgoing_hslice_he_reco_phi -> Fill(reco_phi, w3_osci);
h_mc_atm_nu_upgoing_hslice_he_bjorken_y -> Fill(bjorken_y, w3_osci);
h_mc_atm_nu_upgoing_hslice_he_d_closest -> Fill(d_closest,w3_osci);
h_mc_atm_nu_upgoing_hslice_he_z_closest -> Fill(z_closest,w3_osci);


}
h_mc_atm_nu_upgoing_hslice_diff_energy-> Fill(diff_energy,w3_osci);
h_mc_atm_nu_upgoing_hslice_diff_energy_cos_zen ->Fill(zenith,diff_energy,w3_osci);
h_mc_atm_nu_upgoing_hslice_no_hits->Fill(no_hits,w3_osci);
h_mc_atm_nu_upgoing_hslice_no_trig_hits->Fill(no_trig_hits,w3_osci);
h_mc_atm_nu_upgoing_hslice_no_cher_hits->Fill(no_cher_hits,w3_osci);
h_mc_atm_nu_upgoing_hslice_no_trig_cher_hits->Fill(no_trig_cher_hits,w3_osci); 
h_mc_atm_nu_upgoing_hslice_no_hit_doms->Fill(no_doms_hit,w3_osci); 
h_mc_atm_nu_upgoing_hslice_no_trig_doms->Fill(no_doms_trig_hit,w3_osci); 
h_mc_atm_nu_upgoing_hslice_no_cher_doms->Fill(no_doms_cher_hit,w3_osci);
h_mc_atm_nu_upgoing_hslice_no_trig_cher_doms->Fill(no_doms_trig_cher_hit,w3_osci);
h_mc_atm_nu_upgoing_hslice_no_trig_dus->Fill(no_dus_trig_hit,w3_osci);
h_mc_atm_nu_upgoing_hslice_no_cher_dus->Fill(no_dus_cher_hit,w3_osci);
h_mc_atm_nu_upgoing_hslice_no_trig_cher_dus->Fill(no_dus_trig_cher_hit,w3_osci);
h_mc_atm_nu_upgoing_hslice_zenith->Fill(zenith,w3_osci);
h_mc_atm_nu_upgoing_hslice_true_zenith->Fill(true_zenith,w3_osci);
h_mc_atm_nu_upgoing_hslice_cos_zenith->Fill(cos_zen,w3_osci);
h_mc_atm_nu_upgoing_hslice_true_cos_zen->Fill(true_cos_zen,w3_osci);
h_mc_atm_nu_upgoing_hslice_max_lik_dist->Fill(max_lik,w3_osci);
h_mc_atm_nu_upgoing_hslice_log_lik_dist->Fill(log_lik,w3_osci);
h_mc_atm_nu_upgoing_hslice_true_energy->Fill(TMath::Log10(true_energy),w3_osci);
h_mc_atm_nu_upgoing_hslice_true_energy_no_log->Fill(true_energy,w3_osci);
h_mc_atm_nu_upgoing_hslice_reco_energy->Fill(TMath::Log10(reco_energy),w3_osci);
h_mc_atm_nu_upgoing_hslice_reco_vertex_pos->Fill(reco_vrtx_r,reco_vrtx_z,w3_osci);
h_mc_atm_nu_upgoing_hslice_reco_vrtx_r->Fill(reco_vrtx_r,w3_osci);
h_mc_atm_nu_upgoing_hslice_reco_vrtx_x->Fill(reco_vrtx_x,w3_osci);
h_mc_atm_nu_upgoing_hslice_reco_vrtx_y->Fill(reco_vrtx_y,w3_osci);
h_mc_atm_nu_upgoing_hslice_reco_vrtx_z->Fill(reco_vrtx_z,w3_osci);
h_mc_atm_nu_upgoing_hslice_Nhits->Fill(Nhits,w3_osci);
h_mc_atm_nu_upgoing_hslice_beta0->Fill(beta0,w3_osci);
h_mc_atm_nu_upgoing_hslice_Qhits->Fill(Qhits,w3_osci);
h_mc_atm_nu_upgoing_hslice_trklength->Fill(TrkLength,w3_osci);
h_mc_atm_nu_upgoing_hslice_d_closest->Fill(d_closest,w3_osci);
h_mc_atm_nu_upgoing_hslice_z_closest->Fill(z_closest,w3_osci);
h_mc_atm_nu_upgoing_hslice_mean_z_hits->Fill(mean_z_hits,w3_osci);
h_mc_atm_nu_upgoing_hslice_mean_z_trig_hits->Fill(mean_z_trig_hits,w3_osci);
h_mc_atm_nu_upgoing_hslice_mean_z_cher_hits->Fill(mean_z_cher_hits,w3_osci);
h_mc_atm_nu_upgoing_hslice_mean_z_trig_cher_hits->Fill(mean_z_trig_cher_hits,w3_osci);
h_mc_atm_nu_upgoing_hslice_ratio_hits_trig_over_all->Fill(trig_hits_over_all,w3_osci);
h_mc_atm_nu_upgoing_hslice_ratio_hits_cher_over_all->Fill(cher_hits_over_all,w3_osci);
h_mc_atm_nu_upgoing_hslice_ratio_hits_trig_cher_over_all->Fill(trig_cher_hits_over_all,w3_osci);
h_mc_atm_nu_upgoing_hslice_Qup_m_Qdn_JGandalf->Fill(Qup_m_Qdn_JGandalf,w3_osci);
h_mc_atm_nu_upgoing_hslice_max_trig_tot->Fill(max_tot_trig,w3_osci);
h_mc_atm_nu_upgoing_hslice_early_trig_10->Fill(early_trig_10,w3_osci);
h_mc_atm_nu_upgoing_hslice_Dn_m_Up_hits->Fill(Dn_m_Up_hits,w3_osci);
h_mc_atm_nu_upgoing_hslice_Dn_m_Up_trig_hits->Fill(Dn_m_Up_trig_hits,w3_osci);
h_mc_atm_nu_upgoing_hslice_Dn_m_Up_cher_hits->Fill(Dn_m_Up_cher_hits,w3_osci);
h_mc_atm_nu_upgoing_hslice_Dn_m_Up_trig_cher_hits->Fill(Dn_m_Up_trig_cher_hits,w3_osci);
h_mc_atm_nu_upgoing_hslice_trk_reco_energy -> Fill(reco_energy, TrkLength, w3_osci);
h_mc_atm_nu_upgoing_hslice_trk_true_energy -> Fill(true_energy, TrkLength, w3_osci);
}}
else if ((zenith<=120)&&(zenith>=60)){//for the horizontal condition

  /////////////////////////////////////////////////////////////////////////////////////////////
  //                           Event Data Display                                            //
  /////////////////////////////////////////////////////////////////////////////////////////////

//if ( i>= 2000000){
if (((reco_energy)<31)&&(true_energy>=10) && (true_energy<=13)&&(indexes_horizontal[0]<1)){
  cout << "For particle inside the lslice for horizontal events, the following identifications" << endl;
  cout << "With exact True Energy:" << true_energy << endl; 
  cout << "Low Energy Particle with Ereco="<< reco_energy << "\t Zenith Variation:" << abs(zenith-true_zenith) << "\t Omega Variation:" << abs(reco_phi-true_phi) <<endl; // << "\t Nhits:" << no_hits 
  cout << "Run: " << run << "\t Event ID:" << event_id << "\t Index:" << index << "\t Flav:" << flav << "\t Interaction Type:"<< int(interaction_type)<< "\t Cos_Zen:" << cos_zen << "\n" << endl;
  indexes_horizontal[0]=indexes_horizontal[0]+1;}
else if (((reco_energy)>31)&&(true_energy>=10) && (true_energy<=13)&&(indexes_horizontal[1]<1)){
  cout << "For particle inside the lslice for horizontal events, the following identifications" << endl;
  cout << "With exact True Energy:" << true_energy << endl;      
  cout << "Low Energy Particle with Ereco="<< reco_energy << "\t Zenith Variation:" << abs(zenith-true_zenith) << "\t Omega Variation:" << abs(reco_phi-true_phi) <<endl; // << "\t Nhits:" << no_hits 
  cout << "Run: " << run << "\t Event ID:" << event_id << "\t Index:" << index << "\t Flav:" << flav << "\t Interaction Type:"<< int(interaction_type)<< "\t Cos_Zen:" << cos_zen << "\n" << endl;
  indexes_horizontal[1]=indexes_horizontal[1]+1;}
else if (((reco_energy)<31)&&(true_energy>=100) && (true_energy<=126)&&(indexes_horizontal[2]<1)){
  cout << "For particle inside the mslice for horizontal events, the following identifications:" << endl;
  cout << "With exact True Energy:" << true_energy << endl; 
  cout << "Medium Energy Particle with Ereco="<< reco_energy << "\t Zenith Variation:" << abs(zenith-true_zenith) << "\t Omega Variation:" << abs(reco_phi-true_phi) <<endl; // << "\t Nhits:" << no_hits 
  cout << "Run: " << run << "\t Event ID:" << event_id << "\t Index:" << index << "\t Flav:" << flav << "\t Interaction Type:"<< int(interaction_type)<< "\t Cos_Zen:" << cos_zen <<"\n" << endl;
  indexes_horizontal[2]=indexes_horizontal[2]+1;}
else if (((reco_energy)>31)&&(true_energy>=100) && (true_energy<=126)&&(indexes_horizontal[3]<1)){
  cout << "For particle inside the mslice for horizontal events, the following identifications:" << endl;
  cout << "With exact True Energy:" << true_energy << endl; 
  cout << "Medium Energy Particle with Ereco="<< reco_energy << "\t Zenith Variation:" << abs(zenith-true_zenith) << "\t Omega Variation:" << abs(reco_phi-true_phi) <<endl; // << "\t Nhits:" << no_hits 
  cout << "Run: " << run << "\t Event ID:" << event_id << "\t Index:" << index << "\t Flav:" << flav << "\t Interaction Type:"<< int(interaction_type)<< "\t Cos_Zen:" << cos_zen <<"\n" << endl;
  indexes_horizontal[3]=indexes_horizontal[3]+1;}
else if (((reco_energy)<31)&&(true_energy>=1000) && (true_energy<=1260)&&(indexes_horizontal[4]<1)){
  cout << "For particle inside the hslice for horizontal events, the following identifications:" << endl;
  cout << "With exact True Energy:" << true_energy << endl; 
  cout << "High Energy Particle with Ereco="<< reco_energy << "\t Zenith Variation:" << abs(zenith-true_zenith) << "\t Omega Variation:" << abs(reco_phi-true_phi) <<endl; // << "\t Nhits:" << no_hits 
  cout << "Run: " << run << "\t Event ID:" << event_id << "\t Index:" << index << "\t Flav:" << flav << "\t Interaction Type:"<< int(interaction_type)<<  "\t Cos_Zen:" << cos_zen <<"\n" << endl;
  indexes_horizontal[4]=indexes_horizontal[4]+1;}
else if (((reco_energy)>31)&&(true_energy>=1000) && (true_energy<=1260)&&(indexes_horizontal[5]<1)){
  cout << "For particle inside the hslice for horizontal events, the following identifications:" << endl;
  cout << "With exact True Energy:" << true_energy << endl; 
  cout << "High Energy Particle with Ereco="<< reco_energy << "\t Zenith Variation:" << abs(zenith-true_zenith) << "\t Omega Variation:" << abs(reco_phi-true_phi) <<endl; // << "\t Nhits:" << no_hits 
  cout << "Run: " << run << "\t Event ID:" << event_id << "\t Index:" << index << "\t Flav:" << flav << "\t Interaction Type:"<< int(interaction_type)<<  "\t Cos_Zen:" << cos_zen <<"\n" << endl;
  indexes_horizontal[5]=indexes_horizontal[5]+1;}//}

  diff_energy= (true_energy-reco_energy)/true_energy;
  //cout << diff_energy << endl;
  h_mc_atm_nu_horizontal_diff_energy-> Fill(diff_energy,w3_osci);
  h_mc_atm_nu_horizontal_diff_energy_cos_zen ->Fill(zenith,diff_energy,w3_osci);
  h_mc_atm_nu_horizontal_no_hits->Fill(no_hits,w3_osci);
  h_mc_atm_nu_horizontal_no_trig_hits->Fill(no_trig_hits,w3_osci);
  h_mc_atm_nu_horizontal_no_cher_hits->Fill(no_cher_hits,w3_osci);
  h_mc_atm_nu_horizontal_no_trig_cher_hits->Fill(no_trig_cher_hits,w3_osci); 
  h_mc_atm_nu_horizontal_no_hit_doms->Fill(no_doms_hit,w3_osci); 
  h_mc_atm_nu_horizontal_no_trig_doms->Fill(no_doms_trig_hit,w3_osci); 
  h_mc_atm_nu_horizontal_no_cher_doms->Fill(no_doms_cher_hit,w3_osci);
  h_mc_atm_nu_horizontal_no_trig_cher_doms->Fill(no_doms_trig_cher_hit,w3_osci);
  h_mc_atm_nu_horizontal_no_trig_dus->Fill(no_dus_trig_hit,w3_osci);
  h_mc_atm_nu_horizontal_no_cher_dus->Fill(no_dus_cher_hit,w3_osci);
  h_mc_atm_nu_horizontal_no_trig_cher_dus->Fill(no_dus_trig_cher_hit,w3_osci);
  h_mc_atm_nu_horizontal_zenith->Fill(zenith,w3_osci);
  h_mc_atm_nu_horizontal_true_zenith->Fill(true_zenith,w3_osci);
  h_mc_atm_nu_horizontal_cos_zenith->Fill(cos_zen,w3_osci);
  h_mc_atm_nu_horizontal_true_cos_zen->Fill(true_cos_zen,w3_osci);
  h_mc_atm_nu_horizontal_max_lik_dist->Fill(max_lik,w3_osci);
h_mc_atm_nu_horizontal_log_lik_dist->Fill(log_lik,w3_osci);
h_mc_atm_nu_horizontal_true_energy->Fill(TMath::Log10(true_energy),w3_osci);
h_mc_atm_nu_horizontal_true_energy_no_log->Fill(true_energy,w3_osci);
h_mc_atm_nu_horizontal_reco_energy->Fill(TMath::Log10(reco_energy),w3_osci);
h_mc_atm_nu_horizontal_E_reco_E_true_rec_zen_all ->Fill(TMath::Log10(true_energy),TMath::Log10(reco_energy),w3_osci);
if (zenith<30){
h_mc_atm_nu_horizontal_E_reco_E_true_rec_zen_30_all ->Fill(TMath::Log10(true_energy),TMath::Log10(reco_energy),w3_osci);}
else if ((zenith)>60 && (zenith<120)){
h_mc_atm_nu_horizontal_E_reco_E_true_rec_zen_120_all ->Fill(TMath::Log10(true_energy),TMath::Log10(reco_energy),w3_osci);
}
else if (zenith>150){
h_mc_atm_nu_horizontal_E_reco_E_true_rec_zen_150_all -> Fill (TMath::Log10(true_energy),TMath::Log10(reco_energy),w3_osci);
}
h_mc_atm_nu_horizontal_reco_vertex_pos->Fill(reco_vrtx_r,reco_vrtx_z,w3_osci);
h_mc_atm_nu_horizontal_reco_vrtx_r->Fill(reco_vrtx_r,w3_osci);
h_mc_atm_nu_horizontal_reco_vrtx_x->Fill(reco_vrtx_x,w3_osci);
h_mc_atm_nu_horizontal_reco_vrtx_y->Fill(reco_vrtx_y,w3_osci);
h_mc_atm_nu_horizontal_reco_vrtx_z->Fill(reco_vrtx_z,w3_osci);
h_mc_atm_nu_horizontal_Nhits->Fill(Nhits,w3_osci);
h_mc_atm_nu_horizontal_beta0->Fill(beta0,w3_osci);
h_mc_atm_nu_horizontal_Qhits->Fill(Qhits,w3_osci);
h_mc_atm_nu_horizontal_trklength->Fill(TrkLength,w3_osci);
h_mc_atm_nu_horizontal_d_closest->Fill(d_closest,w3_osci);
h_mc_atm_nu_horizontal_z_closest->Fill(z_closest,w3_osci);
h_mc_atm_nu_horizontal_mean_z_hits->Fill(mean_z_hits,w3_osci);
h_mc_atm_nu_horizontal_mean_z_trig_hits->Fill(mean_z_trig_hits,w3_osci);
h_mc_atm_nu_horizontal_mean_z_cher_hits->Fill(mean_z_cher_hits,w3_osci);
h_mc_atm_nu_horizontal_mean_z_trig_cher_hits->Fill(mean_z_trig_cher_hits,w3_osci);
h_mc_atm_nu_horizontal_ratio_hits_trig_over_all->Fill(trig_hits_over_all,w3_osci);
h_mc_atm_nu_horizontal_ratio_hits_cher_over_all->Fill(cher_hits_over_all,w3_osci);
h_mc_atm_nu_horizontal_ratio_hits_trig_cher_over_all->Fill(trig_cher_hits_over_all,w3_osci);
h_mc_atm_nu_horizontal_Qup_m_Qdn_JGandalf->Fill(Qup_m_Qdn_JGandalf,w3_osci);
h_mc_atm_nu_horizontal_max_trig_tot->Fill(max_tot_trig,w3_osci);
h_mc_atm_nu_horizontal_early_trig_10->Fill(early_trig_10,w3_osci);
h_mc_atm_nu_horizontal_Dn_m_Up_hits->Fill(Dn_m_Up_hits,w3_osci);
h_mc_atm_nu_horizontal_Dn_m_Up_trig_hits->Fill(Dn_m_Up_trig_hits,w3_osci);
h_mc_atm_nu_horizontal_Dn_m_Up_cher_hits->Fill(Dn_m_Up_cher_hits,w3_osci);
h_mc_atm_nu_horizontal_Dn_m_Up_trig_cher_hits->Fill(Dn_m_Up_trig_cher_hits,w3_osci); 
//---------------------- True Slice -----------------------------
if ((true_energy)>10 && (true_energy)<13){
if (reco_energy<31) {
h_mc_atm_nu_horizontal_lslice_le_mean_z_hits-> Fill(mean_z_hits,w3_osci);
h_mc_atm_nu_horizontal_lslice_le_reco_vrtx_r -> Fill(reco_vrtx_r,w3_osci);
h_mc_atm_nu_horizontal_lslice_le_trklength ->Fill(TrkLength,w3_osci);
h_mc_atm_nu_horizontal_lslice_le_zenith -> Fill(zenith,w3_osci);
h_mc_atm_nu_horizontal_lslice_le_no_hit_doms -> Fill(no_doms_hit,w3_osci);
h_mc_atm_nu_horizontal_lslice_le_no_cher_doms -> Fill(no_doms_cher_hit,w3_osci);
h_mc_atm_nu_horizontal_lslice_le_Nhits-> Fill(Nhits,w3_osci);
h_mc_atm_nu_horizontal_lslice_le_beta0 -> Fill(beta0,w3_osci);
h_mc_atm_nu_horizontal_lslice_le_Qhits -> Fill(Qhits,w3_osci);
h_mc_atm_nu_horizontal_lslice_le_reco_vrtx_z -> Fill(reco_vrtx_z,w3_osci);
h_mc_atm_nu_horizontal_lslice_le_true_phi -> Fill(true_phi, w3_osci);
h_mc_atm_nu_horizontal_lslice_le_reco_phi -> Fill(reco_phi, w3_osci);
h_mc_atm_nu_horizontal_lslice_le_bjorken_y -> Fill(bjorken_y, w3_osci);
h_mc_atm_nu_horizontal_lslice_le_d_closest -> Fill(d_closest,w3_osci);
h_mc_atm_nu_horizontal_lslice_le_z_closest -> Fill(z_closest,w3_osci);

}
else {
h_mc_atm_nu_horizontal_lslice_he_mean_z_hits-> Fill(mean_z_hits,w3_osci);
h_mc_atm_nu_horizontal_lslice_he_reco_vrtx_r-> Fill(reco_vrtx_r,w3_osci);
h_mc_atm_nu_horizontal_lslice_he_reco_vertex_pos->Fill(reco_vrtx_r,reco_vrtx_z,w3_osci);
h_mc_atm_nu_horizontal_lslice_he_trklength ->Fill(TrkLength,w3_osci);
h_mc_atm_nu_horizontal_lslice_he_zenith -> Fill(zenith,w3_osci);
h_mc_atm_nu_horizontal_lslice_he_no_hit_doms -> Fill(no_doms_hit,w3_osci);
h_mc_atm_nu_horizontal_lslice_he_no_cher_doms -> Fill(no_doms_cher_hit,w3_osci);
h_mc_atm_nu_horizontal_lslice_he_Nhits-> Fill(Nhits,w3_osci);
h_mc_atm_nu_horizontal_lslice_he_beta0 -> Fill(beta0,w3_osci);
h_mc_atm_nu_horizontal_lslice_he_Qhits -> Fill(Qhits,w3_osci);
h_mc_atm_nu_horizontal_lslice_he_reco_vrtx_z -> Fill(reco_vrtx_z,w3_osci);
h_mc_atm_nu_horizontal_lslice_he_true_phi -> Fill(true_phi, w3_osci);
h_mc_atm_nu_horizontal_lslice_he_reco_phi -> Fill(reco_phi, w3_osci);
h_mc_atm_nu_horizontal_lslice_he_bjorken_y -> Fill(bjorken_y, w3_osci);
h_mc_atm_nu_horizontal_lslice_he_d_closest -> Fill(d_closest,w3_osci);
h_mc_atm_nu_horizontal_lslice_he_z_closest -> Fill(z_closest,w3_osci);

}

h_mc_atm_nu_horizontal_lslice_diff_energy-> Fill(diff_energy,w3_osci);
h_mc_atm_nu_horizontal_lslice_diff_energy_cos_zen ->Fill(zenith,diff_energy,w3_osci);
h_mc_atm_nu_horizontal_lslice_no_hits->Fill(no_hits,w3_osci);
h_mc_atm_nu_horizontal_lslice_no_trig_hits->Fill(no_trig_hits,w3_osci);
h_mc_atm_nu_horizontal_lslice_no_cher_hits->Fill(no_cher_hits,w3_osci);
h_mc_atm_nu_horizontal_lslice_no_trig_cher_hits->Fill(no_trig_cher_hits,w3_osci); 
h_mc_atm_nu_horizontal_lslice_no_hit_doms->Fill(no_doms_hit,w3_osci); 
h_mc_atm_nu_horizontal_lslice_no_trig_doms->Fill(no_doms_trig_hit,w3_osci); 
h_mc_atm_nu_horizontal_lslice_no_cher_doms->Fill(no_doms_cher_hit,w3_osci);
h_mc_atm_nu_horizontal_lslice_no_trig_cher_doms->Fill(no_doms_trig_cher_hit,w3_osci);
h_mc_atm_nu_horizontal_lslice_no_trig_dus->Fill(no_dus_trig_hit,w3_osci);
h_mc_atm_nu_horizontal_lslice_no_cher_dus->Fill(no_dus_cher_hit,w3_osci);
h_mc_atm_nu_horizontal_lslice_no_trig_cher_dus->Fill(no_dus_trig_cher_hit,w3_osci);
h_mc_atm_nu_horizontal_lslice_zenith->Fill(zenith,w3_osci);
h_mc_atm_nu_horizontal_lslice_true_zenith->Fill(true_zenith,w3_osci);
h_mc_atm_nu_horizontal_lslice_cos_zenith->Fill(cos_zen,w3_osci);
h_mc_atm_nu_horizontal_lslice_true_cos_zen->Fill(true_cos_zen,w3_osci);
h_mc_atm_nu_horizontal_lslice_max_lik_dist->Fill(max_lik,w3_osci);
h_mc_atm_nu_horizontal_lslice_log_lik_dist->Fill(log_lik,w3_osci);
h_mc_atm_nu_horizontal_lslice_true_energy->Fill(TMath::Log10(true_energy),w3_osci);
h_mc_atm_nu_horizontal_lslice_true_energy_no_log->Fill(true_energy,w3_osci);
h_mc_atm_nu_horizontal_lslice_reco_energy->Fill(TMath::Log10(reco_energy),w3_osci);
h_mc_atm_nu_horizontal_lslice_reco_vertex_pos->Fill(reco_vrtx_r,reco_vrtx_z,w3_osci);
h_mc_atm_nu_horizontal_lslice_reco_vrtx_r->Fill(reco_vrtx_r,w3_osci);
h_mc_atm_nu_horizontal_lslice_reco_vrtx_x->Fill(reco_vrtx_x,w3_osci);
h_mc_atm_nu_horizontal_lslice_reco_vrtx_y->Fill(reco_vrtx_y,w3_osci);
h_mc_atm_nu_horizontal_lslice_reco_vrtx_z->Fill(reco_vrtx_z,w3_osci);
h_mc_atm_nu_horizontal_lslice_Nhits->Fill(Nhits,w3_osci);
h_mc_atm_nu_horizontal_lslice_beta0->Fill(beta0,w3_osci);
h_mc_atm_nu_horizontal_lslice_Qhits->Fill(Qhits,w3_osci);
h_mc_atm_nu_horizontal_lslice_trklength->Fill(TrkLength,w3_osci);
h_mc_atm_nu_horizontal_lslice_d_closest->Fill(d_closest,w3_osci);
h_mc_atm_nu_horizontal_lslice_z_closest->Fill(z_closest,w3_osci);
h_mc_atm_nu_horizontal_lslice_mean_z_hits->Fill(mean_z_hits,w3_osci);
h_mc_atm_nu_horizontal_lslice_mean_z_trig_hits->Fill(mean_z_trig_hits,w3_osci);
h_mc_atm_nu_horizontal_lslice_mean_z_cher_hits->Fill(mean_z_cher_hits,w3_osci);
h_mc_atm_nu_horizontal_lslice_mean_z_trig_cher_hits->Fill(mean_z_trig_cher_hits,w3_osci);
h_mc_atm_nu_horizontal_lslice_ratio_hits_trig_over_all->Fill(trig_hits_over_all,w3_osci);
h_mc_atm_nu_horizontal_lslice_ratio_hits_cher_over_all->Fill(cher_hits_over_all,w3_osci);
h_mc_atm_nu_horizontal_lslice_ratio_hits_trig_cher_over_all->Fill(trig_cher_hits_over_all,w3_osci);
h_mc_atm_nu_horizontal_lslice_Qup_m_Qdn_JGandalf->Fill(Qup_m_Qdn_JGandalf,w3_osci);
h_mc_atm_nu_horizontal_lslice_max_trig_tot->Fill(max_tot_trig,w3_osci);
h_mc_atm_nu_horizontal_lslice_early_trig_10->Fill(early_trig_10,w3_osci);
h_mc_atm_nu_horizontal_lslice_Dn_m_Up_hits->Fill(Dn_m_Up_hits,w3_osci);
h_mc_atm_nu_horizontal_lslice_Dn_m_Up_trig_hits->Fill(Dn_m_Up_trig_hits,w3_osci);
h_mc_atm_nu_horizontal_lslice_Dn_m_Up_cher_hits->Fill(Dn_m_Up_cher_hits,w3_osci);
h_mc_atm_nu_horizontal_lslice_Dn_m_Up_trig_cher_hits->Fill(Dn_m_Up_trig_cher_hits,w3_osci);
}
if ((true_energy)>100 && (true_energy)<126){
if (reco_energy<31) {
h_mc_atm_nu_horizontal_mslice_le_mean_z_hits-> Fill(mean_z_hits,w3_osci);
h_mc_atm_nu_horizontal_mslice_le_reco_vrtx_r -> Fill(reco_vrtx_r,w3_osci);
h_mc_atm_nu_horizontal_mslice_le_trklength ->Fill(TrkLength,w3_osci);
h_mc_atm_nu_horizontal_mslice_le_zenith -> Fill(zenith,w3_osci);
h_mc_atm_nu_horizontal_mslice_le_no_hit_doms -> Fill(no_doms_hit,w3_osci);
h_mc_atm_nu_horizontal_mslice_le_no_cher_doms -> Fill(no_doms_cher_hit,w3_osci);
h_mc_atm_nu_horizontal_mslice_le_Nhits-> Fill(Nhits,w3_osci);
h_mc_atm_nu_horizontal_mslice_le_beta0 -> Fill(beta0,w3_osci);
h_mc_atm_nu_horizontal_mslice_le_Qhits -> Fill(Qhits,w3_osci);
h_mc_atm_nu_horizontal_mslice_le_reco_vrtx_z -> Fill(reco_vrtx_z,w3_osci);
h_mc_atm_nu_horizontal_mslice_le_true_phi -> Fill(true_phi, w3_osci);
h_mc_atm_nu_horizontal_mslice_le_reco_phi -> Fill(reco_phi, w3_osci);
h_mc_atm_nu_horizontal_mslice_le_bjorken_y -> Fill(bjorken_y, w3_osci);
h_mc_atm_nu_horizontal_mslice_le_d_closest -> Fill(d_closest,w3_osci);
h_mc_atm_nu_horizontal_mslice_le_z_closest -> Fill(z_closest,w3_osci);
}
else if ((reco_energy>31)&&(reco_energy<65)){
h_mc_atm_nu_horizontal_mslice_me_mean_z_hits-> Fill(mean_z_hits,w3_osci);
h_mc_atm_nu_horizontal_mslice_me_reco_vrtx_r-> Fill(reco_vrtx_r,w3_osci);
h_mc_atm_nu_horizontal_mslice_me_reco_vertex_pos->Fill(reco_vrtx_r,reco_vrtx_z,w3_osci);
h_mc_atm_nu_horizontal_mslice_me_trklength ->Fill(TrkLength,w3_osci);
h_mc_atm_nu_horizontal_mslice_me_zenith -> Fill(zenith,w3_osci);
h_mc_atm_nu_horizontal_mslice_me_no_hit_doms -> Fill(no_doms_hit,w3_osci);
h_mc_atm_nu_horizontal_mslice_me_no_cher_doms -> Fill(no_doms_cher_hit,w3_osci);
h_mc_atm_nu_horizontal_mslice_me_Nhits-> Fill(Nhits,w3_osci);
h_mc_atm_nu_horizontal_mslice_me_beta0 -> Fill(beta0,w3_osci);
h_mc_atm_nu_horizontal_mslice_me_Qhits -> Fill(Qhits,w3_osci);
h_mc_atm_nu_horizontal_mslice_me_reco_vrtx_z -> Fill(reco_vrtx_z,w3_osci);
h_mc_atm_nu_horizontal_mslice_me_true_phi -> Fill(true_phi, w3_osci);
h_mc_atm_nu_horizontal_mslice_me_reco_phi -> Fill(reco_phi, w3_osci);
h_mc_atm_nu_horizontal_mslice_me_bjorken_y -> Fill(bjorken_y, w3_osci);
h_mc_atm_nu_horizontal_mslice_me_d_closest -> Fill(d_closest,w3_osci);
h_mc_atm_nu_horizontal_mslice_me_z_closest -> Fill(z_closest,w3_osci);
}
else {
h_mc_atm_nu_horizontal_mslice_he_mean_z_hits-> Fill(mean_z_hits,w3_osci);
h_mc_atm_nu_horizontal_mslice_he_reco_vrtx_r-> Fill(reco_vrtx_r,w3_osci);
h_mc_atm_nu_horizontal_mslice_he_reco_vertex_pos->Fill(reco_vrtx_r,reco_vrtx_z,w3_osci);
h_mc_atm_nu_horizontal_mslice_he_trklength ->Fill(TrkLength,w3_osci);
h_mc_atm_nu_horizontal_mslice_he_zenith -> Fill(zenith,w3_osci);
h_mc_atm_nu_horizontal_mslice_he_no_hit_doms -> Fill(no_doms_hit,w3_osci);
h_mc_atm_nu_horizontal_mslice_he_no_cher_doms -> Fill(no_doms_cher_hit,w3_osci);
h_mc_atm_nu_horizontal_mslice_he_Nhits-> Fill(Nhits,w3_osci);
h_mc_atm_nu_horizontal_mslice_he_beta0 -> Fill(beta0,w3_osci);
h_mc_atm_nu_horizontal_mslice_he_Qhits -> Fill(Qhits,w3_osci);
h_mc_atm_nu_horizontal_mslice_he_reco_vrtx_z -> Fill(reco_vrtx_z,w3_osci);
h_mc_atm_nu_horizontal_mslice_he_true_phi -> Fill(true_phi, w3_osci);
h_mc_atm_nu_horizontal_mslice_he_reco_phi -> Fill(reco_phi, w3_osci);
h_mc_atm_nu_horizontal_mslice_he_bjorken_y -> Fill(bjorken_y, w3_osci);
h_mc_atm_nu_horizontal_mslice_he_d_closest -> Fill(d_closest,w3_osci);
h_mc_atm_nu_horizontal_mslice_he_z_closest -> Fill(z_closest,w3_osci);

}
h_mc_atm_nu_horizontal_mslice_diff_energy-> Fill(diff_energy,w3_osci);
h_mc_atm_nu_horizontal_mslice_diff_energy_cos_zen ->Fill(zenith,diff_energy,w3_osci);
h_mc_atm_nu_horizontal_mslice_no_hits->Fill(no_hits,w3_osci);
h_mc_atm_nu_horizontal_mslice_no_trig_hits->Fill(no_trig_hits,w3_osci);
h_mc_atm_nu_horizontal_mslice_no_cher_hits->Fill(no_cher_hits,w3_osci);
h_mc_atm_nu_horizontal_mslice_no_trig_cher_hits->Fill(no_trig_cher_hits,w3_osci); 
h_mc_atm_nu_horizontal_mslice_no_hit_doms->Fill(no_doms_hit,w3_osci); 
h_mc_atm_nu_horizontal_mslice_no_trig_doms->Fill(no_doms_trig_hit,w3_osci); 
h_mc_atm_nu_horizontal_mslice_no_cher_doms->Fill(no_doms_cher_hit,w3_osci);
h_mc_atm_nu_horizontal_mslice_no_trig_cher_doms->Fill(no_doms_trig_cher_hit,w3_osci);
h_mc_atm_nu_horizontal_mslice_no_trig_dus->Fill(no_dus_trig_hit,w3_osci);
h_mc_atm_nu_horizontal_mslice_no_cher_dus->Fill(no_dus_cher_hit,w3_osci);
h_mc_atm_nu_horizontal_mslice_no_trig_cher_dus->Fill(no_dus_trig_cher_hit,w3_osci);
h_mc_atm_nu_horizontal_mslice_zenith->Fill(zenith,w3_osci);
h_mc_atm_nu_horizontal_mslice_true_zenith->Fill(true_zenith,w3_osci);
h_mc_atm_nu_horizontal_mslice_cos_zenith->Fill(cos_zen,w3_osci);
h_mc_atm_nu_horizontal_mslice_true_cos_zen->Fill(true_cos_zen,w3_osci);
h_mc_atm_nu_horizontal_mslice_max_lik_dist->Fill(max_lik,w3_osci);
h_mc_atm_nu_horizontal_mslice_log_lik_dist->Fill(log_lik,w3_osci);
h_mc_atm_nu_horizontal_mslice_true_energy->Fill(TMath::Log10(true_energy),w3_osci);
h_mc_atm_nu_horizontal_mslice_true_energy_no_log->Fill(true_energy,w3_osci);
h_mc_atm_nu_horizontal_mslice_reco_energy->Fill(TMath::Log10(reco_energy),w3_osci);
h_mc_atm_nu_horizontal_mslice_reco_vertex_pos->Fill(reco_vrtx_r,reco_vrtx_z,w3_osci);
h_mc_atm_nu_horizontal_mslice_reco_vrtx_r->Fill(reco_vrtx_r,w3_osci);
h_mc_atm_nu_horizontal_mslice_reco_vrtx_x->Fill(reco_vrtx_x,w3_osci);
h_mc_atm_nu_horizontal_mslice_reco_vrtx_y->Fill(reco_vrtx_y,w3_osci);
h_mc_atm_nu_horizontal_mslice_reco_vrtx_z->Fill(reco_vrtx_z,w3_osci);
h_mc_atm_nu_horizontal_mslice_Nhits->Fill(Nhits,w3_osci);
h_mc_atm_nu_horizontal_mslice_beta0->Fill(beta0,w3_osci);
h_mc_atm_nu_horizontal_mslice_Qhits->Fill(Qhits,w3_osci);
h_mc_atm_nu_horizontal_mslice_trklength->Fill(TrkLength,w3_osci);
h_mc_atm_nu_horizontal_mslice_d_closest->Fill(d_closest,w3_osci);
h_mc_atm_nu_horizontal_mslice_z_closest->Fill(z_closest,w3_osci);
h_mc_atm_nu_horizontal_mslice_mean_z_hits->Fill(mean_z_hits,w3_osci);
h_mc_atm_nu_horizontal_mslice_mean_z_trig_hits->Fill(mean_z_trig_hits,w3_osci);
h_mc_atm_nu_horizontal_mslice_mean_z_cher_hits->Fill(mean_z_cher_hits,w3_osci);
h_mc_atm_nu_horizontal_mslice_mean_z_trig_cher_hits->Fill(mean_z_trig_cher_hits,w3_osci);
h_mc_atm_nu_horizontal_mslice_ratio_hits_trig_over_all->Fill(trig_hits_over_all,w3_osci);
h_mc_atm_nu_horizontal_mslice_ratio_hits_cher_over_all->Fill(cher_hits_over_all,w3_osci);
h_mc_atm_nu_horizontal_mslice_ratio_hits_trig_cher_over_all->Fill(trig_cher_hits_over_all,w3_osci);
h_mc_atm_nu_horizontal_mslice_Qup_m_Qdn_JGandalf->Fill(Qup_m_Qdn_JGandalf,w3_osci);
h_mc_atm_nu_horizontal_mslice_max_trig_tot->Fill(max_tot_trig,w3_osci);
h_mc_atm_nu_horizontal_mslice_early_trig_10->Fill(early_trig_10,w3_osci);
h_mc_atm_nu_horizontal_mslice_Dn_m_Up_hits->Fill(Dn_m_Up_hits,w3_osci);
h_mc_atm_nu_horizontal_mslice_Dn_m_Up_trig_hits->Fill(Dn_m_Up_trig_hits,w3_osci);
h_mc_atm_nu_horizontal_mslice_Dn_m_Up_cher_hits->Fill(Dn_m_Up_cher_hits,w3_osci);
h_mc_atm_nu_horizontal_mslice_Dn_m_Up_trig_cher_hits->Fill(Dn_m_Up_trig_cher_hits,w3_osci);
}
if ((true_energy)>1000 && (true_energy)<1260){
if (reco_energy<31) { //100
h_mc_atm_nu_horizontal_hslice_le_mean_z_hits-> Fill(mean_z_hits,w3_osci);
h_mc_atm_nu_horizontal_hslice_le_reco_vrtx_r -> Fill(reco_vrtx_r,w3_osci);
h_mc_atm_nu_horizontal_hslice_le_trklength ->Fill(TrkLength,w3_osci);
h_mc_atm_nu_horizontal_hslice_le_zenith -> Fill(zenith,w3_osci);
h_mc_atm_nu_horizontal_hslice_le_no_hit_doms -> Fill(no_doms_hit,w3_osci);
h_mc_atm_nu_horizontal_hslice_le_no_cher_doms -> Fill(no_doms_cher_hit,w3_osci);
h_mc_atm_nu_horizontal_hslice_le_Nhits-> Fill(Nhits,w3_osci);
h_mc_atm_nu_horizontal_hslice_le_beta0 -> Fill(beta0,w3_osci);
h_mc_atm_nu_horizontal_hslice_le_Qhits -> Fill(Qhits,w3_osci);
h_mc_atm_nu_horizontal_hslice_le_reco_vrtx_z -> Fill(reco_vrtx_z,w3_osci);
h_mc_atm_nu_horizontal_hslice_le_true_phi -> Fill(true_phi, w3_osci);
h_mc_atm_nu_horizontal_hslice_le_reco_phi -> Fill(reco_phi, w3_osci);
h_mc_atm_nu_horizontal_hslice_le_bjorken_y -> Fill(bjorken_y, w3_osci);
h_mc_atm_nu_horizontal_hslice_le_d_closest -> Fill(d_closest,w3_osci);
h_mc_atm_nu_horizontal_hslice_le_z_closest -> Fill(z_closest,w3_osci);
}
else {
h_mc_atm_nu_horizontal_hslice_he_mean_z_hits-> Fill(mean_z_hits,w3_osci);
h_mc_atm_nu_horizontal_hslice_he_reco_vrtx_r-> Fill(reco_vrtx_r,w3_osci);
h_mc_atm_nu_horizontal_hslice_he_reco_vertex_pos->Fill(reco_vrtx_r,reco_vrtx_z,w3_osci);
h_mc_atm_nu_horizontal_hslice_he_trklength ->Fill(TrkLength,w3_osci);
h_mc_atm_nu_horizontal_hslice_he_zenith -> Fill(zenith,w3_osci);
h_mc_atm_nu_horizontal_hslice_he_no_hit_doms -> Fill(no_doms_hit,w3_osci);
h_mc_atm_nu_horizontal_hslice_he_no_cher_doms -> Fill(no_doms_cher_hit,w3_osci);
h_mc_atm_nu_horizontal_hslice_he_Nhits-> Fill(Nhits,w3_osci);
h_mc_atm_nu_horizontal_hslice_he_beta0 -> Fill(beta0,w3_osci);
h_mc_atm_nu_horizontal_hslice_he_Qhits -> Fill(Qhits,w3_osci);
h_mc_atm_nu_horizontal_hslice_he_reco_vrtx_z -> Fill(reco_vrtx_z,w3_osci);
h_mc_atm_nu_horizontal_hslice_he_true_phi -> Fill(true_phi, w3_osci);
h_mc_atm_nu_horizontal_hslice_he_reco_phi -> Fill(reco_phi, w3_osci);
h_mc_atm_nu_horizontal_hslice_he_bjorken_y -> Fill(bjorken_y, w3_osci);
h_mc_atm_nu_horizontal_hslice_he_d_closest -> Fill(d_closest,w3_osci);
h_mc_atm_nu_horizontal_hslice_he_z_closest -> Fill(z_closest,w3_osci);

}
h_mc_atm_nu_horizontal_hslice_diff_energy-> Fill(diff_energy,w3_osci);
h_mc_atm_nu_horizontal_hslice_diff_energy_cos_zen ->Fill(zenith,diff_energy,w3_osci);
h_mc_atm_nu_horizontal_hslice_no_hits->Fill(no_hits,w3_osci);
h_mc_atm_nu_horizontal_hslice_no_trig_hits->Fill(no_trig_hits,w3_osci);
h_mc_atm_nu_horizontal_hslice_no_cher_hits->Fill(no_cher_hits,w3_osci);
h_mc_atm_nu_horizontal_hslice_no_trig_cher_hits->Fill(no_trig_cher_hits,w3_osci); 
h_mc_atm_nu_horizontal_hslice_no_hit_doms->Fill(no_doms_hit,w3_osci); 
h_mc_atm_nu_horizontal_hslice_no_trig_doms->Fill(no_doms_trig_hit,w3_osci); 
h_mc_atm_nu_horizontal_hslice_no_cher_doms->Fill(no_doms_cher_hit,w3_osci);
h_mc_atm_nu_horizontal_hslice_no_trig_cher_doms->Fill(no_doms_trig_cher_hit,w3_osci);
h_mc_atm_nu_horizontal_hslice_no_trig_dus->Fill(no_dus_trig_hit,w3_osci);
h_mc_atm_nu_horizontal_hslice_no_cher_dus->Fill(no_dus_cher_hit,w3_osci);
h_mc_atm_nu_horizontal_hslice_no_trig_cher_dus->Fill(no_dus_trig_cher_hit,w3_osci);
h_mc_atm_nu_horizontal_hslice_zenith->Fill(zenith,w3_osci);
h_mc_atm_nu_horizontal_hslice_true_zenith->Fill(true_zenith,w3_osci);
h_mc_atm_nu_horizontal_hslice_cos_zenith->Fill(cos_zen,w3_osci);
h_mc_atm_nu_horizontal_hslice_true_cos_zen->Fill(true_cos_zen,w3_osci);
h_mc_atm_nu_horizontal_hslice_max_lik_dist->Fill(max_lik,w3_osci);
h_mc_atm_nu_horizontal_hslice_log_lik_dist->Fill(log_lik,w3_osci);
h_mc_atm_nu_horizontal_hslice_true_energy->Fill(TMath::Log10(true_energy),w3_osci);
h_mc_atm_nu_horizontal_hslice_true_energy_no_log->Fill(true_energy,w3_osci);
h_mc_atm_nu_horizontal_hslice_reco_energy->Fill(TMath::Log10(reco_energy),w3_osci);
h_mc_atm_nu_horizontal_hslice_reco_vertex_pos->Fill(reco_vrtx_r,reco_vrtx_z,w3_osci);
h_mc_atm_nu_horizontal_hslice_reco_vrtx_r->Fill(reco_vrtx_r,w3_osci);
h_mc_atm_nu_horizontal_hslice_reco_vrtx_x->Fill(reco_vrtx_x,w3_osci);
h_mc_atm_nu_horizontal_hslice_reco_vrtx_y->Fill(reco_vrtx_y,w3_osci);
h_mc_atm_nu_horizontal_hslice_reco_vrtx_z->Fill(reco_vrtx_z,w3_osci);
h_mc_atm_nu_horizontal_hslice_Nhits->Fill(Nhits,w3_osci);
h_mc_atm_nu_horizontal_hslice_beta0->Fill(beta0,w3_osci);
h_mc_atm_nu_horizontal_hslice_Qhits->Fill(Qhits,w3_osci);
h_mc_atm_nu_horizontal_hslice_trklength->Fill(TrkLength,w3_osci);
h_mc_atm_nu_horizontal_hslice_d_closest->Fill(d_closest,w3_osci);
h_mc_atm_nu_horizontal_hslice_z_closest->Fill(z_closest,w3_osci);
h_mc_atm_nu_horizontal_hslice_mean_z_hits->Fill(mean_z_hits,w3_osci);
h_mc_atm_nu_horizontal_hslice_mean_z_trig_hits->Fill(mean_z_trig_hits,w3_osci);
h_mc_atm_nu_horizontal_hslice_mean_z_cher_hits->Fill(mean_z_cher_hits,w3_osci);
h_mc_atm_nu_horizontal_hslice_mean_z_trig_cher_hits->Fill(mean_z_trig_cher_hits,w3_osci);
h_mc_atm_nu_horizontal_hslice_ratio_hits_trig_over_all->Fill(trig_hits_over_all,w3_osci);
h_mc_atm_nu_horizontal_hslice_ratio_hits_cher_over_all->Fill(cher_hits_over_all,w3_osci);
h_mc_atm_nu_horizontal_hslice_ratio_hits_trig_cher_over_all->Fill(trig_cher_hits_over_all,w3_osci);
h_mc_atm_nu_horizontal_hslice_Qup_m_Qdn_JGandalf->Fill(Qup_m_Qdn_JGandalf,w3_osci);
h_mc_atm_nu_horizontal_hslice_max_trig_tot->Fill(max_tot_trig,w3_osci);
h_mc_atm_nu_horizontal_hslice_early_trig_10->Fill(early_trig_10,w3_osci);
h_mc_atm_nu_horizontal_hslice_Dn_m_Up_hits->Fill(Dn_m_Up_hits,w3_osci);
h_mc_atm_nu_horizontal_hslice_Dn_m_Up_trig_hits->Fill(Dn_m_Up_trig_hits,w3_osci);
h_mc_atm_nu_horizontal_hslice_Dn_m_Up_cher_hits->Fill(Dn_m_Up_cher_hits,w3_osci);
h_mc_atm_nu_horizontal_hslice_Dn_m_Up_trig_cher_hits->Fill(Dn_m_Up_trig_cher_hits,w3_osci);
h_mc_atm_nu_horizontal_hslice_trk_reco_energy -> Fill(reco_energy, TrkLength, w3_osci);
h_mc_atm_nu_horizontal_hslice_trk_true_energy -> Fill(true_energy, TrkLength, w3_osci);}}}

if(i%1000000==0) cout << "Atm. nu Ev. = " << i << endl;}
//if (i==0) break;}

 

// scale mc atm. nu histograms to the data livetime
// divide with the # of runs giving the rate (s^-1), then multiply with the data livetime 

h_mc_atm_nu_horizontal_no_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_no_trig_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_no_cher_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_no_trig_cher_hits->Scale(total_data_livetime/1387.0); 
h_mc_atm_nu_horizontal_no_hit_doms->Scale(total_data_livetime/1387.0); 
h_mc_atm_nu_horizontal_no_trig_doms->Scale(total_data_livetime/1387.0); 
h_mc_atm_nu_horizontal_no_cher_doms->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_no_trig_cher_doms->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_no_trig_dus->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_no_cher_dus->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_no_trig_cher_dus->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_zenith->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_true_zenith->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_cos_zenith->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_true_cos_zen->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_max_lik_dist->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_log_lik_dist->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_true_energy->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_true_energy_no_log->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_reco_energy->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_E_reco_E_true_rec_zen_all -> Scale(total_data_livetime/1387);
h_mc_atm_nu_horizontal_E_reco_E_true_rec_zen_30_all-> Scale(total_data_livetime/1387); //inserted for the job requested by boss
h_mc_atm_nu_horizontal_E_reco_E_true_rec_zen_150_all-> Scale(total_data_livetime/1387); 
h_mc_atm_nu_horizontal_reco_vertex_pos->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_reco_vrtx_r->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_reco_vrtx_x->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_reco_vrtx_y->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_reco_vrtx_z->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_Nhits->Scale(total_data_livetime/1387.0);

h_mc_atm_nu_horizontal_beta0->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_Qhits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_trklength->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_d_closest->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_z_closest->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mean_z_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mean_z_trig_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mean_z_cher_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mean_z_trig_cher_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_ratio_hits_trig_over_all->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_ratio_hits_cher_over_all->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_ratio_hits_trig_cher_over_all->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_Qup_m_Qdn_JGandalf->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_max_trig_tot->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_early_trig_10->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_Dn_m_Up_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_Dn_m_Up_trig_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_Dn_m_Up_cher_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_Dn_m_Up_trig_cher_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_E_true_zenith_upgoing ->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_E_true_zenith_horizontal ->Scale(total_data_livetime/1387.0);



// scale mc atm. muon histograms to the data livetime
// divide with the # of runs giving the rate (s^-1), then multiply with the data livetime 
h_mc_atm_nu_horizontal_lslice_no_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_lslice_no_trig_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_lslice_no_cher_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_lslice_no_trig_cher_hits->Scale(total_data_livetime/1387.0); 
h_mc_atm_nu_horizontal_lslice_no_hit_doms->Scale(total_data_livetime/1387.0); 
h_mc_atm_nu_horizontal_lslice_no_trig_doms->Scale(total_data_livetime/1387.0); 
h_mc_atm_nu_horizontal_lslice_no_cher_doms->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_lslice_no_trig_cher_doms->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_lslice_no_trig_dus->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_lslice_no_cher_dus->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_lslice_no_trig_cher_dus->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_lslice_zenith->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_lslice_true_zenith->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_lslice_cos_zenith->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_lslice_true_cos_zen->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_lslice_max_lik_dist->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_lslice_log_lik_dist->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_lslice_true_energy->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_lslice_true_energy_no_log->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_lslice_reco_energy->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_lslice_reco_vertex_pos->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_lslice_reco_vrtx_r->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_lslice_reco_vrtx_x->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_lslice_reco_vrtx_y->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_lslice_reco_vrtx_z->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_lslice_Nhits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_lslice_beta0->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_lslice_Qhits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_lslice_trklength->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_lslice_d_closest->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_lslice_z_closest->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_lslice_mean_z_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_lslice_mean_z_trig_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_lslice_mean_z_cher_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_lslice_mean_z_trig_cher_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_lslice_ratio_hits_trig_over_all->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_lslice_ratio_hits_cher_over_all->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_lslice_ratio_hits_trig_cher_over_all->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_lslice_Qup_m_Qdn_JGandalf->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_lslice_max_trig_tot->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_lslice_early_trig_10->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_lslice_Dn_m_Up_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_lslice_Dn_m_Up_trig_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_lslice_Dn_m_Up_cher_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_lslice_Dn_m_Up_trig_cher_hits->Scale(total_data_livetime/1387.0);

h_mc_atm_nu_horizontal_lslice_le_reco_vrtx_r->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_lslice_le_mean_z_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_lslice_le_trklength ->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_lslice_le_zenith ->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_lslice_le_no_hit_doms -> Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_lslice_le_no_cher_doms -> Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_lslice_le_Nhits-> Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_lslice_le_beta0 -> Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_lslice_le_Qhits -> Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_lslice_le_reco_vrtx_z -> Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_lslice_le_true_phi ->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_lslice_le_reco_phi ->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_lslice_le_bjorken_y ->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_lslice_le_d_closest ->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_lslice_le_z_closest ->Scale(total_data_livetime/1387.0);

h_mc_atm_nu_horizontal_lslice_he_d_closest ->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_lslice_he_z_closest ->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_lslice_he_reco_phi ->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_lslice_he_bjorken_y ->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_lslice_he_true_phi ->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_lslice_he_reco_vrtx_z -> Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_lslice_he_no_hit_doms -> Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_lslice_he_no_cher_doms -> Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_lslice_he_Nhits-> Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_lslice_he_beta0 -> Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_lslice_he_Qhits -> Scale(total_data_livetime/1387.0); 
h_mc_atm_nu_horizontal_lslice_he_zenith ->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_lslice_he_reco_vertex_pos->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_lslice_he_trklength ->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_lslice_he_mean_z_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_lslice_he_reco_vrtx_r->Scale(total_data_livetime/1387.0);
 

// scale mc atm. muon histograms to the data livetime
// divide with the # of runs giving the rate (s^-1), then multiply with the data livetime 
h_mc_atm_nu_horizontal_mslice_no_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_no_trig_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_no_cher_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_no_trig_cher_hits->Scale(total_data_livetime/1387.0); 
h_mc_atm_nu_horizontal_mslice_no_hit_doms->Scale(total_data_livetime/1387.0); 
h_mc_atm_nu_horizontal_mslice_no_trig_doms->Scale(total_data_livetime/1387.0); 
h_mc_atm_nu_horizontal_mslice_no_cher_doms->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_no_trig_cher_doms->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_no_trig_dus->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_no_cher_dus->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_no_trig_cher_dus->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_zenith->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_true_zenith->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_cos_zenith->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_true_cos_zen->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_max_lik_dist->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_log_lik_dist->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_true_energy->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_true_energy_no_log->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_reco_energy->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_reco_vertex_pos->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_reco_vrtx_r->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_reco_vrtx_x->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_reco_vrtx_y->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_reco_vrtx_z->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_Nhits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_beta0->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_Qhits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_trklength->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_d_closest->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_z_closest->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_mean_z_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_mean_z_trig_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_mean_z_cher_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_mean_z_trig_cher_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_ratio_hits_trig_over_all->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_ratio_hits_cher_over_all->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_ratio_hits_trig_cher_over_all->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_Qup_m_Qdn_JGandalf->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_max_trig_tot->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_early_trig_10->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_Dn_m_Up_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_Dn_m_Up_trig_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_Dn_m_Up_cher_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_Dn_m_Up_trig_cher_hits->Scale(total_data_livetime/1387.0);

h_mc_atm_nu_horizontal_mslice_le_reco_vrtx_r->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_le_mean_z_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_le_trklength ->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_le_zenith ->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_le_no_hit_doms -> Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_le_no_cher_doms -> Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_le_Nhits-> Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_le_beta0 -> Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_le_Qhits -> Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_le_reco_vrtx_z -> Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_le_true_phi ->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_le_reco_phi ->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_le_bjorken_y ->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_le_d_closest ->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_le_z_closest ->Scale(total_data_livetime/1387.0);

h_mc_atm_nu_horizontal_mslice_me_reco_vrtx_r->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_me_mean_z_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_me_trklength ->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_me_zenith ->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_me_no_hit_doms -> Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_me_no_cher_doms -> Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_me_Nhits-> Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_me_beta0 -> Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_me_Qhits -> Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_me_reco_vrtx_z -> Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_me_true_phi ->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_me_reco_phi ->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_me_bjorken_y ->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_me_d_closest ->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_me_z_closest ->Scale(total_data_livetime/1387.0);

h_mc_atm_nu_horizontal_mslice_he_reco_vrtx_r->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_he_mean_z_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_he_trklength ->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_he_zenith ->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_he_no_hit_doms -> Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_he_no_cher_doms -> Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_he_Nhits-> Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_he_beta0 -> Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_he_Qhits -> Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_he_reco_vrtx_z -> Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_he_true_phi ->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_he_reco_phi ->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_he_bjorken_y ->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_he_d_closest ->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_he_z_closest ->Scale(total_data_livetime/1387.0);


// scale mc atm. muon histograms to the data livetime
// divide with the # of runs giving the rate (s^-1), then multiply with the data livetime 
h_mc_atm_nu_horizontal_hslice_no_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_hslice_no_trig_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_hslice_no_cher_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_hslice_no_trig_cher_hits->Scale(total_data_livetime/1387.0); 
h_mc_atm_nu_horizontal_hslice_no_hit_doms->Scale(total_data_livetime/1387.0); 
h_mc_atm_nu_horizontal_hslice_no_trig_doms->Scale(total_data_livetime/1387.0); 
h_mc_atm_nu_horizontal_hslice_no_cher_doms->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_hslice_no_trig_cher_doms->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_hslice_no_trig_dus->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_hslice_no_cher_dus->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_hslice_no_trig_cher_dus->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_hslice_zenith->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_hslice_true_zenith->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_hslice_cos_zenith->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_hslice_true_cos_zen->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_hslice_max_lik_dist->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_hslice_log_lik_dist->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_hslice_true_energy->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_hslice_true_energy_no_log->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_hslice_reco_energy->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_hslice_reco_vertex_pos->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_hslice_reco_vrtx_r->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_hslice_reco_vrtx_x->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_hslice_reco_vrtx_y->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_hslice_reco_vrtx_z->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_hslice_Nhits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_hslice_beta0->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_hslice_Qhits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_hslice_trklength->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_hslice_d_closest->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_hslice_z_closest->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_hslice_mean_z_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_hslice_mean_z_trig_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_hslice_mean_z_cher_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_hslice_mean_z_trig_cher_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_hslice_ratio_hits_trig_over_all->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_hslice_ratio_hits_cher_over_all->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_hslice_ratio_hits_trig_cher_over_all->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_hslice_Qup_m_Qdn_JGandalf->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_hslice_max_trig_tot->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_hslice_early_trig_10->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_hslice_Dn_m_Up_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_hslice_Dn_m_Up_trig_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_hslice_Dn_m_Up_cher_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_hslice_Dn_m_Up_trig_cher_hits->Scale(total_data_livetime/1387.0);

h_mc_atm_nu_horizontal_hslice_he_reco_vrtx_r->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_hslice_le_reco_vrtx_r->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_hslice_he_mean_z_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_hslice_le_mean_z_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_hslice_he_reco_vertex_pos->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_hslice_he_trklength ->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_hslice_le_trklength ->Scale(total_data_livetime/1387.0); 
h_mc_atm_nu_horizontal_hslice_trk_reco_energy -> Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_hslice_trk_true_energy -> Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_hslice_le_zenith ->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_hslice_he_zenith ->Scale(total_data_livetime/1387.0);

h_mc_atm_nu_horizontal_hslice_le_no_hit_doms -> Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_hslice_le_no_cher_doms -> Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_hslice_le_Nhits-> Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_hslice_le_beta0 -> Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_hslice_le_Qhits -> Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_hslice_he_no_hit_doms -> Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_hslice_he_no_cher_doms -> Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_hslice_he_Nhits-> Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_hslice_he_beta0 -> Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_hslice_he_Qhits -> Scale(total_data_livetime/1387.0); 
h_mc_atm_nu_horizontal_hslice_le_reco_vrtx_z -> Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_hslice_he_reco_vrtx_z -> Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_hslice_le_true_phi ->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_hslice_le_reco_phi ->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_hslice_le_bjorken_y ->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_hslice_he_true_phi ->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_hslice_he_reco_phi ->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_hslice_he_bjorken_y ->Scale(total_data_livetime/1387.0);

h_mc_atm_nu_horizontal_hslice_le_d_closest ->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_hslice_le_z_closest ->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_hslice_he_d_closest ->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_hslice_he_z_closest ->Scale(total_data_livetime/1387.0);




//
h_mc_atm_nu_upgoing_no_hits ->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_no_trig_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_no_cher_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_no_trig_cher_hits->Scale(total_data_livetime/1387.0); 
h_mc_atm_nu_upgoing_no_hit_doms->Scale(total_data_livetime/1387.0); 
h_mc_atm_nu_upgoing_no_trig_doms->Scale(total_data_livetime/1387.0); 
h_mc_atm_nu_upgoing_no_cher_doms->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_no_trig_cher_doms->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_no_trig_dus->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_no_cher_dus->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_no_trig_cher_dus->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_zenith->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_true_zenith->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_cos_zenith->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_true_cos_zen->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_max_lik_dist->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_log_lik_dist->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_true_energy->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_true_energy_no_log->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_reco_energy->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_E_reco_E_true_rec_zen_all -> Scale(total_data_livetime/1387);
h_mc_atm_nu_upgoing_E_reco_E_true_rec_zen_30_all-> Scale(total_data_livetime/1387); //inserted for the job requested by boss
h_mc_atm_nu_upgoing_E_reco_E_true_rec_zen_150_all-> Scale(total_data_livetime/1387); 
h_mc_atm_nu_upgoing_reco_vertex_pos->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_reco_vrtx_r->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_reco_vrtx_x->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_reco_vrtx_y->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_reco_vrtx_z->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_Nhits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_beta0->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_Qhits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_trklength->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_d_closest->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_z_closest->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_mean_z_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_mean_z_trig_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_mean_z_cher_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_mean_z_trig_cher_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_ratio_hits_trig_over_all->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_ratio_hits_cher_over_all->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_ratio_hits_trig_cher_over_all->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_Qup_m_Qdn_JGandalf->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_max_trig_tot->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_early_trig_10->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_Dn_m_Up_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_Dn_m_Up_trig_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_Dn_m_Up_cher_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_Dn_m_Up_trig_cher_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_E_true_zenith_upgoing ->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_E_true_zenith_horizontal ->Scale(total_data_livetime/1387.0);

// scale mc atm. muon histograms to the data livetime
// divide with the # of runs giving the rate (s^-1), then multiply with the data livetime 
h_mc_atm_nu_upgoing_lslice_no_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_lslice_no_trig_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_lslice_no_cher_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_lslice_no_trig_cher_hits->Scale(total_data_livetime/1387.0); 
h_mc_atm_nu_upgoing_lslice_no_hit_doms->Scale(total_data_livetime/1387.0); 
h_mc_atm_nu_upgoing_lslice_no_trig_doms->Scale(total_data_livetime/1387.0); 
h_mc_atm_nu_upgoing_lslice_no_cher_doms->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_lslice_no_trig_cher_doms->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_lslice_no_trig_dus->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_lslice_no_cher_dus->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_lslice_no_trig_cher_dus->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_lslice_zenith->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_lslice_true_zenith->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_lslice_cos_zenith->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_lslice_true_cos_zen->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_lslice_max_lik_dist->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_lslice_log_lik_dist->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_lslice_true_energy->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_lslice_true_energy_no_log->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_lslice_reco_energy->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_lslice_reco_vertex_pos->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_lslice_reco_vrtx_r->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_lslice_reco_vrtx_x->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_lslice_reco_vrtx_y->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_lslice_reco_vrtx_z->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_lslice_Nhits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_lslice_beta0->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_lslice_Qhits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_lslice_trklength->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_lslice_d_closest->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_lslice_z_closest->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_lslice_mean_z_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_lslice_mean_z_trig_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_lslice_mean_z_cher_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_lslice_mean_z_trig_cher_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_lslice_ratio_hits_trig_over_all->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_lslice_ratio_hits_cher_over_all->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_lslice_ratio_hits_trig_cher_over_all->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_lslice_Qup_m_Qdn_JGandalf->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_lslice_max_trig_tot->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_lslice_early_trig_10->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_lslice_Dn_m_Up_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_lslice_Dn_m_Up_trig_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_lslice_Dn_m_Up_cher_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_lslice_Dn_m_Up_trig_cher_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_lslice_he_reco_vrtx_r->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_lslice_le_reco_vrtx_r->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_lslice_he_mean_z_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_lslice_le_mean_z_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_lslice_he_reco_vertex_pos->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_lslice_le_reco_vertex_pos->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_lslice_he_trklength ->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_lslice_le_trklength ->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_lslice_le_zenith ->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_lslice_he_zenith ->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_lslice_le_no_hit_doms -> Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_lslice_le_no_cher_doms -> Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_lslice_le_Nhits-> Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_lslice_le_beta0 -> Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_lslice_le_Qhits -> Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_lslice_he_no_hit_doms -> Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_lslice_he_no_cher_doms -> Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_lslice_he_Nhits-> Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_lslice_he_beta0 -> Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_lslice_he_Qhits -> Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_lslice_le_reco_vrtx_z -> Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_lslice_he_reco_vrtx_z -> Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_lslice_le_true_phi ->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_lslice_le_reco_phi ->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_lslice_le_bjorken_y ->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_lslice_he_true_phi ->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_lslice_he_reco_phi ->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_lslice_he_bjorken_y ->Scale(total_data_livetime/1387.0);

h_mc_atm_nu_upgoing_lslice_le_d_closest ->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_lslice_le_z_closest ->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_lslice_he_d_closest ->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_lslice_he_z_closest ->Scale(total_data_livetime/1387.0);




// scale mc atm. muon histograms to the data livetime
// divide with the # of runs giving the rate (s^-1), then multiply with the data livetime 
h_mc_atm_nu_upgoing_mslice_no_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_mslice_no_trig_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_mslice_no_cher_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_mslice_no_trig_cher_hits->Scale(total_data_livetime/1387.0); 
h_mc_atm_nu_upgoing_mslice_no_hit_doms->Scale(total_data_livetime/1387.0); 
h_mc_atm_nu_upgoing_mslice_no_trig_doms->Scale(total_data_livetime/1387.0); 
h_mc_atm_nu_upgoing_mslice_no_cher_doms->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_mslice_no_trig_cher_doms->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_mslice_no_trig_dus->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_mslice_no_cher_dus->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_mslice_no_trig_cher_dus->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_mslice_zenith->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_mslice_true_zenith->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_mslice_cos_zenith->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_mslice_true_cos_zen->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_mslice_max_lik_dist->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_mslice_log_lik_dist->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_mslice_true_energy->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_mslice_true_energy_no_log->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_mslice_reco_energy->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_mslice_reco_vertex_pos->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_mslice_reco_vrtx_r->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_mslice_reco_vrtx_x->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_mslice_reco_vrtx_y->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_mslice_reco_vrtx_z->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_mslice_Nhits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_mslice_beta0->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_mslice_Qhits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_mslice_trklength->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_mslice_d_closest->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_mslice_z_closest->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_mslice_mean_z_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_mslice_mean_z_trig_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_mslice_mean_z_cher_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_mslice_mean_z_trig_cher_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_mslice_ratio_hits_trig_over_all->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_mslice_ratio_hits_cher_over_all->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_mslice_ratio_hits_trig_cher_over_all->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_mslice_Qup_m_Qdn_JGandalf->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_mslice_max_trig_tot->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_mslice_early_trig_10->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_mslice_Dn_m_Up_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_mslice_Dn_m_Up_trig_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_mslice_Dn_m_Up_cher_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_mslice_Dn_m_Up_trig_cher_hits->Scale(total_data_livetime/1387.0);

h_mc_atm_nu_horizontal_mslice_le_reco_vrtx_r->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_le_mean_z_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_le_trklength ->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_le_zenith ->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_le_no_hit_doms -> Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_le_no_cher_doms -> Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_le_Nhits-> Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_le_beta0 -> Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_le_Qhits -> Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_le_reco_vrtx_z -> Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_le_true_phi ->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_le_reco_phi ->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_le_bjorken_y ->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_le_d_closest ->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_le_z_closest ->Scale(total_data_livetime/1387.0);

h_mc_atm_nu_horizontal_mslice_me_reco_vrtx_r->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_me_mean_z_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_me_trklength ->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_me_zenith ->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_me_no_hit_doms -> Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_me_no_cher_doms -> Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_me_Nhits-> Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_me_beta0 -> Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_me_Qhits -> Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_me_reco_vrtx_z -> Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_me_true_phi ->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_me_reco_phi ->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_me_bjorken_y ->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_me_d_closest ->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_me_z_closest ->Scale(total_data_livetime/1387.0);

h_mc_atm_nu_horizontal_mslice_he_reco_vrtx_r->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_he_mean_z_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_he_trklength ->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_he_zenith ->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_he_no_hit_doms -> Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_he_no_cher_doms -> Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_he_Nhits-> Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_he_beta0 -> Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_he_Qhits -> Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_he_reco_vrtx_z -> Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_he_true_phi ->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_he_reco_phi ->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_he_bjorken_y ->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_he_d_closest ->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_horizontal_mslice_he_z_closest ->Scale(total_data_livetime/1387.0);



// scale mc atm. muon histograms to the data livetime
// divide with the # of runs giving the rate (s^-1), then multiply with the data livetime//for the upgoing condition 
h_mc_atm_nu_upgoing_hslice_no_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_hslice_no_trig_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_hslice_no_cher_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_hslice_no_trig_cher_hits->Scale(total_data_livetime/1387.0); 
h_mc_atm_nu_upgoing_hslice_no_hit_doms->Scale(total_data_livetime/1387.0); 
h_mc_atm_nu_upgoing_hslice_no_trig_doms->Scale(total_data_livetime/1387.0); 
h_mc_atm_nu_upgoing_hslice_no_cher_doms->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_hslice_no_trig_cher_doms->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_hslice_no_trig_dus->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_hslice_no_cher_dus->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_hslice_no_trig_cher_dus->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_hslice_zenith->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_hslice_true_zenith->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_hslice_cos_zenith->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_hslice_true_cos_zen->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_hslice_max_lik_dist->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_hslice_log_lik_dist->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_hslice_true_energy->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_hslice_true_energy_no_log->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_hslice_reco_energy->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_hslice_reco_vertex_pos->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_hslice_reco_vrtx_r->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_hslice_reco_vrtx_x->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_hslice_reco_vrtx_y->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_hslice_reco_vrtx_z->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_hslice_Nhits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_hslice_beta0->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_hslice_Qhits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_hslice_trklength->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_hslice_d_closest->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_hslice_z_closest->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_hslice_mean_z_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_hslice_mean_z_trig_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_hslice_mean_z_cher_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_hslice_mean_z_trig_cher_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_hslice_ratio_hits_trig_over_all->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_hslice_ratio_hits_cher_over_all->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_hslice_ratio_hits_trig_cher_over_all->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_hslice_Qup_m_Qdn_JGandalf->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_hslice_max_trig_tot->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_hslice_early_trig_10->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_hslice_Dn_m_Up_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_hslice_Dn_m_Up_trig_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_hslice_Dn_m_Up_cher_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_hslice_Dn_m_Up_trig_cher_hits->Scale(total_data_livetime/1387.0);

h_mc_atm_nu_upgoing_hslice_he_reco_vrtx_r->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_hslice_le_reco_vrtx_r->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_hslice_he_mean_z_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_hslice_le_mean_z_hits->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_hslice_he_reco_vertex_pos->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_hslice_he_trklength ->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_hslice_le_trklength ->Scale(total_data_livetime/1387.0); 
h_mc_atm_nu_upgoing_hslice_trk_reco_energy -> Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_hslice_trk_true_energy -> Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_hslice_le_zenith ->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_hslice_he_zenith ->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_hslice_le_no_hit_doms -> Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_hslice_le_no_cher_doms -> Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_hslice_le_Nhits-> Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_hslice_le_beta0 -> Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_hslice_le_Qhits -> Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_hslice_he_no_hit_doms -> Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_hslice_he_no_cher_doms -> Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_hslice_he_Nhits-> Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_hslice_he_beta0 -> Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_hslice_he_Qhits -> Scale(total_data_livetime/1387.0); 
h_mc_atm_nu_upgoing_hslice_le_reco_vrtx_z -> Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_hslice_he_reco_vrtx_z -> Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_hslice_le_true_phi ->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_hslice_le_reco_phi ->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_hslice_le_bjorken_y ->Scale(total_data_livetime/1387.0);

h_mc_atm_nu_upgoing_hslice_he_true_phi ->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_hslice_he_reco_phi ->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_hslice_he_bjorken_y ->Scale(total_data_livetime/1387.0);

h_mc_atm_nu_upgoing_hslice_le_d_closest ->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_hslice_le_z_closest ->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_hslice_he_d_closest ->Scale(total_data_livetime/1387.0);
h_mc_atm_nu_upgoing_hslice_he_z_closest ->Scale(total_data_livetime/1387.0);




/*
 //----------------------- MC NOISE --------------------------------
TFile* f_rand_no = new TFile();
f_rand_no = TFile::Open(Form("/home/mrboson/Downloads/km3net/MC_Analysis/Analyze_ORCA6/analysis/Analysis_Data/%s",rand_no_file.c_str()));   


TTree* rand_no_run_qual_params = (TTree*)f_rand_no->Get("QualParams");
run=0;
rand_no_run_qual_params->SetBranchAddress("run",&run);
rand_no_run_qual_params->SetBranchAddress("livetime",&livetime);
double total_rand_no_livetime;

for( int i=0 ; i<rand_no_run_qual_params->GetEntries() ; i++ ){
rand_no_run_qual_params->GetEntry(i);
total_rand_no_livetime += livetime;
}
cout << "Random noiselivetime = " << total_rand_no_livetime/(24*3600) << " days." << endl;

TTree* rand_noise_events = (TTree*)f_rand_no->Get("ProcEvts");

zenith, true_zenith, true_cos_zen, true_energy = 0 ;
index = event_id = frame_index = trigger_counter = 0 ;
no_hits = no_doms_hit = no_dus_hit = no_trig_hits = no_doms_trig_hit = no_dus_trig_hit = no_cher_hits = no_doms_cher_hit = no_dus_cher_hit = no_trig_cher_hits = no_doms_trig_cher_hit = no_dus_trig_cher_hit = 0 ;
cos_zen = max_lik = log_lik = reco_energy = reco_vrtx_x = reco_vrtx_y = reco_vrtx_z = reco_vrtx_r = Nhits = Qhits = beta0 = TrkLength = d_closest = z_closest = 0 ;
mean_z_hits = mean_z_trig_hits = mean_z_cher_hits = mean_z_trig_cher_hits = trig_hits_over_all = cher_hits_over_all = trig_cher_hits_over_all = Qup_m_Qdn_JGandalf = max_tot_trig = 0 ;
Dn_m_Up_hits = Dn_m_Up_trig_hits = Dn_m_Up_cher_hits = Dn_m_Up_trig_cher_hits = early_trig_10 = 0 ;

rand_noise_events->SetBranchAddress("run",&run);
rand_noise_events->SetBranchAddress("index",&index);
rand_noise_events->SetBranchAddress("event_id",&event_id);
rand_noise_events->SetBranchAddress("frame_index",&frame_index);
rand_noise_events->SetBranchAddress("trigger_counter",&trigger_counter);
rand_noise_events->SetBranchAddress("no_hits",&no_hits);
rand_noise_events->SetBranchAddress("no_doms_hit",&no_doms_hit);
rand_noise_events->SetBranchAddress("no_dus_hit",&no_dus_hit);
rand_noise_events->SetBranchAddress("no_trig_hits",&no_trig_hits);
rand_noise_events->SetBranchAddress("no_doms_trig_hit",&no_doms_trig_hit);
rand_noise_events->SetBranchAddress("no_dus_trig_hit",&no_dus_trig_hit);
rand_noise_events->SetBranchAddress("no_cher_hits",&no_cher_hits);
rand_noise_events->SetBranchAddress("no_doms_cher_hit",&no_doms_cher_hit);
rand_noise_events->SetBranchAddress("no_dus_cher_hit",&no_dus_cher_hit);
rand_noise_events->SetBranchAddress("no_trig_cher_hits",&no_trig_cher_hits);
rand_noise_events->SetBranchAddress("no_doms_trig_cher_hit",&no_doms_trig_cher_hit);
rand_noise_events->SetBranchAddress("no_dus_trig_cher_hit",&no_dus_trig_cher_hit);
rand_noise_events->SetBranchAddress("zenith",&zenith);
rand_noise_events->SetBranchAddress("cos_zen",&cos_zen);
rand_noise_events->SetBranchAddress("max_lik",&max_lik);
rand_noise_events->SetBranchAddress("log_lik",&log_lik);
rand_noise_events->SetBranchAddress("reco_energy",&reco_energy);
rand_noise_events->SetBranchAddress("reco_vrtx_x",&reco_vrtx_x);
rand_noise_events->SetBranchAddress("reco_vrtx_y",&reco_vrtx_y);
rand_noise_events->SetBranchAddress("reco_vrtx_z",&reco_vrtx_z);
rand_noise_events->SetBranchAddress("reco_vrtx_r",&reco_vrtx_r);
rand_noise_events->SetBranchAddress("Nhits",&Nhits);
rand_noise_events->SetBranchAddress("Qhits",&Qhits);
rand_noise_events->SetBranchAddress("beta0",&beta0);
rand_noise_events->SetBranchAddress("TrkLength",&TrkLength);
rand_noise_events->SetBranchAddress("d_closest",&d_closest);
rand_noise_events->SetBranchAddress("z_closest",&z_closest);
rand_noise_events->SetBranchAddress("mean_z_hits",&mean_z_hits);
rand_noise_events->SetBranchAddress("mean_z_trig_hits",&mean_z_trig_hits);
rand_noise_events->SetBranchAddress("mean_z_cher_hits",&mean_z_cher_hits);
rand_noise_events->SetBranchAddress("mean_z_trig_cher_hits",&mean_z_trig_cher_hits);
rand_noise_events->SetBranchAddress("trig_hits_over_all",&trig_hits_over_all);
rand_noise_events->SetBranchAddress("cher_hits_over_all",&cher_hits_over_all);
rand_noise_events->SetBranchAddress("trig_cher_hits_over_all",&trig_cher_hits_over_all);
rand_noise_events->SetBranchAddress("Qup_m_Qdn_JGandalf",&Qup_m_Qdn_JGandalf);
rand_noise_events->SetBranchAddress("max_tot_trig",&max_tot_trig);
rand_noise_events->SetBranchAddress("early_trig_10",&early_trig_10);
rand_noise_events->SetBranchAddress("Dn_m_Up_hits",&Dn_m_Up_hits);
rand_noise_events->SetBranchAddress("Dn_m_Up_trig_hits",&Dn_m_Up_trig_hits);
rand_noise_events->SetBranchAddress("Dn_m_Up_cher_hits",&Dn_m_Up_cher_hits);
rand_noise_events->SetBranchAddress("Dn_m_Up_trig_cher_hits",&Dn_m_Up_trig_cher_hits);

TH1F* h_rand_noise_no_hits = new TH1F("h_rand_noise_no_hits",";# hits;counts;", 1001 , -0.5 , 1000.5 );
TH1F* h_rand_noise_no_hit_doms = new TH1F("h_rand_noise_no_hit_doms","hit DOMs", 108 , 0.5 , 108.5 );
TH1F* h_rand_noise_no_trig_hits = new TH1F("h_rand_noise_trig_hits",";# hits;counts;", 1001 , -0.5 , 1000.5 );
TH1F* h_rand_noise_no_trig_doms = new TH1F("h_rand_noise_trig_doms","triggered DOMs", 108 , 0.5 , 108.5 );
TH1F* h_rand_noise_no_cher_hits = new TH1F("h_rand_noise_no_cher_hits","Cherenkov hits", 1001 , -0.5 , 1000.5 );
TH1F* h_rand_noise_no_cher_doms = new TH1F("h_rand_noise_no_cher_doms","Cherenkov doms", 108 , 0.5 , 108.5 );
TH1F* h_rand_noise_no_trig_cher_doms = new TH1F("h_rand_noise_no_trig_cher_doms","Trig & Cherenkov doms", 72 , 0.5 , 72.5 );
TH1F* h_rand_noise_no_trig_dus = new TH1F("h_rand_noise_no_trig_dus"," DUs", 6 , 0.5 , 6.5 );
TH1F* h_rand_noise_no_cher_dus = new TH1F("h_rand_noise_no_cher_dus"," DUs", 6 , 0.5 , 6.5 );
TH1F* h_rand_noise_no_trig_cher_dus = new TH1F("h_rand_noise_no_trig_cher_dus"," DUs", 6 , 0.5 , 6.5 );
TH1F* h_rand_noise_no_trig_cher_hits = new TH1F("h_rand_noise_no_trig_cher_hits","Trig & Cherenkov hits", 1001 , -0.5 , 1000.5 );
TH1F* h_rand_noise_zenith = new TH1F("h_rand_noise_zenith",";reco zenith [deg]", 180 , 0.0 , 180.0 );
TH1F* h_rand_noise_cos_zenith = new TH1F("h_rand_noise_cos_zen",";cos(reco zenith)", 100 , -1.0 , 1.0 );
TH1F* h_rand_noise_max_lik_dist = new TH1F("h_rand_noise_max_lik",";L;", 100 , 0 , 2000 );
TH1F* h_rand_noise_log_lik_dist = new TH1F("h_rand_noise_log_lik",";log(L);", 100 , -1.0 , 4.0 );
TH1F* h_rand_noise_reco_energy = new TH1F("h_rand_noise_reco_energy",";log[E_reco/GeV];", 40 , 0 , 4.0 );
TH2F* h_rand_noise_reco_vertex_pos = new TH2F("h_rand_noise_reco_vertex_pos",";radial position [m];vertical position [m]", 100, 0 , 100 , 160 , -40 , 280 );
TH1F* h_rand_noise_reco_vrtx_r = new TH1F("h_rand_noise_reco_vrtx_r","reco vrtx radial pos.;r [m];", 40 , 0 , 200 );
TH1F* h_rand_noise_reco_vrtx_x = new TH1F("h_rand_noise_reco_vrtx_x","reco vrtx x pos.;x [m];", 40 , 0 , 200 );
TH1F* h_rand_noise_reco_vrtx_y = new TH1F("h_rand_noise_reco_vrtx_y","reco vrtx y pos.;y [m];", 40 , 0 , 200 );
TH1F* h_rand_noise_reco_vrtx_z = new TH1F("h_rand_noise_reco_vrtx_z","reco vrtx z pos.;z [m];", 40 , 0 , 200 );
TH1F* h_rand_noise_Nhits = new TH1F("h_rand_noise_Nhits",";NHits;", 300 , 0.5 , 300.5 );
TH1F* h_rand_noise_beta0 = new TH1F("h_rand_noise_beta0",";beta0;",100,0,1);
TH1F* h_rand_noise_Qhits = new TH1F("h_rand_noise_Qhits",";L/Nhits;",120,0,6);
TH1F* h_rand_noise_trklength = new TH1F("h_rand_noise_trklength","", 150 , 0 , 300);
TH1F* h_rand_noise_d_closest = new TH1F("h_rand_noise_d_closest",";d_closest [m];", 15 , 0 , 150 );
TH1F* h_rand_noise_z_closest = new TH1F("h_rand_noise_z_closest",";z_closest [m];", 50 , -100 , 400 );
TH1F* h_rand_noise_mean_z_hits = new TH1F("h_rand_noise_mean_z_hits",";vertical position [m];", 160 , -40 , 280 );
TH1F* h_rand_noise_mean_z_trig_hits = new TH1F("h_rand_noise_mean_z_trig_hits",";vertical position [m];", 160 , -40 , 280 );
TH1F* h_rand_noise_mean_z_cher_hits = new TH1F("h_rand_noise_mean_z_cher_hits",";vertical position [m];", 160 , -40 , 280 );
TH1F* h_rand_noise_mean_z_trig_cher_hits = new TH1F("h_rand_noise_mean_z_trig_cher_hits",";vertical position [m];", 160 , -40 , 280 );
TH1F* h_rand_noise_ratio_hits_trig_over_all = new TH1F("h_rand_noise_ratio_hits_trig_over_all","trig_hits/all_hits", 100 , 0.0 , 1.0 );
TH1F* h_rand_noise_ratio_hits_cher_over_all = new TH1F("h_rand_noise_ratio_hits_cher_over_all","cher_hits/all_hits", 100 , 0.0 , 1.0 );
TH1F* h_rand_noise_ratio_hits_trig_cher_over_all = new TH1F("h_rand_noise_ratio_hits_trig_cher_over_all","cher_hits/all_hits", 100 , 0.0 , 1.0 );
TH1F* h_rand_noise_Qup_m_Qdn_JGandalf = new TH1F("h_rand_noise_Qup_m_Qdn_JGandalf","Qup_m_Qdn_JGandalf;Qup-Qdn;", 250 , 0 , 250 );
TH1F* h_rand_noise_max_trig_tot = new TH1F("h_rand_noise_max_trig_tot",";tot [ns];", 100 , 0 , 500 );
TH1F* h_rand_noise_early_trig_10 = new TH1F("h_rand_noise_early_trig_10","", 201 , -0.5 , 200.5 );
TH1F* h_rand_noise_Dn_m_Up_hits = new TH1F("h_rand_noise_Dn_m_Up_hits","Lower_hits_minus_Upper_hits" , 1500 , -500 , 1000);
TH1F* h_rand_noise_Dn_m_Up_trig_hits = new TH1F("h_rand_noise_Dn_m_Up_trig_hits","Lower_hits_minus_Upper_hits_trig" , 1500 , -500 , 1000);
TH1F* h_rand_noise_Dn_m_Up_cher_hits = new TH1F("h_rand_noise_Dn_m_Up_cher_hits","Lower_hits_minus_Upper_hits_cher" , 1500 , -500 , 1000);
TH1F* h_rand_noise_Dn_m_Up_trig_cher_hits = new TH1F("h_rand_noise_Dn_m_Up_trig_cher_hits","Lower_hits_minus_Upper_hits_trig_cher" , 1500 , -500 , 1000);

for( int i=0 ; i<rand_noise_events->GetEntries() ; i++ ){

rand_noise_events->GetEntry(i); // get i-th event parameters

//cuts
//if( (cos_zen<0) && (max_tot_trig<220) && (early_trig_10<5) && (no_doms_cher_hit>5) && (cher_hits_over_all>0.28) && (Dn_m_Up_trig_cher_hits>0) && (Dn_m_Up_cher_hits>5) && (mean_z_cher_hits>55) && (log_lik>1.7) && (Qhits>2.0) && (Nhits>20) && (Qup_m_Qdn_JGandalf>10) && (max_lik/TrkLength>1.5) && (reco_vrtx_r<45.0) && (reco_vrtx_y>-38.0) && (reco_vrtx_y<38.0) && (z_closest<185) ){
if((no_doms_cher_hit>5)&&(log_lik>1.7) ){
//if (Nhits>20){
h_rand_noise_no_hits->Fill(no_hits);
h_rand_noise_no_trig_hits->Fill(no_trig_hits);
h_rand_noise_no_cher_hits->Fill(no_cher_hits);
h_rand_noise_no_trig_cher_hits->Fill(no_trig_cher_hits); 
h_rand_noise_no_hit_doms->Fill(no_doms_hit); 
h_rand_noise_no_trig_doms->Fill(no_doms_trig_hit); 
h_rand_noise_no_cher_doms->Fill(no_doms_cher_hit);
h_rand_noise_no_trig_cher_doms->Fill(no_doms_trig_cher_hit);
h_rand_noise_no_trig_dus->Fill(no_dus_trig_hit);
h_rand_noise_no_cher_dus->Fill(no_dus_cher_hit);
h_rand_noise_no_trig_cher_dus->Fill(no_dus_trig_cher_hit);
h_rand_noise_zenith->Fill(zenith);
h_rand_noise_cos_zenith->Fill(cos_zen);
h_rand_noise_max_lik_dist->Fill(max_lik);
h_rand_noise_log_lik_dist->Fill(log_lik);
h_rand_noise_reco_energy->Fill(TMath::Log10(reco_energy));
h_rand_noise_reco_vertex_pos->Fill(reco_vrtx_r,reco_vrtx_z);
h_rand_noise_reco_vrtx_r->Fill(reco_vrtx_r);
h_rand_noise_reco_vrtx_x->Fill(reco_vrtx_x);
h_rand_noise_reco_vrtx_y->Fill(reco_vrtx_y);
h_rand_noise_reco_vrtx_z->Fill(reco_vrtx_z);
h_rand_noise_Nhits->Fill(Nhits);
h_rand_noise_beta0->Fill(beta0);
h_rand_noise_Qhits->Fill(Qhits);
h_rand_noise_trklength->Fill(TrkLength);
h_rand_noise_d_closest->Fill(d_closest);
h_rand_noise_z_closest->Fill(z_closest);
h_rand_noise_mean_z_hits->Fill(mean_z_hits);
h_rand_noise_mean_z_trig_hits->Fill(mean_z_trig_hits);
h_rand_noise_mean_z_cher_hits->Fill(mean_z_cher_hits);
h_rand_noise_mean_z_trig_cher_hits->Fill(mean_z_trig_cher_hits);
h_rand_noise_ratio_hits_trig_over_all->Fill(trig_hits_over_all);
h_rand_noise_ratio_hits_cher_over_all->Fill(cher_hits_over_all);
h_rand_noise_ratio_hits_trig_cher_over_all->Fill(trig_cher_hits_over_all);
h_rand_noise_Qup_m_Qdn_JGandalf->Fill(Qup_m_Qdn_JGandalf);
h_rand_noise_max_trig_tot->Fill(max_tot_trig);
h_rand_noise_early_trig_10->Fill(early_trig_10);
h_rand_noise_Dn_m_Up_hits->Fill(Dn_m_Up_hits);
h_rand_noise_Dn_m_Up_trig_hits->Fill(Dn_m_Up_trig_hits);
h_rand_noise_Dn_m_Up_cher_hits->Fill(Dn_m_Up_cher_hits);
h_rand_noise_Dn_m_Up_trig_cher_hits->Fill(Dn_m_Up_trig_cher_hits);

 }

if(i%1000000==0) cout << "Random Noise Ev. = " << i << endl;

//if(100<0= 

}

// scale random noise histograms to the muon livetime - data livetime
// divide with the # of runs giving the rate (s^-1), then multiply with the data livetime //change again total_mc_atm_muon_livetime again in the end//

h_rand_noise_no_hits->Scale(total_data_livetime/total_rand_no_livetime);
h_rand_noise_no_trig_hits->Scale(total_data_livetime/total_rand_no_livetime);
h_rand_noise_no_cher_hits->Scale(total_data_livetime/total_rand_no_livetime);
h_rand_noise_no_trig_cher_hits->Scale(total_data_livetime/total_rand_no_livetime); 
h_rand_noise_no_hit_doms->Scale(total_data_livetime/total_rand_no_livetime); 
h_rand_noise_no_trig_doms->Scale(total_data_livetime/total_rand_no_livetime); 
h_rand_noise_no_cher_doms->Scale(total_data_livetime/total_rand_no_livetime);
h_rand_noise_no_trig_cher_doms->Scale(total_data_livetime/total_rand_no_livetime);
h_rand_noise_no_trig_dus->Scale(total_data_livetime/total_rand_no_livetime);
h_rand_noise_no_cher_dus->Scale(total_data_livetime/total_rand_no_livetime);
h_rand_noise_no_trig_cher_dus->Scale(total_data_livetime/total_rand_no_livetime);
h_rand_noise_zenith->Scale(total_data_livetime/total_rand_no_livetime);
h_rand_noise_cos_zenith->Scale(total_data_livetime/total_rand_no_livetime);
h_rand_noise_max_lik_dist->Scale(total_data_livetime/total_rand_no_livetime);
h_rand_noise_log_lik_dist->Scale(total_data_livetime/total_rand_no_livetime);
h_rand_noise_reco_energy->Scale(total_data_livetime/total_rand_no_livetime);
h_rand_noise_reco_vertex_pos->Scale(total_data_livetime/total_rand_no_livetime);
h_rand_noise_reco_vrtx_r->Scale(total_data_livetime/total_rand_no_livetime);
h_rand_noise_reco_vrtx_x->Scale(total_data_livetime/total_rand_no_livetime);
h_rand_noise_reco_vrtx_y->Scale(total_data_livetime/total_rand_no_livetime);
h_rand_noise_reco_vrtx_z->Scale(total_data_livetime/total_rand_no_livetime);
h_rand_noise_Nhits->Scale(total_data_livetime/total_rand_no_livetime);
h_rand_noise_beta0->Scale(total_data_livetime/total_rand_no_livetime);
h_rand_noise_Qhits->Scale(total_data_livetime/total_rand_no_livetime);
h_rand_noise_trklength->Scale(total_data_livetime/total_rand_no_livetime);
h_rand_noise_d_closest->Scale(total_data_livetime/total_rand_no_livetime);
h_rand_noise_z_closest->Scale(total_data_livetime/total_rand_no_livetime);
h_rand_noise_mean_z_hits->Scale(total_data_livetime/total_rand_no_livetime);
h_rand_noise_mean_z_trig_hits->Scale(total_data_livetime/total_rand_no_livetime);
h_rand_noise_mean_z_cher_hits->Scale(total_data_livetime/total_rand_no_livetime);
h_rand_noise_mean_z_trig_cher_hits->Scale(total_data_livetime/total_rand_no_livetime);
h_rand_noise_ratio_hits_trig_over_all->Scale(total_data_livetime/total_rand_no_livetime);
h_rand_noise_ratio_hits_cher_over_all->Scale(total_data_livetime/total_rand_no_livetime);
h_rand_noise_ratio_hits_trig_cher_over_all->Scale(total_data_livetime/total_rand_no_livetime);
h_rand_noise_Qup_m_Qdn_JGandalf->Scale(total_data_livetime/total_rand_no_livetime);
h_rand_noise_max_trig_tot->Scale(total_data_livetime/total_rand_no_livetime);
h_rand_noise_early_trig_10->Scale(total_data_livetime/total_rand_no_livetime);
h_rand_noise_Dn_m_Up_hits->Scale(total_data_livetime/total_rand_no_livetime);
h_rand_noise_Dn_m_Up_trig_hits->Scale(total_data_livetime/total_rand_no_livetime);
h_rand_noise_Dn_m_Up_cher_hits->Scale(total_data_livetime/total_rand_no_livetime);
h_rand_noise_Dn_m_Up_trig_cher_hits->Scale(total_data_livetime/total_rand_no_livetime); */


TFile* f_out = new TFile( outname.c_str() ,"RECREATE"); // output file that contains the TTree 


// end of data categories


/*
// write data distributions
h_data_no_hits->Write();
h_data_no_trig_hits->Write();
h_data_no_cher_hits->Write();
h_data_no_trig_cher_hits-> Write();
h_data_no_hit_doms-> Write();
h_data_no_trig_doms-> Write();
h_data_no_cher_doms->Write();
h_data_no_trig_cher_doms->Write();
h_data_no_trig_dus->Write();
h_data_no_cher_dus->Write();
h_data_no_trig_cher_dus->Write();
h_data_cos_zenith->Write();
h_data_no_hits->Write();
h_data_no_trig_hits->Write();
h_data_no_cher_hits->Write();
h_data_no_trig_cher_hits->Write();
h_data_no_hit_doms->Write();
h_data_no_trig_doms->Write();
h_data_no_cher_doms->Write();
h_data_no_trig_cher_doms->Write();
h_data_no_trig_dus->Write();
h_data_no_cher_dus->Write();
h_data_no_trig_cher_dus->Write();
h_data_cos_zenith->Write();
h_data_max_lik_dist->Write();
h_data_log_lik_dist->Write();
h_data_reco_energy->Write();
h_data_reco_vertex_pos->Write();
h_data_reco_vrtx_r->Write();
h_data_reco_vrtx_x->Write();
h_data_reco_vrtx_y->Write();
h_data_reco_vrtx_z->Write();
h_data_Nhits->Write();
h_data_beta0->Write();
h_data_Qhits->Write();
h_data_trklength->Write();
h_data_d_closest->Write();
h_data_z_closest->Write();
h_data_mean_z_hits->Write();
h_data_mean_z_trig_hits->Write();
h_data_mean_z_cher_hits->Write();
h_data_mean_z_trig_cher_hits->Write();
h_data_ratio_hits_trig_over_all->Write();
h_data_ratio_hits_cher_over_all->Write();
h_data_ratio_hits_trig_cher_over_all->Write();
h_data_Qup_m_Qdn_JGandalf->Write();
h_data_max_trig_tot->Write();
h_data_early_trig_10->Write();
h_data_Dn_m_Up_hits->Write();
h_data_Dn_m_Up_trig_hits->Write();
h_data_Dn_m_Up_cher_hits->Write();
h_data_Dn_m_Up_trig_cher_hits->Write();

// atm. muon MC
h_mc_atm_muon_no_hits->Write();
h_mc_atm_muon_no_trig_hits->Write();
h_mc_atm_muon_no_cher_hits->Write();
h_mc_atm_muon_no_trig_cher_hits-> Write();
h_mc_atm_muon_no_hit_doms-> Write();
h_mc_atm_muon_no_trig_doms-> Write();
h_mc_atm_muon_no_cher_doms->Write();
h_mc_atm_muon_no_trig_cher_doms->Write();
h_mc_atm_muon_no_trig_dus->Write();
h_mc_atm_muon_no_cher_dus->Write();
h_mc_atm_muon_no_trig_cher_dus->Write();
h_mc_atm_muon_cos_zenith->Write();
h_mc_atm_muon_no_hits->Write();
h_mc_atm_muon_no_trig_hits->Write();
h_mc_atm_muon_no_cher_hits->Write();
h_mc_atm_muon_no_trig_cher_hits->Write();
h_mc_atm_muon_no_hit_doms->Write();
h_mc_atm_muon_no_trig_doms->Write();
h_mc_atm_muon_no_cher_doms->Write();
h_mc_atm_muon_no_trig_cher_doms->Write();
h_mc_atm_muon_no_trig_dus->Write();
h_mc_atm_muon_no_cher_dus->Write();
h_mc_atm_muon_no_trig_cher_dus->Write();
h_mc_atm_muon_zenith->Write();
h_mc_atm_muon_true_zenith->Write();
h_mc_atm_muon_cos_zenith->Write();
h_mc_atm_muon_true_cos_zen->Write();
h_mc_atm_muon_max_lik_dist->Write();
h_mc_atm_muon_log_lik_dist->Write();
h_mc_atm_muon_true_energy->Write();
h_mc_atm_muon_reco_energy->Write();
h_mc_atm_muon_reco_vertex_pos->Write();
h_mc_atm_muon_reco_vrtx_r->Write();
h_mc_atm_muon_reco_vrtx_x->Write();
h_mc_atm_muon_reco_vrtx_y->Write();
h_mc_atm_muon_reco_vrtx_z->Write();
h_mc_atm_muon_Nhits->Write();
h_mc_atm_muon_beta0->Write();
h_mc_atm_muon_Qhits->Write();
h_mc_atm_muon_trklength->Write();
h_mc_atm_muon_d_closest->Write();
h_mc_atm_muon_z_closest->Write();
h_mc_atm_muon_mean_z_hits->Write();
h_mc_atm_muon_mean_z_trig_hits->Write();
h_mc_atm_muon_mean_z_cher_hits->Write();
h_mc_atm_muon_mean_z_trig_cher_hits->Write();
h_mc_atm_muon_ratio_hits_trig_over_all->Write();
h_mc_atm_muon_ratio_hits_cher_over_all->Write();
h_mc_atm_muon_ratio_hits_trig_cher_over_all->Write();
h_mc_atm_muon_Qup_m_Qdn_JGandalf->Write();
h_mc_atm_muon_max_trig_tot->Write();
h_mc_atm_muon_early_trig_10->Write();
h_mc_atm_muon_Dn_m_Up_hits->Write();
h_mc_atm_muon_Dn_m_Up_trig_hits->Write();
h_mc_atm_muon_Dn_m_Up_cher_hits->Write();
h_mc_atm_muon_Dn_m_Up_trig_cher_hits->Write();
*/
// atm. neutrino MC
 // atm. neutrino MC
 
 h_mc_atm_nu_horizontal_diff_energy -> Write();
 h_mc_atm_nu_horizontal_no_hits->Write();
 h_mc_atm_nu_horizontal_no_trig_hits->Write();
 h_mc_atm_nu_horizontal_no_cher_hits->Write();
 h_mc_atm_nu_horizontal_no_trig_cher_hits-> Write();
 h_mc_atm_nu_horizontal_no_hit_doms-> Write();
 h_mc_atm_nu_horizontal_no_trig_doms-> Write();
 h_mc_atm_nu_horizontal_no_cher_doms->Write();
 h_mc_atm_nu_horizontal_no_trig_cher_doms->Write();
 h_mc_atm_nu_horizontal_no_trig_dus->Write();
 h_mc_atm_nu_horizontal_no_cher_dus->Write();
 h_mc_atm_nu_horizontal_no_trig_cher_dus->Write();
 h_mc_atm_nu_horizontal_cos_zenith->Write();
 h_mc_atm_nu_horizontal_no_hits->Write();
 h_mc_atm_nu_horizontal_no_trig_hits->Write();
 h_mc_atm_nu_horizontal_no_cher_hits->Write();
 h_mc_atm_nu_horizontal_no_trig_cher_hits->Write();
 h_mc_atm_nu_horizontal_no_hit_doms->Write();
 h_mc_atm_nu_horizontal_no_trig_doms->Write();
 h_mc_atm_nu_horizontal_no_cher_doms->Write();
 h_mc_atm_nu_horizontal_no_trig_cher_doms->Write();
 h_mc_atm_nu_horizontal_no_trig_dus->Write();
 h_mc_atm_nu_horizontal_no_cher_dus->Write();
 h_mc_atm_nu_horizontal_no_trig_cher_dus->Write();
 h_mc_atm_nu_horizontal_zenith->Write();
 h_mc_atm_nu_horizontal_true_zenith->Write();
 h_mc_atm_nu_horizontal_cos_zenith->Write();
 h_mc_atm_nu_horizontal_true_cos_zen->Write();
 h_mc_atm_nu_horizontal_max_lik_dist->Write();
 h_mc_atm_nu_horizontal_log_lik_dist->Write();
 h_mc_atm_nu_horizontal_true_energy->Write();
 h_mc_atm_nu_horizontal_true_energy_no_log -> Write();
 h_mc_atm_nu_horizontal_reco_energy->Write();
 h_mc_atm_nu_horizontal_E_reco_E_true_rec_zen_all -> Write();
 h_mc_atm_nu_horizontal_E_reco_E_true_rec_zen_30_all-> Write();//inserted for the job requested by boss
 h_mc_atm_nu_horizontal_E_reco_E_true_rec_zen_120_all->Write();
 h_mc_atm_nu_horizontal_E_reco_E_true_rec_zen_150_all->Write();
 h_mc_atm_nu_horizontal_reco_vrtx_r->Write();
 h_mc_atm_nu_horizontal_reco_vrtx_x->Write();
 h_mc_atm_nu_horizontal_reco_vrtx_y->Write();
 h_mc_atm_nu_horizontal_reco_vrtx_z->Write();
 h_mc_atm_nu_horizontal_Nhits->Write();
 h_mc_atm_nu_horizontal_beta0->Write();
 h_mc_atm_nu_horizontal_Qhits->Write();
 h_mc_atm_nu_horizontal_trklength->Write();
 h_mc_atm_nu_horizontal_d_closest->Write();
 h_mc_atm_nu_horizontal_z_closest->Write();
 h_mc_atm_nu_horizontal_mean_z_hits->Write();
 h_mc_atm_nu_horizontal_mean_z_trig_hits->Write();
 h_mc_atm_nu_horizontal_mean_z_cher_hits->Write();
 h_mc_atm_nu_horizontal_mean_z_trig_cher_hits->Write();
 h_mc_atm_nu_horizontal_ratio_hits_trig_over_all->Write();
 h_mc_atm_nu_horizontal_ratio_hits_cher_over_all->Write();
 h_mc_atm_nu_horizontal_ratio_hits_trig_cher_over_all->Write();
 h_mc_atm_nu_horizontal_Qup_m_Qdn_JGandalf->Write();
 h_mc_atm_nu_horizontal_max_trig_tot->Write();
 h_mc_atm_nu_horizontal_early_trig_10->Write();
 h_mc_atm_nu_horizontal_Dn_m_Up_hits->Write();
 h_mc_atm_nu_horizontal_Dn_m_Up_trig_hits->Write();
 h_mc_atm_nu_horizontal_Dn_m_Up_cher_hits->Write();
 h_mc_atm_nu_horizontal_Dn_m_Up_trig_cher_hits->Write();
 h_mc_atm_nu_horizontal_diff_energy_cos_zen -> Write();
 h_mc_atm_nu_horizontal_E_true_zenith_horizontal -> Write();
 h_mc_atm_nu_horizontal_E_true_zenith_upgoing -> Write();
 
 
h_mc_atm_nu_horizontal_lslice_diff_energy -> Write();
 h_mc_atm_nu_horizontal_lslice_no_hits->Write();
 h_mc_atm_nu_horizontal_lslice_no_trig_hits->Write();
 h_mc_atm_nu_horizontal_lslice_no_cher_hits->Write();
 h_mc_atm_nu_horizontal_lslice_no_trig_cher_hits-> Write();
 h_mc_atm_nu_horizontal_lslice_no_hit_doms-> Write();
 h_mc_atm_nu_horizontal_lslice_no_trig_doms-> Write();
 h_mc_atm_nu_horizontal_lslice_no_cher_doms->Write();
 h_mc_atm_nu_horizontal_lslice_no_trig_cher_doms->Write();
 h_mc_atm_nu_horizontal_lslice_no_trig_dus->Write();
 h_mc_atm_nu_horizontal_lslice_no_cher_dus->Write();
 h_mc_atm_nu_horizontal_lslice_no_trig_cher_dus->Write();
 h_mc_atm_nu_horizontal_lslice_cos_zenith->Write();
 h_mc_atm_nu_horizontal_lslice_no_hits->Write();
 h_mc_atm_nu_horizontal_lslice_no_trig_hits->Write();
 h_mc_atm_nu_horizontal_lslice_no_cher_hits->Write();
 h_mc_atm_nu_horizontal_lslice_no_trig_cher_hits->Write();
 h_mc_atm_nu_horizontal_lslice_no_hit_doms->Write();
 h_mc_atm_nu_horizontal_lslice_no_trig_doms->Write();
 h_mc_atm_nu_horizontal_lslice_no_cher_doms->Write();
 h_mc_atm_nu_horizontal_lslice_no_trig_cher_doms->Write();
 h_mc_atm_nu_horizontal_lslice_no_trig_dus->Write();
 h_mc_atm_nu_horizontal_lslice_no_cher_dus->Write();
 h_mc_atm_nu_horizontal_lslice_no_trig_cher_dus->Write();
 h_mc_atm_nu_horizontal_lslice_zenith->Write();
 h_mc_atm_nu_horizontal_lslice_true_zenith->Write();
 h_mc_atm_nu_horizontal_lslice_cos_zenith->Write();
 h_mc_atm_nu_horizontal_lslice_true_cos_zen->Write();
 h_mc_atm_nu_horizontal_lslice_max_lik_dist->Write();
 h_mc_atm_nu_horizontal_lslice_log_lik_dist->Write();
 h_mc_atm_nu_horizontal_lslice_true_energy->Write();
 h_mc_atm_nu_horizontal_lslice_true_energy_no_log -> Write();
 h_mc_atm_nu_horizontal_lslice_reco_energy->Write();
 h_mc_atm_nu_horizontal_lslice_reco_vertex_pos->Write();
 h_mc_atm_nu_horizontal_lslice_reco_vrtx_r->Write();
 h_mc_atm_nu_horizontal_lslice_reco_vrtx_x->Write();
 h_mc_atm_nu_horizontal_lslice_reco_vrtx_y->Write();
 h_mc_atm_nu_horizontal_lslice_reco_vrtx_z->Write();
 h_mc_atm_nu_horizontal_lslice_Nhits->Write();
 h_mc_atm_nu_horizontal_lslice_beta0->Write();
 h_mc_atm_nu_horizontal_lslice_Qhits->Write();
 h_mc_atm_nu_horizontal_lslice_trklength->Write();
 h_mc_atm_nu_horizontal_lslice_d_closest->Write();
 h_mc_atm_nu_horizontal_lslice_z_closest->Write();
 h_mc_atm_nu_horizontal_lslice_mean_z_hits->Write();
 h_mc_atm_nu_horizontal_lslice_mean_z_trig_hits->Write();
 h_mc_atm_nu_horizontal_lslice_mean_z_cher_hits->Write();
 h_mc_atm_nu_horizontal_lslice_mean_z_trig_cher_hits->Write();
 h_mc_atm_nu_horizontal_lslice_ratio_hits_trig_over_all->Write();
 h_mc_atm_nu_horizontal_lslice_ratio_hits_cher_over_all->Write();
 h_mc_atm_nu_horizontal_lslice_ratio_hits_trig_cher_over_all->Write();
 h_mc_atm_nu_horizontal_lslice_Qup_m_Qdn_JGandalf->Write();
 h_mc_atm_nu_horizontal_lslice_max_trig_tot->Write();
 h_mc_atm_nu_horizontal_lslice_early_trig_10->Write();
 h_mc_atm_nu_horizontal_lslice_Dn_m_Up_hits->Write();
 h_mc_atm_nu_horizontal_lslice_Dn_m_Up_trig_hits->Write();
 h_mc_atm_nu_horizontal_lslice_Dn_m_Up_cher_hits->Write();
 h_mc_atm_nu_horizontal_lslice_Dn_m_Up_trig_cher_hits->Write();
 h_mc_atm_nu_horizontal_lslice_diff_energy_cos_zen -> Write();
 h_mc_atm_nu_horizontal_lslice_he_reco_vrtx_r-> Write();
 h_mc_atm_nu_horizontal_lslice_le_reco_vrtx_r-> Write();
 h_mc_atm_nu_horizontal_lslice_he_mean_z_hits-> Write();
 h_mc_atm_nu_horizontal_lslice_le_mean_z_hits-> Write();
 h_mc_atm_nu_horizontal_lslice_he_reco_vertex_pos-> Write();
 h_mc_atm_nu_horizontal_lslice_he_trklength ->Write();
 h_mc_atm_nu_horizontal_lslice_le_trklength ->Write();
 h_mc_atm_nu_horizontal_lslice_le_zenith -> Write();
 h_mc_atm_nu_horizontal_lslice_he_zenith -> Write();
 h_mc_atm_nu_horizontal_lslice_le_no_hit_doms -> Write();
 h_mc_atm_nu_horizontal_lslice_le_no_cher_doms -> Write();
 h_mc_atm_nu_horizontal_lslice_le_Nhits-> Write();
 h_mc_atm_nu_horizontal_lslice_le_beta0 -> Write();
 h_mc_atm_nu_horizontal_lslice_le_Qhits -> Write();
 h_mc_atm_nu_horizontal_lslice_he_no_hit_doms -> Write();
 h_mc_atm_nu_horizontal_lslice_he_no_cher_doms -> Write();
 h_mc_atm_nu_horizontal_lslice_he_Nhits-> Write();
 h_mc_atm_nu_horizontal_lslice_he_beta0 -> Write();
 h_mc_atm_nu_horizontal_lslice_he_Qhits -> Write(); 
 h_mc_atm_nu_horizontal_lslice_he_reco_vrtx_z-> Write();
 h_mc_atm_nu_horizontal_lslice_le_reco_vrtx_z-> Write();
 h_mc_atm_nu_horizontal_lslice_le_true_phi -> Write();
 h_mc_atm_nu_horizontal_lslice_le_reco_phi -> Write();
 h_mc_atm_nu_horizontal_lslice_le_bjorken_y-> Write();
 h_mc_atm_nu_horizontal_lslice_he_true_phi -> Write();
 h_mc_atm_nu_horizontal_lslice_he_reco_phi -> Write();
 h_mc_atm_nu_horizontal_lslice_he_bjorken_y-> Write();
 h_mc_atm_nu_horizontal_lslice_le_d_closest ->Write();
 h_mc_atm_nu_horizontal_lslice_le_z_closest ->Write();
 h_mc_atm_nu_horizontal_lslice_he_d_closest ->Write();
 h_mc_atm_nu_horizontal_lslice_he_z_closest ->Write();

 
 //--------------- mslice -------------------------------
 h_mc_atm_nu_horizontal_mslice_diff_energy -> Write();
 h_mc_atm_nu_horizontal_mslice_no_hits->Write();
 h_mc_atm_nu_horizontal_mslice_no_trig_hits->Write();
 h_mc_atm_nu_horizontal_mslice_no_cher_hits->Write();
 h_mc_atm_nu_horizontal_mslice_no_trig_cher_hits-> Write();
 h_mc_atm_nu_horizontal_mslice_no_hit_doms-> Write();
 h_mc_atm_nu_horizontal_mslice_no_trig_doms-> Write();
 h_mc_atm_nu_horizontal_mslice_no_cher_doms->Write();
 h_mc_atm_nu_horizontal_mslice_no_trig_cher_doms->Write();
 h_mc_atm_nu_horizontal_mslice_no_trig_dus->Write();
 h_mc_atm_nu_horizontal_mslice_no_cher_dus->Write();
 h_mc_atm_nu_horizontal_mslice_no_trig_cher_dus->Write();
 h_mc_atm_nu_horizontal_mslice_cos_zenith->Write();
 h_mc_atm_nu_horizontal_mslice_no_hits->Write();
 h_mc_atm_nu_horizontal_mslice_no_trig_hits->Write();
 h_mc_atm_nu_horizontal_mslice_no_cher_hits->Write();
 h_mc_atm_nu_horizontal_mslice_no_trig_cher_hits->Write();
 h_mc_atm_nu_horizontal_mslice_no_hit_doms->Write();
 h_mc_atm_nu_horizontal_mslice_no_trig_doms->Write();
 h_mc_atm_nu_horizontal_mslice_no_cher_doms->Write();
 h_mc_atm_nu_horizontal_mslice_no_trig_cher_doms->Write();
 h_mc_atm_nu_horizontal_mslice_no_trig_dus->Write();
 h_mc_atm_nu_horizontal_mslice_no_cher_dus->Write();
 h_mc_atm_nu_horizontal_mslice_no_trig_cher_dus->Write();
 h_mc_atm_nu_horizontal_mslice_zenith->Write();
 h_mc_atm_nu_horizontal_mslice_true_zenith->Write();
 h_mc_atm_nu_horizontal_mslice_cos_zenith->Write();
 h_mc_atm_nu_horizontal_mslice_true_cos_zen->Write();
 h_mc_atm_nu_horizontal_mslice_max_lik_dist->Write();
 h_mc_atm_nu_horizontal_mslice_log_lik_dist->Write();
 h_mc_atm_nu_horizontal_mslice_true_energy->Write();
 h_mc_atm_nu_horizontal_mslice_true_energy_no_log -> Write();
 h_mc_atm_nu_horizontal_mslice_reco_energy->Write();
 h_mc_atm_nu_horizontal_mslice_reco_vertex_pos->Write();
 h_mc_atm_nu_horizontal_mslice_reco_vrtx_r->Write();
 h_mc_atm_nu_horizontal_mslice_reco_vrtx_x->Write();
 h_mc_atm_nu_horizontal_mslice_reco_vrtx_y->Write();
 h_mc_atm_nu_horizontal_mslice_reco_vrtx_z->Write();
 h_mc_atm_nu_horizontal_mslice_Nhits->Write(); 
 h_mc_atm_nu_horizontal_mslice_beta0->Write();
 h_mc_atm_nu_horizontal_mslice_Qhits->Write();
 h_mc_atm_nu_horizontal_mslice_trklength->Write();
 h_mc_atm_nu_horizontal_mslice_d_closest->Write();
 h_mc_atm_nu_horizontal_mslice_z_closest->Write();
 h_mc_atm_nu_horizontal_mslice_mean_z_hits->Write();
 h_mc_atm_nu_horizontal_mslice_mean_z_trig_hits->Write();
 h_mc_atm_nu_horizontal_mslice_mean_z_cher_hits->Write();
 h_mc_atm_nu_horizontal_mslice_mean_z_trig_cher_hits->Write();
 h_mc_atm_nu_horizontal_mslice_ratio_hits_trig_over_all->Write();
 h_mc_atm_nu_horizontal_mslice_ratio_hits_cher_over_all->Write();
 h_mc_atm_nu_horizontal_mslice_ratio_hits_trig_cher_over_all->Write();
 h_mc_atm_nu_horizontal_mslice_Qup_m_Qdn_JGandalf->Write();
 h_mc_atm_nu_horizontal_mslice_max_trig_tot->Write();
 h_mc_atm_nu_horizontal_mslice_early_trig_10->Write();
 h_mc_atm_nu_horizontal_mslice_Dn_m_Up_hits->Write();
 h_mc_atm_nu_horizontal_mslice_Dn_m_Up_trig_hits->Write();
 h_mc_atm_nu_horizontal_mslice_Dn_m_Up_cher_hits->Write();
 h_mc_atm_nu_horizontal_mslice_Dn_m_Up_trig_cher_hits->Write();
 h_mc_atm_nu_horizontal_mslice_diff_energy_cos_zen -> Write();

h_mc_atm_nu_horizontal_mslice_le_reco_vrtx_r->Write();
h_mc_atm_nu_horizontal_mslice_le_mean_z_hits->Write();
h_mc_atm_nu_horizontal_mslice_le_trklength ->Write();
h_mc_atm_nu_horizontal_mslice_le_zenith ->Write();
h_mc_atm_nu_horizontal_mslice_le_no_hit_doms -> Write();
h_mc_atm_nu_horizontal_mslice_le_no_cher_doms -> Write();
h_mc_atm_nu_horizontal_mslice_le_Nhits-> Write();
h_mc_atm_nu_horizontal_mslice_le_beta0 -> Write();
h_mc_atm_nu_horizontal_mslice_le_Qhits -> Write();
h_mc_atm_nu_horizontal_mslice_le_reco_vrtx_z -> Write();
h_mc_atm_nu_horizontal_mslice_le_true_phi ->Write();
h_mc_atm_nu_horizontal_mslice_le_reco_phi ->Write();
h_mc_atm_nu_horizontal_mslice_le_bjorken_y ->Write();
h_mc_atm_nu_horizontal_mslice_le_d_closest ->Write();
h_mc_atm_nu_horizontal_mslice_le_z_closest ->Write();

h_mc_atm_nu_horizontal_mslice_me_reco_vrtx_r->Write();
h_mc_atm_nu_horizontal_mslice_me_mean_z_hits->Write();
h_mc_atm_nu_horizontal_mslice_me_trklength ->Write();
h_mc_atm_nu_horizontal_mslice_me_zenith ->Write();
h_mc_atm_nu_horizontal_mslice_me_no_hit_doms -> Write();
h_mc_atm_nu_horizontal_mslice_me_no_cher_doms -> Write();
h_mc_atm_nu_horizontal_mslice_me_Nhits-> Write();
h_mc_atm_nu_horizontal_mslice_me_beta0 -> Write();
h_mc_atm_nu_horizontal_mslice_me_Qhits -> Write();
h_mc_atm_nu_horizontal_mslice_me_reco_vrtx_z -> Write();
h_mc_atm_nu_horizontal_mslice_me_true_phi ->Write();
h_mc_atm_nu_horizontal_mslice_me_reco_phi ->Write();
h_mc_atm_nu_horizontal_mslice_me_bjorken_y ->Write();
h_mc_atm_nu_horizontal_mslice_me_d_closest ->Write();
h_mc_atm_nu_horizontal_mslice_me_z_closest ->Write();

h_mc_atm_nu_horizontal_mslice_he_reco_vrtx_r->Write();
h_mc_atm_nu_horizontal_mslice_he_mean_z_hits->Write();
h_mc_atm_nu_horizontal_mslice_he_trklength ->Write();
h_mc_atm_nu_horizontal_mslice_he_zenith ->Write();
h_mc_atm_nu_horizontal_mslice_he_no_hit_doms -> Write();
h_mc_atm_nu_horizontal_mslice_he_no_cher_doms -> Write();
h_mc_atm_nu_horizontal_mslice_he_Nhits-> Write();
h_mc_atm_nu_horizontal_mslice_he_beta0 -> Write();
h_mc_atm_nu_horizontal_mslice_he_Qhits -> Write();
h_mc_atm_nu_horizontal_mslice_he_reco_vrtx_z -> Write();
h_mc_atm_nu_horizontal_mslice_he_true_phi ->Write();
h_mc_atm_nu_horizontal_mslice_he_reco_phi ->Write();
h_mc_atm_nu_horizontal_mslice_he_bjorken_y ->Write();
h_mc_atm_nu_horizontal_mslice_he_d_closest ->Write();
h_mc_atm_nu_horizontal_mslice_he_z_closest ->Write();





 //--------------- high energy slice ---------------- 
 
 h_mc_atm_nu_horizontal_hslice_diff_energy -> Write();
 h_mc_atm_nu_horizontal_hslice_no_hits->Write();
 h_mc_atm_nu_horizontal_hslice_no_trig_hits->Write();
 h_mc_atm_nu_horizontal_hslice_no_cher_hits->Write();
 h_mc_atm_nu_horizontal_hslice_no_trig_cher_hits-> Write();
 h_mc_atm_nu_horizontal_hslice_no_hit_doms-> Write();
 h_mc_atm_nu_horizontal_hslice_no_trig_doms-> Write();
 h_mc_atm_nu_horizontal_hslice_no_cher_doms->Write();
 h_mc_atm_nu_horizontal_hslice_no_trig_cher_doms->Write();
 h_mc_atm_nu_horizontal_hslice_no_trig_dus->Write();
 h_mc_atm_nu_horizontal_hslice_no_cher_dus->Write();
 h_mc_atm_nu_horizontal_hslice_no_trig_cher_dus->Write();
 h_mc_atm_nu_horizontal_hslice_cos_zenith->Write();
 h_mc_atm_nu_horizontal_hslice_no_hits->Write();
 h_mc_atm_nu_horizontal_hslice_no_trig_hits->Write();
 h_mc_atm_nu_horizontal_hslice_no_cher_hits->Write();
 h_mc_atm_nu_horizontal_hslice_no_trig_cher_hits->Write();
 h_mc_atm_nu_horizontal_hslice_no_hit_doms->Write();
 h_mc_atm_nu_horizontal_hslice_no_trig_doms->Write();
 h_mc_atm_nu_horizontal_hslice_no_cher_doms->Write();
 h_mc_atm_nu_horizontal_hslice_no_trig_cher_doms->Write();
 h_mc_atm_nu_horizontal_hslice_no_trig_dus->Write();
 h_mc_atm_nu_horizontal_hslice_no_cher_dus->Write();
 h_mc_atm_nu_horizontal_hslice_no_trig_cher_dus->Write();
 h_mc_atm_nu_horizontal_hslice_zenith->Write();
 h_mc_atm_nu_horizontal_hslice_true_zenith->Write();
 h_mc_atm_nu_horizontal_hslice_cos_zenith->Write();
 h_mc_atm_nu_horizontal_hslice_true_cos_zen->Write();
 h_mc_atm_nu_horizontal_hslice_max_lik_dist->Write();
 h_mc_atm_nu_horizontal_hslice_log_lik_dist->Write();
 h_mc_atm_nu_horizontal_hslice_true_energy->Write();
 h_mc_atm_nu_horizontal_hslice_true_energy_no_log -> Write();
 h_mc_atm_nu_horizontal_hslice_reco_energy->Write();
 h_mc_atm_nu_horizontal_hslice_reco_vertex_pos->Write();
 h_mc_atm_nu_horizontal_hslice_reco_vrtx_r->Write();
 h_mc_atm_nu_horizontal_hslice_reco_vrtx_x->Write();
 h_mc_atm_nu_horizontal_hslice_reco_vrtx_y->Write();
 h_mc_atm_nu_horizontal_hslice_reco_vrtx_z->Write();
 h_mc_atm_nu_horizontal_hslice_Nhits->Write();
 h_mc_atm_nu_horizontal_hslice_beta0->Write();
 h_mc_atm_nu_horizontal_hslice_Qhits->Write();
 h_mc_atm_nu_horizontal_hslice_trklength->Write();
 h_mc_atm_nu_horizontal_hslice_d_closest->Write();
 h_mc_atm_nu_horizontal_hslice_z_closest->Write();
 h_mc_atm_nu_horizontal_hslice_mean_z_hits->Write();
 h_mc_atm_nu_horizontal_hslice_mean_z_trig_hits->Write();
 h_mc_atm_nu_horizontal_hslice_mean_z_cher_hits->Write();
 h_mc_atm_nu_horizontal_hslice_mean_z_trig_cher_hits->Write();
 h_mc_atm_nu_horizontal_hslice_ratio_hits_trig_over_all->Write();
 h_mc_atm_nu_horizontal_hslice_ratio_hits_cher_over_all->Write();
 h_mc_atm_nu_horizontal_hslice_ratio_hits_trig_cher_over_all->Write();
 h_mc_atm_nu_horizontal_hslice_Qup_m_Qdn_JGandalf->Write();
 h_mc_atm_nu_horizontal_hslice_max_trig_tot->Write();
 h_mc_atm_nu_horizontal_hslice_early_trig_10->Write();
 h_mc_atm_nu_horizontal_hslice_Dn_m_Up_hits->Write();
 h_mc_atm_nu_horizontal_hslice_Dn_m_Up_trig_hits->Write();
 h_mc_atm_nu_horizontal_hslice_Dn_m_Up_cher_hits->Write();
 h_mc_atm_nu_horizontal_hslice_Dn_m_Up_trig_cher_hits->Write();
 h_mc_atm_nu_horizontal_hslice_diff_energy_cos_zen -> Write();
 h_mc_atm_nu_horizontal_hslice_he_reco_vertex_pos-> Write();
 h_mc_atm_nu_horizontal_hslice_he_trklength -> Write();
 h_mc_atm_nu_horizontal_hslice_le_trklength -> Write(); 
 h_mc_atm_nu_horizontal_hslice_trk_reco_energy -> Write();
 h_mc_atm_nu_horizontal_hslice_trk_true_energy -> Write();
 h_mc_atm_nu_horizontal_hslice_le_zenith -> Write();
 h_mc_atm_nu_horizontal_hslice_he_zenith -> Write();
 h_mc_atm_nu_horizontal_hslice_le_no_hit_doms -> Write();
 h_mc_atm_nu_horizontal_hslice_le_no_cher_doms -> Write();
 h_mc_atm_nu_horizontal_hslice_le_Nhits-> Write();
 h_mc_atm_nu_horizontal_hslice_le_beta0 -> Write();
 h_mc_atm_nu_horizontal_hslice_le_Qhits -> Write();
 h_mc_atm_nu_horizontal_hslice_he_no_hit_doms -> Write();
 h_mc_atm_nu_horizontal_hslice_he_no_cher_doms -> Write();
 h_mc_atm_nu_horizontal_hslice_he_Nhits-> Write();
 h_mc_atm_nu_horizontal_hslice_he_beta0 -> Write();
 h_mc_atm_nu_horizontal_hslice_he_Qhits -> Write();
 h_mc_atm_nu_horizontal_hslice_he_reco_vrtx_r-> Write();
 h_mc_atm_nu_horizontal_hslice_le_reco_vrtx_r-> Write();
 h_mc_atm_nu_horizontal_hslice_he_mean_z_hits-> Write();
 h_mc_atm_nu_horizontal_hslice_le_mean_z_hits-> Write();
 h_mc_atm_nu_horizontal_hslice_he_reco_vrtx_z-> Write();
 h_mc_atm_nu_horizontal_hslice_le_reco_vrtx_z-> Write();

 h_mc_atm_nu_horizontal_hslice_le_true_phi -> Write();
 h_mc_atm_nu_horizontal_hslice_le_reco_phi -> Write();
 h_mc_atm_nu_horizontal_hslice_le_bjorken_y-> Write();

 h_mc_atm_nu_horizontal_hslice_he_true_phi -> Write();
 h_mc_atm_nu_horizontal_hslice_he_reco_phi -> Write();
 h_mc_atm_nu_horizontal_hslice_he_bjorken_y-> Write();

 h_mc_atm_nu_horizontal_hslice_le_d_closest ->Write();
 h_mc_atm_nu_horizontal_hslice_le_z_closest ->Write();
 h_mc_atm_nu_horizontal_hslice_he_d_closest ->Write();
 h_mc_atm_nu_horizontal_hslice_he_z_closest ->Write();
 



//For the upgoing condition 
// atm. neutrino MC
 // atm. neutrino MC
h_mc_atm_nu_upgoing_diff_energy -> Write();
h_mc_atm_nu_upgoing_no_hits->Write();
h_mc_atm_nu_upgoing_no_trig_hits->Write();
h_mc_atm_nu_upgoing_no_cher_hits->Write();
h_mc_atm_nu_upgoing_no_trig_cher_hits-> Write();
h_mc_atm_nu_upgoing_no_hit_doms-> Write();
h_mc_atm_nu_upgoing_no_trig_doms-> Write();
h_mc_atm_nu_upgoing_no_cher_doms->Write();
h_mc_atm_nu_upgoing_no_trig_cher_doms->Write();
h_mc_atm_nu_upgoing_no_trig_dus->Write();
h_mc_atm_nu_upgoing_no_cher_dus->Write();
h_mc_atm_nu_upgoing_no_trig_cher_dus->Write();
h_mc_atm_nu_upgoing_cos_zenith->Write();
h_mc_atm_nu_upgoing_no_hits->Write();
h_mc_atm_nu_upgoing_no_trig_hits->Write();
h_mc_atm_nu_upgoing_no_cher_hits->Write();
h_mc_atm_nu_upgoing_no_trig_cher_hits->Write();
h_mc_atm_nu_upgoing_no_hit_doms->Write();
h_mc_atm_nu_upgoing_no_trig_doms->Write();
h_mc_atm_nu_upgoing_no_cher_doms->Write();
h_mc_atm_nu_upgoing_no_trig_cher_doms->Write();
h_mc_atm_nu_upgoing_no_trig_dus->Write();
h_mc_atm_nu_upgoing_no_cher_dus->Write();
h_mc_atm_nu_upgoing_no_trig_cher_dus->Write();
h_mc_atm_nu_upgoing_zenith->Write();
h_mc_atm_nu_upgoing_true_zenith->Write();
h_mc_atm_nu_upgoing_cos_zenith->Write();
h_mc_atm_nu_upgoing_true_cos_zen->Write();
h_mc_atm_nu_upgoing_max_lik_dist->Write();
h_mc_atm_nu_upgoing_log_lik_dist->Write();
h_mc_atm_nu_upgoing_true_energy->Write();
h_mc_atm_nu_upgoing_true_energy_no_log -> Write();
h_mc_atm_nu_upgoing_reco_energy->Write();
h_mc_atm_nu_upgoing_E_reco_E_true_rec_zen_all -> Write();
h_mc_atm_nu_upgoing_E_reco_E_true_rec_zen_30_all-> Write();//inserted for the job requested by boss
h_mc_atm_nu_upgoing_E_reco_E_true_rec_zen_150_all->Write();
h_mc_atm_nu_upgoing_reco_vertex_pos->Write();
h_mc_atm_nu_upgoing_reco_vrtx_r->Write();
h_mc_atm_nu_upgoing_reco_vrtx_x->Write();
h_mc_atm_nu_upgoing_reco_vrtx_y->Write();
h_mc_atm_nu_upgoing_reco_vrtx_z->Write();
h_mc_atm_nu_upgoing_Nhits->Write();
h_mc_atm_nu_upgoing_beta0->Write();
h_mc_atm_nu_upgoing_Qhits->Write();
h_mc_atm_nu_upgoing_trklength->Write();
h_mc_atm_nu_upgoing_d_closest->Write();
h_mc_atm_nu_upgoing_z_closest->Write();
h_mc_atm_nu_upgoing_mean_z_hits->Write();
h_mc_atm_nu_upgoing_mean_z_trig_hits->Write();
h_mc_atm_nu_upgoing_mean_z_cher_hits->Write();
h_mc_atm_nu_upgoing_mean_z_trig_cher_hits->Write();
h_mc_atm_nu_upgoing_ratio_hits_trig_over_all->Write();
h_mc_atm_nu_upgoing_ratio_hits_cher_over_all->Write();
h_mc_atm_nu_upgoing_ratio_hits_trig_cher_over_all->Write();
h_mc_atm_nu_upgoing_Qup_m_Qdn_JGandalf->Write();
h_mc_atm_nu_upgoing_max_trig_tot->Write();
h_mc_atm_nu_upgoing_early_trig_10->Write();
h_mc_atm_nu_upgoing_Dn_m_Up_hits->Write();
h_mc_atm_nu_upgoing_Dn_m_Up_trig_hits->Write();
h_mc_atm_nu_upgoing_Dn_m_Up_cher_hits->Write();
h_mc_atm_nu_upgoing_Dn_m_Up_trig_cher_hits->Write();
h_mc_atm_nu_upgoing_diff_energy_cos_zen -> Write();
h_mc_atm_nu_upgoing_E_true_zenith_horizontal -> Write();
h_mc_atm_nu_upgoing_E_true_zenith_upgoing -> Write();

//--------------------- Low section --------------------------
h_mc_atm_nu_upgoing_lslice_diff_energy -> Write();
h_mc_atm_nu_upgoing_lslice_no_hits->Write();
h_mc_atm_nu_upgoing_lslice_no_trig_hits->Write();
h_mc_atm_nu_upgoing_lslice_no_cher_hits->Write();
h_mc_atm_nu_upgoing_lslice_no_trig_cher_hits-> Write();
h_mc_atm_nu_upgoing_lslice_no_hit_doms-> Write();
h_mc_atm_nu_upgoing_lslice_no_trig_doms-> Write();
h_mc_atm_nu_upgoing_lslice_no_cher_doms->Write();
h_mc_atm_nu_upgoing_lslice_no_trig_cher_doms->Write();
h_mc_atm_nu_upgoing_lslice_no_trig_dus->Write();
h_mc_atm_nu_upgoing_lslice_no_cher_dus->Write();
h_mc_atm_nu_upgoing_lslice_no_trig_cher_dus->Write();
h_mc_atm_nu_upgoing_lslice_cos_zenith->Write();
h_mc_atm_nu_upgoing_lslice_no_hits->Write();
h_mc_atm_nu_upgoing_lslice_no_trig_hits->Write();
h_mc_atm_nu_upgoing_lslice_no_cher_hits->Write();
h_mc_atm_nu_upgoing_lslice_no_trig_cher_hits->Write();
h_mc_atm_nu_upgoing_lslice_no_hit_doms->Write();
h_mc_atm_nu_upgoing_lslice_no_trig_doms->Write();
h_mc_atm_nu_upgoing_lslice_no_cher_doms->Write();
h_mc_atm_nu_upgoing_lslice_no_trig_cher_doms->Write();
h_mc_atm_nu_upgoing_lslice_no_trig_dus->Write();
h_mc_atm_nu_upgoing_lslice_no_cher_dus->Write();
h_mc_atm_nu_upgoing_lslice_no_trig_cher_dus->Write();
h_mc_atm_nu_upgoing_lslice_zenith->Write();
h_mc_atm_nu_upgoing_lslice_true_zenith->Write();
h_mc_atm_nu_upgoing_lslice_cos_zenith->Write();
h_mc_atm_nu_upgoing_lslice_true_cos_zen->Write();
h_mc_atm_nu_upgoing_lslice_max_lik_dist->Write();
h_mc_atm_nu_upgoing_lslice_log_lik_dist->Write();
h_mc_atm_nu_upgoing_lslice_true_energy->Write();
h_mc_atm_nu_upgoing_lslice_true_energy_no_log -> Write();
h_mc_atm_nu_upgoing_lslice_reco_energy->Write();
h_mc_atm_nu_upgoing_lslice_reco_vertex_pos->Write();
h_mc_atm_nu_upgoing_lslice_reco_vrtx_r->Write();
h_mc_atm_nu_upgoing_lslice_reco_vrtx_x->Write();
h_mc_atm_nu_upgoing_lslice_reco_vrtx_y->Write();
h_mc_atm_nu_upgoing_lslice_reco_vrtx_z->Write();
h_mc_atm_nu_upgoing_lslice_Nhits->Write();
h_mc_atm_nu_upgoing_lslice_beta0->Write();
h_mc_atm_nu_upgoing_lslice_Qhits->Write();
h_mc_atm_nu_upgoing_lslice_trklength->Write();
h_mc_atm_nu_upgoing_lslice_d_closest->Write();
h_mc_atm_nu_upgoing_lslice_z_closest->Write();
h_mc_atm_nu_upgoing_lslice_mean_z_hits->Write();
h_mc_atm_nu_upgoing_lslice_mean_z_trig_hits->Write();
h_mc_atm_nu_upgoing_lslice_mean_z_cher_hits->Write();
h_mc_atm_nu_upgoing_lslice_mean_z_trig_cher_hits->Write();
h_mc_atm_nu_upgoing_lslice_ratio_hits_trig_over_all->Write();
h_mc_atm_nu_upgoing_lslice_ratio_hits_cher_over_all->Write();
h_mc_atm_nu_upgoing_lslice_ratio_hits_trig_cher_over_all->Write();
h_mc_atm_nu_upgoing_lslice_Qup_m_Qdn_JGandalf->Write();
h_mc_atm_nu_upgoing_lslice_max_trig_tot->Write();
h_mc_atm_nu_upgoing_lslice_early_trig_10->Write();
h_mc_atm_nu_upgoing_lslice_Dn_m_Up_hits->Write();
h_mc_atm_nu_upgoing_lslice_Dn_m_Up_trig_hits->Write();
h_mc_atm_nu_upgoing_lslice_Dn_m_Up_cher_hits->Write();
h_mc_atm_nu_upgoing_lslice_Dn_m_Up_trig_cher_hits->Write();
h_mc_atm_nu_upgoing_lslice_diff_energy_cos_zen -> Write();
h_mc_atm_nu_upgoing_lslice_he_reco_vrtx_r-> Write();
h_mc_atm_nu_upgoing_lslice_le_reco_vrtx_r-> Write();
h_mc_atm_nu_upgoing_lslice_he_mean_z_hits-> Write();
h_mc_atm_nu_upgoing_lslice_le_mean_z_hits-> Write();
h_mc_atm_nu_upgoing_lslice_he_reco_vertex_pos-> Write();
h_mc_atm_nu_upgoing_lslice_le_reco_vertex_pos-> Write();
h_mc_atm_nu_upgoing_lslice_he_trklength ->Write();
h_mc_atm_nu_upgoing_lslice_le_trklength ->Write();
h_mc_atm_nu_upgoing_lslice_le_zenith -> Write();
h_mc_atm_nu_upgoing_lslice_he_zenith -> Write();
h_mc_atm_nu_upgoing_lslice_le_no_hit_doms -> Write();
h_mc_atm_nu_upgoing_lslice_le_no_cher_doms -> Write();
h_mc_atm_nu_upgoing_lslice_le_Nhits-> Write();
h_mc_atm_nu_upgoing_lslice_le_beta0 -> Write();
h_mc_atm_nu_upgoing_lslice_le_Qhits -> Write();
h_mc_atm_nu_upgoing_lslice_he_no_hit_doms -> Write();
h_mc_atm_nu_upgoing_lslice_he_no_cher_doms -> Write();
h_mc_atm_nu_upgoing_lslice_he_Nhits-> Write();
h_mc_atm_nu_upgoing_lslice_he_beta0 -> Write();
h_mc_atm_nu_upgoing_lslice_he_Qhits -> Write();
h_mc_atm_nu_upgoing_lslice_he_reco_vrtx_z-> Write();
h_mc_atm_nu_upgoing_lslice_le_reco_vrtx_z-> Write();
h_mc_atm_nu_upgoing_lslice_le_true_phi -> Write();
h_mc_atm_nu_upgoing_lslice_le_reco_phi -> Write();
h_mc_atm_nu_upgoing_lslice_le_bjorken_y-> Write();

h_mc_atm_nu_upgoing_lslice_he_true_phi -> Write();
h_mc_atm_nu_upgoing_lslice_he_reco_phi -> Write();
h_mc_atm_nu_upgoing_lslice_he_bjorken_y-> Write();

 h_mc_atm_nu_upgoing_lslice_le_d_closest ->Write();
 h_mc_atm_nu_upgoing_lslice_le_z_closest ->Write();
 h_mc_atm_nu_upgoing_lslice_he_d_closest ->Write();
 h_mc_atm_nu_upgoing_lslice_he_z_closest ->Write();

 


//-------------------Medium Slice --------------------
h_mc_atm_nu_upgoing_mslice_diff_energy -> Write();
h_mc_atm_nu_upgoing_mslice_no_hits->Write();
h_mc_atm_nu_upgoing_mslice_no_trig_hits->Write();
h_mc_atm_nu_upgoing_mslice_no_cher_hits->Write();
h_mc_atm_nu_upgoing_mslice_no_trig_cher_hits-> Write();
h_mc_atm_nu_upgoing_mslice_no_hit_doms-> Write();
h_mc_atm_nu_upgoing_mslice_no_trig_doms-> Write();
h_mc_atm_nu_upgoing_mslice_no_cher_doms->Write();
h_mc_atm_nu_upgoing_mslice_no_trig_cher_doms->Write();
h_mc_atm_nu_upgoing_mslice_no_trig_dus->Write();
h_mc_atm_nu_upgoing_mslice_no_cher_dus->Write();
h_mc_atm_nu_upgoing_mslice_no_trig_cher_dus->Write();
h_mc_atm_nu_upgoing_mslice_no_hits->Write();
h_mc_atm_nu_upgoing_mslice_no_trig_hits->Write();
h_mc_atm_nu_upgoing_mslice_no_cher_hits->Write();
h_mc_atm_nu_upgoing_mslice_no_trig_cher_hits->Write();
h_mc_atm_nu_upgoing_mslice_no_hit_doms->Write();
h_mc_atm_nu_upgoing_mslice_no_trig_doms->Write();
h_mc_atm_nu_upgoing_mslice_no_cher_doms->Write();
h_mc_atm_nu_upgoing_mslice_no_trig_cher_doms->Write();
h_mc_atm_nu_upgoing_mslice_no_trig_dus->Write();
h_mc_atm_nu_upgoing_mslice_no_cher_dus->Write();
h_mc_atm_nu_upgoing_mslice_no_trig_cher_dus->Write();
h_mc_atm_nu_upgoing_mslice_zenith->Write();
h_mc_atm_nu_upgoing_mslice_true_zenith->Write();
h_mc_atm_nu_upgoing_mslice_cos_zenith->Write();
h_mc_atm_nu_upgoing_mslice_true_cos_zen->Write();
h_mc_atm_nu_upgoing_mslice_max_lik_dist->Write();
h_mc_atm_nu_upgoing_mslice_log_lik_dist->Write();
h_mc_atm_nu_upgoing_mslice_true_energy->Write();
h_mc_atm_nu_upgoing_mslice_true_energy_no_log -> Write();
h_mc_atm_nu_upgoing_mslice_reco_energy->Write();
h_mc_atm_nu_upgoing_mslice_reco_vertex_pos->Write();
h_mc_atm_nu_upgoing_mslice_reco_vrtx_r->Write();
h_mc_atm_nu_upgoing_mslice_reco_vrtx_x->Write();
h_mc_atm_nu_upgoing_mslice_reco_vrtx_y->Write();
h_mc_atm_nu_upgoing_mslice_reco_vrtx_z->Write();
h_mc_atm_nu_upgoing_mslice_Nhits->Write();
h_mc_atm_nu_upgoing_mslice_he_reco_vrtx_r-> Write();
h_mc_atm_nu_upgoing_mslice_le_reco_vrtx_r-> Write();
h_mc_atm_nu_upgoing_mslice_he_mean_z_hits-> Write();
h_mc_atm_nu_upgoing_mslice_le_mean_z_hits-> Write();
h_mc_atm_nu_upgoing_mslice_beta0->Write();
h_mc_atm_nu_upgoing_mslice_Qhits->Write();
h_mc_atm_nu_upgoing_mslice_trklength->Write();
h_mc_atm_nu_upgoing_mslice_d_closest->Write();
h_mc_atm_nu_upgoing_mslice_z_closest->Write();
h_mc_atm_nu_upgoing_mslice_mean_z_hits->Write();
h_mc_atm_nu_upgoing_mslice_mean_z_trig_hits->Write();
h_mc_atm_nu_upgoing_mslice_mean_z_cher_hits->Write();
h_mc_atm_nu_upgoing_mslice_mean_z_trig_cher_hits->Write();
h_mc_atm_nu_upgoing_mslice_ratio_hits_trig_over_all->Write();
h_mc_atm_nu_upgoing_mslice_ratio_hits_cher_over_all->Write();
h_mc_atm_nu_upgoing_mslice_ratio_hits_trig_cher_over_all->Write();
h_mc_atm_nu_upgoing_mslice_Qup_m_Qdn_JGandalf->Write();
h_mc_atm_nu_upgoing_mslice_max_trig_tot->Write();
h_mc_atm_nu_upgoing_mslice_early_trig_10->Write();
h_mc_atm_nu_upgoing_mslice_Dn_m_Up_hits->Write();
h_mc_atm_nu_upgoing_mslice_Dn_m_Up_trig_hits->Write();
h_mc_atm_nu_upgoing_mslice_Dn_m_Up_cher_hits->Write();
h_mc_atm_nu_upgoing_mslice_Dn_m_Up_trig_cher_hits->Write();
h_mc_atm_nu_upgoing_mslice_diff_energy_cos_zen -> Write();

h_mc_atm_nu_upgoing_mslice_le_reco_vrtx_r->Write();
h_mc_atm_nu_upgoing_mslice_le_mean_z_hits->Write();
h_mc_atm_nu_upgoing_mslice_le_trklength ->Write();
h_mc_atm_nu_upgoing_mslice_le_zenith ->Write();
h_mc_atm_nu_upgoing_mslice_le_no_hit_doms -> Write();
h_mc_atm_nu_upgoing_mslice_le_no_cher_doms -> Write();
h_mc_atm_nu_upgoing_mslice_le_Nhits-> Write();
h_mc_atm_nu_upgoing_mslice_le_beta0 -> Write();
h_mc_atm_nu_upgoing_mslice_le_Qhits -> Write();
h_mc_atm_nu_upgoing_mslice_le_reco_vrtx_z -> Write();
h_mc_atm_nu_upgoing_mslice_le_true_phi ->Write();
h_mc_atm_nu_upgoing_mslice_le_reco_phi ->Write();
h_mc_atm_nu_upgoing_mslice_le_bjorken_y ->Write();
h_mc_atm_nu_upgoing_mslice_le_d_closest ->Write();
h_mc_atm_nu_upgoing_mslice_le_z_closest ->Write();

h_mc_atm_nu_upgoing_mslice_me_reco_vrtx_r->Write();
h_mc_atm_nu_upgoing_mslice_me_mean_z_hits->Write();
h_mc_atm_nu_upgoing_mslice_me_trklength ->Write();
h_mc_atm_nu_upgoing_mslice_me_zenith ->Write();
h_mc_atm_nu_upgoing_mslice_me_no_hit_doms -> Write();
h_mc_atm_nu_upgoing_mslice_me_no_cher_doms -> Write();
h_mc_atm_nu_upgoing_mslice_me_Nhits-> Write();
h_mc_atm_nu_upgoing_mslice_me_beta0 -> Write();
h_mc_atm_nu_upgoing_mslice_me_Qhits -> Write();
h_mc_atm_nu_upgoing_mslice_me_reco_vrtx_z -> Write();
h_mc_atm_nu_upgoing_mslice_me_true_phi ->Write();
h_mc_atm_nu_upgoing_mslice_me_reco_phi ->Write();
h_mc_atm_nu_upgoing_mslice_me_bjorken_y ->Write();
h_mc_atm_nu_upgoing_mslice_me_d_closest ->Write();
h_mc_atm_nu_upgoing_mslice_me_z_closest ->Write();

h_mc_atm_nu_upgoing_mslice_he_reco_vrtx_r->Write();
h_mc_atm_nu_upgoing_mslice_he_mean_z_hits->Write();
h_mc_atm_nu_upgoing_mslice_he_trklength ->Write();
h_mc_atm_nu_upgoing_mslice_he_zenith ->Write();
h_mc_atm_nu_upgoing_mslice_he_no_hit_doms -> Write();
h_mc_atm_nu_upgoing_mslice_he_no_cher_doms -> Write();
h_mc_atm_nu_upgoing_mslice_he_Nhits-> Write();
h_mc_atm_nu_upgoing_mslice_he_beta0 -> Write();
h_mc_atm_nu_upgoing_mslice_he_Qhits -> Write();
h_mc_atm_nu_upgoing_mslice_he_reco_vrtx_z -> Write();
h_mc_atm_nu_upgoing_mslice_he_true_phi ->Write();
h_mc_atm_nu_upgoing_mslice_he_reco_phi ->Write();
h_mc_atm_nu_upgoing_mslice_he_bjorken_y ->Write();
h_mc_atm_nu_upgoing_mslice_he_d_closest ->Write();
h_mc_atm_nu_upgoing_mslice_he_z_closest ->Write();


//--------------- High Slice ---------------- 
h_mc_atm_nu_upgoing_hslice_diff_energy -> Write();
h_mc_atm_nu_upgoing_hslice_no_hits->Write();
h_mc_atm_nu_upgoing_hslice_no_trig_hits->Write();
h_mc_atm_nu_upgoing_hslice_no_cher_hits->Write();
h_mc_atm_nu_upgoing_hslice_no_trig_cher_hits-> Write();
h_mc_atm_nu_upgoing_hslice_no_hit_doms-> Write();
h_mc_atm_nu_upgoing_hslice_no_trig_doms-> Write();
h_mc_atm_nu_upgoing_hslice_no_cher_doms->Write();
h_mc_atm_nu_upgoing_hslice_no_trig_cher_doms->Write();
h_mc_atm_nu_upgoing_hslice_no_trig_dus->Write();
h_mc_atm_nu_upgoing_hslice_no_cher_dus->Write();
h_mc_atm_nu_upgoing_hslice_no_trig_cher_dus->Write();
h_mc_atm_nu_upgoing_hslice_cos_zenith->Write();
h_mc_atm_nu_upgoing_hslice_no_hits->Write();
h_mc_atm_nu_upgoing_hslice_no_trig_hits->Write();
h_mc_atm_nu_upgoing_hslice_no_cher_hits->Write();
h_mc_atm_nu_upgoing_hslice_no_trig_cher_hits->Write();
h_mc_atm_nu_upgoing_hslice_no_hit_doms->Write();
h_mc_atm_nu_upgoing_hslice_no_trig_doms->Write();
h_mc_atm_nu_upgoing_hslice_no_cher_doms->Write();
h_mc_atm_nu_upgoing_hslice_no_trig_cher_doms->Write();
h_mc_atm_nu_upgoing_hslice_no_trig_dus->Write();
h_mc_atm_nu_upgoing_hslice_no_cher_dus->Write();
h_mc_atm_nu_upgoing_hslice_no_trig_cher_dus->Write();
h_mc_atm_nu_upgoing_hslice_zenith->Write();
h_mc_atm_nu_upgoing_hslice_true_zenith->Write();
h_mc_atm_nu_upgoing_hslice_cos_zenith->Write();
h_mc_atm_nu_upgoing_hslice_true_cos_zen->Write();
h_mc_atm_nu_upgoing_hslice_max_lik_dist->Write();
h_mc_atm_nu_upgoing_hslice_log_lik_dist->Write();
h_mc_atm_nu_upgoing_hslice_true_energy->Write();
h_mc_atm_nu_upgoing_hslice_true_energy_no_log -> Write();
h_mc_atm_nu_upgoing_hslice_reco_energy->Write();
h_mc_atm_nu_upgoing_hslice_reco_vertex_pos->Write();
h_mc_atm_nu_upgoing_hslice_reco_vrtx_r->Write();
h_mc_atm_nu_upgoing_hslice_reco_vrtx_x->Write();
h_mc_atm_nu_upgoing_hslice_reco_vrtx_y->Write();
h_mc_atm_nu_upgoing_hslice_reco_vrtx_z->Write();
h_mc_atm_nu_upgoing_hslice_Nhits->Write();
h_mc_atm_nu_upgoing_hslice_beta0->Write();
h_mc_atm_nu_upgoing_hslice_Qhits->Write();
h_mc_atm_nu_upgoing_hslice_trklength->Write();
h_mc_atm_nu_upgoing_hslice_d_closest->Write();
h_mc_atm_nu_upgoing_hslice_z_closest->Write();
h_mc_atm_nu_upgoing_hslice_mean_z_hits->Write();
h_mc_atm_nu_upgoing_hslice_mean_z_trig_hits->Write();
h_mc_atm_nu_upgoing_hslice_mean_z_cher_hits->Write();
h_mc_atm_nu_upgoing_hslice_mean_z_trig_cher_hits->Write();
h_mc_atm_nu_upgoing_hslice_ratio_hits_trig_over_all->Write();
h_mc_atm_nu_upgoing_hslice_ratio_hits_cher_over_all->Write();
h_mc_atm_nu_upgoing_hslice_ratio_hits_trig_cher_over_all->Write();
h_mc_atm_nu_upgoing_hslice_Qup_m_Qdn_JGandalf->Write();
h_mc_atm_nu_upgoing_hslice_max_trig_tot->Write();
h_mc_atm_nu_upgoing_hslice_early_trig_10->Write();
h_mc_atm_nu_upgoing_hslice_Dn_m_Up_hits->Write();
h_mc_atm_nu_upgoing_hslice_Dn_m_Up_trig_hits->Write();
h_mc_atm_nu_upgoing_hslice_Dn_m_Up_cher_hits->Write();
h_mc_atm_nu_upgoing_hslice_Dn_m_Up_trig_cher_hits->Write();
h_mc_atm_nu_upgoing_hslice_diff_energy_cos_zen -> Write();
h_mc_atm_nu_upgoing_hslice_he_reco_vrtx_r-> Write();
h_mc_atm_nu_upgoing_hslice_le_reco_vrtx_r-> Write();
h_mc_atm_nu_upgoing_hslice_he_mean_z_hits-> Write();
h_mc_atm_nu_upgoing_hslice_le_mean_z_hits-> Write();
h_mc_atm_nu_upgoing_hslice_he_reco_vertex_pos-> Write();
h_mc_atm_nu_upgoing_hslice_he_trklength -> Write();
h_mc_atm_nu_upgoing_hslice_le_trklength -> Write();
h_mc_atm_nu_upgoing_hslice_trk_reco_energy -> Write();
h_mc_atm_nu_upgoing_hslice_trk_true_energy -> Write();
h_mc_atm_nu_upgoing_hslice_le_zenith -> Write();
h_mc_atm_nu_upgoing_hslice_he_zenith -> Write();
h_mc_atm_nu_upgoing_hslice_le_no_hit_doms -> Write();
h_mc_atm_nu_upgoing_hslice_le_no_cher_doms -> Write();
h_mc_atm_nu_upgoing_hslice_le_Nhits-> Write();
h_mc_atm_nu_upgoing_hslice_le_beta0 -> Write();
h_mc_atm_nu_upgoing_hslice_le_Qhits -> Write();
h_mc_atm_nu_upgoing_hslice_he_no_hit_doms -> Write();
h_mc_atm_nu_upgoing_hslice_he_no_cher_doms -> Write();
h_mc_atm_nu_upgoing_hslice_he_Nhits-> Write();
h_mc_atm_nu_upgoing_hslice_he_beta0 -> Write();
h_mc_atm_nu_upgoing_hslice_he_Qhits -> Write(); 
h_mc_atm_nu_upgoing_hslice_he_reco_vrtx_z-> Write();
h_mc_atm_nu_upgoing_hslice_le_reco_vrtx_z-> Write();
h_mc_atm_nu_upgoing_hslice_le_true_phi -> Write();
h_mc_atm_nu_upgoing_hslice_le_reco_phi -> Write();
h_mc_atm_nu_upgoing_hslice_le_bjorken_y-> Write();

h_mc_atm_nu_upgoing_hslice_he_true_phi -> Write();
h_mc_atm_nu_upgoing_hslice_he_reco_phi -> Write();
h_mc_atm_nu_upgoing_hslice_he_bjorken_y-> Write();

 h_mc_atm_nu_upgoing_hslice_le_d_closest ->Write();
 h_mc_atm_nu_upgoing_hslice_le_z_closest ->Write();
 h_mc_atm_nu_upgoing_hslice_he_d_closest ->Write();
 h_mc_atm_nu_upgoing_hslice_he_z_closest ->Write();



 

// rand noise MC
 /*
h_rand_noise_no_hits->Write();
h_rand_noise_no_trig_hits->Write();
h_rand_noise_no_cher_hits->Write();
h_rand_noise_no_trig_cher_hits-> Write();
h_rand_noise_no_hit_doms-> Write();
h_rand_noise_no_trig_doms-> Write();
h_rand_noise_no_cher_doms->Write();
h_rand_noise_no_trig_cher_doms->Write();
h_rand_noise_no_trig_dus->Write();
h_rand_noise_no_cher_dus->Write();
h_rand_noise_no_trig_cher_dus->Write();
h_rand_noise_cos_zenith->Write();
h_rand_noise_no_hits->Write();
h_rand_noise_no_trig_hits->Write();
h_rand_noise_no_cher_hits->Write();
h_rand_noise_no_trig_cher_hits->Write();
h_rand_noise_no_hit_doms->Write();
h_rand_noise_no_trig_doms->Write();
h_rand_noise_no_cher_doms->Write();
h_rand_noise_no_trig_cher_doms->Write();
h_rand_noise_no_trig_dus->Write();
h_rand_noise_no_cher_dus->Write();
h_rand_noise_no_trig_cher_dus->Write();
h_rand_noise_zenith->Write();
h_rand_noise_cos_zenith->Write();
h_rand_noise_max_lik_dist->Write();
h_rand_noise_log_lik_dist->Write();
h_rand_noise_reco_energy->Write();
h_rand_noise_reco_vertex_pos->Write();
h_rand_noise_reco_vrtx_r->Write();
h_rand_noise_reco_vrtx_x->Write();
h_rand_noise_reco_vrtx_y->Write();
h_rand_noise_reco_vrtx_z->Write();
h_rand_noise_Nhits->Write();
h_rand_noise_beta0->Write();
h_rand_noise_Qhits->Write();
h_rand_noise_trklength->Write();
h_rand_noise_d_closest->Write();
h_rand_noise_z_closest->Write();
h_rand_noise_mean_z_hits->Write();
h_rand_noise_mean_z_trig_hits->Write();
h_rand_noise_mean_z_cher_hits->Write();
h_rand_noise_mean_z_trig_cher_hits->Write();
h_rand_noise_ratio_hits_trig_over_all->Write();
h_rand_noise_ratio_hits_cher_over_all->Write();
h_rand_noise_ratio_hits_trig_cher_over_all->Write();
h_rand_noise_Qup_m_Qdn_JGandalf->Write();
h_rand_noise_max_trig_tot->Write();
h_rand_noise_early_trig_10->Write();
h_rand_noise_Dn_m_Up_hits->Write();
h_rand_noise_Dn_m_Up_trig_hits->Write();
h_rand_noise_Dn_m_Up_cher_hits->Write();
h_rand_noise_Dn_m_Up_trig_cher_hits->Write(); 
*/

f_out->Write();

return 0;
}
