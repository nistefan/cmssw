import FWCore.ParameterSet.Config as cms

##____________________________________________________________________________||
particleFlowForChargedMET = cms.EDProducer(
    "ParticleFlowForChargedMETProducer",
    PFCollectionLabel = cms.InputTag("particleFlow"),
    PVCollectionLabel = cms.InputTag("offlinePrimaryVertices"),
    dzCut = cms.double(0.2),
    neutralEtThreshold = cms.double(-1.0)
    )

##____________________________________________________________________________||
pfChMet = cms.EDProducer(
    "PFMETProducer",
    src = cms.InputTag("particleFlowForChargedMET"),
    alias = cms.string('pfChMet'),
    globalThreshold = cms.double(0.0),
    calculateSignificance = cms.bool(False),
    )

##____________________________________________________________________________||
