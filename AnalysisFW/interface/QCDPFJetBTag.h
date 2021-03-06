//Author K. Kousouris
//Modified by: S. Ganguly

#ifndef QCDPFJetBTag_h
#define QCDPFJetBTag_h
#include "SMPJ/AnalysisFW/interface/QCDJet.h"
#include "TLorentzVector.h"
class QCDPFJetBTag : public QCDJet {
   public:
     //------------ Constructor ------------------------------
     QCDPFJetBTag() {}
     //------------ Destructor -------------------------------
     ~QCDPFJetBTag() {}
     //------------ Set methods ------------------------------
     void setTCHETag(float ftche, float ftchp, float ftchepf, float ftchppf)  {TCHE_ = ftche; TCHP_ = ftchp; TCHEpf_ = ftchepf; TCHPpf_ = ftchppf; }
     void setSoftLeptonTag(float fsoftmuonbyip, float fsoftelectronbyip, float fsoftmuon, float fsoftelectron)  {SoftMuonTagByIP_ = fsoftmuonbyip; SoftElectronTagByIP_ = fsoftelectronbyip; SoftMuonTag_ = fsoftmuon; SoftElectronTag_ = fsoftelectron; }
     void setSimpleSecondaryVertexTag(float fsimplesecvertexhe, float fsimplesecvertexhp, float fsimplesecvertexhepf, float fsimplesecvertexhppf)  {SimpleSecVertexHE_ = fsimplesecvertexhe; SimpleSecVertexHP_ = fsimplesecvertexhp; SimpleSecVertexHEpf_ = fsimplesecvertexhepf; SimpleSecVertexHPpf_ = fsimplesecvertexhppf; }
     void setCombinedSecondaryVertexTag(float fcsv, float fcsvpf, float fcinclsvpf, float fcsvsoftleptonpf, float fcmvapf)  {CSV_ = fcsv; CSVpf_ = fcsvpf; CinclSVpf_ = fcinclsvpf; CSVSoftLeptonpf_ = fcsvsoftleptonpf; CMVApf_= fcmvapf;}

     void setPositiveNegativeCSV(float fcsvpfpositive, float fcsvpfnegative) { CSVpfPositive_ = fcsvpfpositive; CSVpfNegative_ = fcsvpfnegative;}

     void setFlavour(float fpartonflavour, float fhadronflavour) {partonFlavour_ = fpartonflavour; hadronFlavour_ = fhadronflavour;}

     //------------ Get methods ------------------------------
     float tche()     const {return TCHE_;}
     float tchp()     const {return TCHP_;}
     float tchepf()      const {return TCHEpf_;}
     float tchppf()      const {return TCHPpf_;}
     float softmuonbyip()      const {return SoftMuonTagByIP_;}
     float softelectronbyip()      const {return SoftElectronTagByIP_;}
     float softmuon()      const {return SoftMuonTag_;}
     float softelectron()      const {return SoftElectronTag_;}
     float simplesecvertexhe()      const {return SimpleSecVertexHE_;}
     float simplesecvertexhp()      const {return SimpleSecVertexHP_;}
     float simplesecvertexhepf()      const {return SimpleSecVertexHEpf_;}
     float simplesecvertexhppf()      const {return SimpleSecVertexHPpf_;}
     float csv()      const {return CSV_;}
     float csvpf()      const {return CSVpf_;}
     float cinclsvpf()      const {return CinclSVpf_;}
     float cmvapf()      const {return CMVApf_;}
     float csvsoftleptonpf()      const {return CSVSoftLeptonpf_;}
     
     float csvpfpositive()      const {return CSVpfPositive_;}
     float csvpfnegative()      const {return CSVpfNegative_;}

     float partonflavour()      const {return partonFlavour_;}
     float hadronflavour()      const {return hadronFlavour_;}

   private:
     float TCHE_;
     float TCHP_;
     float TCHEpf_;
     float TCHPpf_;
     float SoftMuonTagByIP_;
     float SoftElectronTagByIP_;
     float SoftMuonTag_;
     float SoftElectronTag_;
     float SimpleSecVertexHE_;
     float SimpleSecVertexHP_;
     float SimpleSecVertexHEpf_;
     float SimpleSecVertexHPpf_;
     float CSV_;
     float CSVpf_;
     float CinclSVpf_;
     float CMVApf_;
     float CSVSoftLeptonpf_;
     float CSVpfPositive_;
     float CSVpfNegative_;

     float partonFlavour_;
     float hadronFlavour_;

    };
#endif
