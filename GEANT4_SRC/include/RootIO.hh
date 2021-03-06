//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
/// \file persistency/P01/include/RootIO.hh
/// \brief Definition of the RootIO class
//
// $Id: RootIO.hh 71791 2013-06-24 14:08:28Z gcosmo $
#ifndef INCLUDE_ROOTIO_HH 
#define INCLUDE_ROOTIO_HH 1

// Include files
#include "TROOT.h"
#include "TFile.h"
#include "TTree.h"
#include "TClonesArray.h"
#include "TSystem.h"
#include "MinerHit.hh"
#include "G4Track.hh"
#include "RootIOMessenger.hh"

class RootIO 
{
public: 
  //RootIO();
  virtual ~RootIO();
  
  static RootIO* GetInstance();
  void Write();
  void Close();
  void AddHits(MinerHitsCollection * zipHits, G4int detID);
  void AddTrack(const G4Track* trk);
  void Setup();
  void SetFileName(G4String name);
  G4String GetFileName();


protected:
  RootIO(); 
  
private:

   RootIOMessenger *fMessenger;
  // stuff for root
   G4String fileName;
   TTree *theTree;
   TFile *theFile;
   TClonesArray* sHits;
   TClonesArray* sTracks;
   int hitC;
   int trackC;
   int event;
   float eInc, maxX, eDet, eScint;
};
#endif // INCLUDE_ROOTIO_HH
