#ifndef __SimFastTiming_FastTimingCommon_BTLDeviceSim_h__
#define __SimFastTiming_FastTimingCommon_BTLDeviceSim_h__

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "SimDataFormats/TrackingHit/interface/PSimHit.h"
#include "SimDataFormats/TrackingHit/interface/PSimHitContainer.h"
#include "SimFastTiming/FastTimingCommon/interface/MTDDigitizerTypes.h"

#include <tuple>

namespace CLHEP {
  class HepRandomEngine;
}

class BTLDeviceSim {

 public:

  BTLDeviceSim(const edm::ParameterSet& pset);
  
  void getEvent(const edm::Event& evt) { }

  void getEventSetup(const edm::EventSetup& evt) { }

  void getHitsResponse(const std::vector<std::tuple<int,uint32_t,float> > &hitRefs, 
		       const edm::Handle<edm::PSimHitContainer> &hits,
		       mtd_digitizer::MTDSimHitDataAccumulator *simHitAccumulator,
		       CLHEP::HepRandomEngine *hre);
  
 private:

  const float refSpeed_;  
  const float bxTime_;
  const float LightYield_;
  const float LightCollEff_;
  const float LightCollTime_;
  const float smearLightCollTime_;
  const float PDE_;

};

#endif
