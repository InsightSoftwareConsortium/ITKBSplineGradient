/*=========================================================================
 *
 *  Copyright Insight Software Consortium
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/
#include "itkVectorMagnitudeImageFilter.h"
#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"

#include "itkBSplineGradientImageFilter.h"

int itkBSplineGradientImageFilterTest(int argc, char *argv[])
{
  if ( argc < 3 )
    {
    std::cerr << "Usage: " << argv[0];
    std::cerr << " inputImage outputImage ";
    std::cerr << std::endl;
    return EXIT_FAILURE;
    }

  const unsigned int Dimension = 2;
  typedef float                              PixelType;
  typedef itk::Image< PixelType, Dimension > InputImageType;

  typedef itk::ImageFileReader< InputImageType > ReaderType;
  ReaderType::Pointer reader = ReaderType::New();

  typedef itk::BSplineGradientImageFilter< InputImageType, PixelType > FilterType;
  FilterType::Pointer filter = FilterType::New();
  filter->SetInput( reader->GetOutput() );
  reader->SetFileName( argv[1] );

  typedef FilterType::OutputImageType GradientImageType;
  typedef itk::VectorMagnitudeImageFilter< GradientImageType, InputImageType >
    GradientMagnitudeFilterType;
  GradientMagnitudeFilterType::Pointer gradientMagnitude = GradientMagnitudeFilterType::New();
  gradientMagnitude->SetInput( filter->GetOutput() );

  typedef itk::ImageFileWriter< InputImageType > WriterType;
  WriterType::Pointer writer = WriterType::New();
  writer->SetInput( gradientMagnitude->GetOutput() );
  writer->SetFileName( argv[2] );

  try
    {
    writer->Update();
    }
  catch( itk::ExceptionObject& ex )
    {
    std::cerr << "Exception caught!" << std::endl;
    std::cerr << ex << std::endl;
    return EXIT_FAILURE;
    }

  return EXIT_SUCCESS;
}
