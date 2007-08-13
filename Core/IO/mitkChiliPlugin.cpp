/*=========================================================================

Program:   Medical Imaging & Interaction Toolkit
Module:    $RCSfile$
Language:  C++
Date:      $Date$
Version:   $Revision$

Copyright (c) German Cancer Research Center, Division of Medical and
Biological Informatics. All rights reserved.
See MITKCopyright.txt or http://www.mitk.org/copyright.html for details.

This software is distributed WITHOUT ANY WARRANTY; without even
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.  See the above copyright notices for more information.

=========================================================================*/

#include "mitkChiliPlugin.h"

/** return a singleton from the current ChiliPlugin */
mitk::ChiliPlugin* mitk::ChiliPlugin::GetInstance(bool destroyInstance)
{
  static mitk::ChiliPlugin::Pointer s_Instance = mitk::ChiliPlugin::New();

  if (destroyInstance)  // needed because of double inheritance of mitk::ChiliPluginImpl
    s_Instance = NULL;

  return s_Instance;
}

/** DefaultImplementation */

mitk::ChiliPlugin::ChiliPlugin()
{
}

mitk::ChiliPlugin::~ChiliPlugin()
{
}

int mitk::ChiliPlugin::GetConferenceID()
{
  return 0;
}

bool mitk::ChiliPlugin::IsPlugin()
{
  return false;
}

mitk::ChiliPlugin::StudyInformation mitk::ChiliPlugin::GetStudyInformation( const std::string& seriesOID )
{
  StudyInformation emptyResult;
  return emptyResult;
}

mitk::ChiliPlugin::PatientInformation mitk::ChiliPlugin::GetPatientInformation( const std::string& seriesOID )
{
  PatientInformation emptyResult;
  return emptyResult;
}

mitk::ChiliPlugin::SeriesInformation mitk::ChiliPlugin::GetSeriesInformation( const std::string& seriesOID )
{
  SeriesInformation emptyResult;
  return emptyResult;
}

mitk::ChiliPlugin::SeriesInformationList mitk::ChiliPlugin::GetSeriesInformationList( const std::string& studyOID )
{
  SeriesInformationList emptyResult;
  emptyResult.clear();
  return emptyResult;
}

mitk::ChiliPlugin::TextInformation mitk::ChiliPlugin::GetTextInformation( const std::string& textOID )
{
  TextInformation emptyResult;
  return emptyResult;
}

mitk::ChiliPlugin::TextInformationList mitk::ChiliPlugin::GetTextInformationList( const std::string& seriesOID )
{
  TextInformationList emptyResult;
  emptyResult.clear();
  return emptyResult;
}

unsigned int mitk::ChiliPlugin::GetLightboxCount()
{
  return 0;
}

QcLightbox* mitk::ChiliPlugin::GetNewLightbox()
{
  return NULL;
}

QcLightbox* mitk::ChiliPlugin::GetCurrentLightbox()
{
  return NULL;
}

std::vector<mitk::DataTreeNode::Pointer> mitk::ChiliPlugin::LoadImagesFromLightbox( QcLightbox* inputLightbox )
{
  std::vector<DataTreeNode::Pointer> emptyVector;
  emptyVector.clear();
  return emptyVector;
}

void mitk::ChiliPlugin::SaveImageToLightbox( Image* sourceImage, const mitk::PropertyList::Pointer propertyList, QcLightbox* lightbox )
{
}

std::vector<mitk::DataTreeNode::Pointer> mitk::ChiliPlugin::LoadCompleteSeries( const std::string& seriesOID )
{
  std::vector<DataTreeNode::Pointer> emptyVector;
  emptyVector.clear();
  return emptyVector;
}

std::vector<mitk::DataTreeNode::Pointer> mitk::ChiliPlugin::LoadAllImagesFromSeries( const std::string& seriesOID )
{
  std::vector<DataTreeNode::Pointer> emptyVector;
  emptyVector.clear();
  return emptyVector;
}

std::vector<mitk::DataTreeNode::Pointer> mitk::ChiliPlugin::LoadAllTextsFromSeries( const std::string& seriesOID )
{
  std::vector<DataTreeNode::Pointer> emptyVector;
  emptyVector.clear();
  return emptyVector;
}

mitk::DataTreeNode::Pointer mitk::ChiliPlugin::LoadOneTextFromSeries( const std::string& seriesOID, const std::string& textOID )
{
  return NULL;
}

void mitk::ChiliPlugin::SaveToChili( DataStorage::SetOfObjects::ConstPointer inputNodes )
{
}
