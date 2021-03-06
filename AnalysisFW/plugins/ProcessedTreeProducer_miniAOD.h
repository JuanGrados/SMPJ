#ifndef ProcessedTreeProducer_miniAOD_h
#define ProcessedTreeProducer_miniAOD_h

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "HLTrigger/HLTcore/interface/HLTConfigProvider.h"
#include "DataFormats/Common/interface/TriggerResults.h"
#include "DataFormats/HLTReco/interface/TriggerEvent.h"
#include "JetMETCorrections/Objects/interface/JetCorrector.h"
#include "CondFormats/JetMETObjects/interface/JetCorrectionUncertainty.h"
#include "DataFormats/PatCandidates/interface/Jet.h"
#include "DataFormats/PatCandidates/interface/JetCorrFactors.h"
#include "SMPJ/AnalysisFW/interface/QCDJet.h"
#include "SMPJ/AnalysisFW/interface/QCDEvent.h"
#include "SMPJ/AnalysisFW/interface/QCDEventHdr.h"
#include "SMPJ/AnalysisFW/interface/QCDCaloJet.h"
#include "SMPJ/AnalysisFW/interface/QCDPFJet.h"
#include "SMPJ/AnalysisFW/interface/QCDMET.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"
#include "DataFormats/PatCandidates/interface/MET.h"
#include "DataFormats/PatCandidates/interface/PackedCandidate.h"

#include "DataFormats/L1Trigger/interface/L1JetParticle.h"

#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "DataFormats/Math/interface/deltaR.h"
#include "FWCore/Common/interface/TriggerNames.h"
#include "DataFormats/Common/interface/TriggerResults.h"
#include "DataFormats/PatCandidates/interface/TriggerObjectStandAlone.h"
#include "DataFormats/PatCandidates/interface/PackedTriggerPrescales.h"

using namespace edm;
using namespace reco;
using namespace std;
using namespace trigger;

class ProcessedTreeProducer_miniAOD : public edm::EDAnalyzer
{
  public:
    typedef reco::Particle::LorentzVector LorentzVector;
    explicit ProcessedTreeProducer_miniAOD(edm::ParameterSet const& cfg);
    virtual void beginJob();
    virtual void beginRun(edm::Run const &, edm::EventSetup const& iSetup);
    virtual void analyze(edm::Event const& evt, edm::EventSetup const& iSetup);
    virtual void endJob();
    virtual ~ProcessedTreeProducer_miniAOD();
  private:
    void buildTree();
    static bool sort_calojets(QCDCaloJet j1, QCDCaloJet j2) {
      return j1.ptCor() > j2.ptCor();
    }
    static bool sort_pfjets(QCDPFJet j1, QCDPFJet j2) {
      return j1.ptCor() > j2.ptCor();
    }

    //edm::EDGetTokenT<edm::TriggerResults> triggerBits_;
    //edm::EDGetTokenT<pat::TriggerObjectStandAloneCollection> triggerObjects_;
    //edm::EDGetTokenT<pat::PackedTriggerPrescales> triggerPrescales_;

    std::vector<std::string> triggerObjects_;
    std::vector<unsigned int> triggerPrescales_;

    //---- configurable parameters --------
    //bool   mEventInfo;
    bool   mIsMCarlo;
    bool   mUseGenInfo;
    bool   mPrintTriggerMenu;
    bool   isPFJecUncSet_,isCaloJecUncSet_,isPFJecUncSetCHS_;
    int    mGoodVtxNdof,mMinNCaloJets,mMinNPFJets;
    double mGoodVtxZ;
    double mMinCaloPt,mMinPFPt,mMinPFFatPt,mMaxPFFatEta,mMinGenPt,mMaxY,mMinJJMass;
    std::string mCaloJECservice;
    std::string mPFJECservice;
    std::string mPFPayloadName;
    std::string mPFPayloadNameCHS;
    std::string mCaloPayloadName;
    // unc file for non CHS jet ---- //
    std::string mPFJECUncSrc;
    // unc file for CHS jet ---- //
    std::string mPFJECUncSrcCHS;
    std::vector<std::string> mPFJECUncSrcNames;
    edm::InputTag mCaloJetsName;
    // ---- non CHS jet input tag ----- //
    edm::InputTag mPFJetsName;
    // ----CHS jet input tag ----- //
    edm::InputTag mPFJetsNameCHS;
    edm::InputTag mGenJetsName;
    edm::InputTag mCaloJetID;
    edm::InputTag mCaloJetExtender;
    edm::InputTag mOfflineVertices;
    edm::InputTag mSrcCaloRho;
    edm::InputTag mSrcPFRho;
    edm::InputTag mSrcPU;

    edm::InputTag triggerBits_;

    //edm::InputTag mPFMET;
    edm::EDGetTokenT<pat::METCollection> mPFMET;

    //edm::InputTag mHBHENoiseFilter;
    //---- TRIGGER -------------------------
    std::string   processName_;
    std::vector<std::string> triggerNames_;
    std::vector<unsigned int> triggerIndex_;
    edm::InputTag triggerResultsTag_;
    edm::InputTag triggerEventTag_;
    edm::Handle<edm::TriggerResults>   triggerResultsHandle_;
    edm::Handle<trigger::TriggerEvent> triggerEventHandle_;
    edm::InputTag cenJetLabel_;
    edm::InputTag forwJetLabel_;

    HLTConfigProvider hltConfig_;
    //---- CORRECTORS ----------------------
    const JetCorrector *mPFJEC;
    const JetCorrector *mCALOJEC;
    JetCorrectionUncertainty *mCALOUnc;
    // ---- non CHS jet uncertainty ------ //
    JetCorrectionUncertainty *mPFUnc;
    // ---- non CHS jet uncertainty ------ //
    JetCorrectionUncertainty *mPFUncCHS;
    //------- non CHS jet uncertainty sources -------- //
    std::vector<JetCorrectionUncertainty*> mPFUncSrc;
    // -------- CHS jet uncertainty sources -------- //
    std::vector<JetCorrectionUncertainty*> mPFUncSrcCHS;

    edm::Service<TFileService> fs;
    TTree *mTree;
    TH1F *mTriggerPassHisto,*mTriggerNamesHisto;
    //---- TREE variables --------
    QCDEvent *mEvent;
};

#endif
