itk_module_test()

set(BSplineGradientTests
  itkImageToImageOfVectorsFilterTest.cxx
  itkBSplineScatteredDataPointSetToGradientImageFilterTest.cxx
  itkBSplineApproximationGradientImageFilterTest.cxx
  itkBSplineGradientImageFilterTest.cxx
  )

CreateTestDriver(BSplineGradient "${BSplineGradient-Test_LIBRARIES}" "${BSplineGradientTests}")

itk_add_test(NAME itkImageToImageOfVectorsFilterTest
  COMMAND BSplineGradientTestDriver
  itkImageToImageOfVectorsFilterTest
    DATA{Input/foot.mha}
    ${ITK_TEST_OUTPUT_DIR}/itkImageToImageOfVectorsFilterTestOutput.mha
  )

itk_add_test(NAME itkBSplineScatteredDataPointSetToGradientImageFilterTest
  COMMAND BSplineGradientTestDriver
  itkBSplineScatteredDataPointSetToGradientImageFilterTest
    DATA{Input/foot.mha}
    ${ITK_TEST_OUTPUT_DIR}/itkBSplineScatteredDataPointSetToGradientImageFilterTestGradientMagnitudeOutput.mha
  )

itk_add_test(NAME itkBSplineApproximationGradientImageFilterTest
  COMMAND BSplineGradientTestDriver
  itkBSplineApproximationGradientImageFilterTest
    DATA{Input/foot.mha}
    ${ITK_TEST_OUTPUT_DIR}/itkBSplineApproximationGradientImageFilterTest
  )

itk_add_test(NAME itkBSplineGradientImageFilterTest
  COMMAND BSplineGradientTestDriver
  itkBSplineGradientImageFilterTest
    DATA{Input/foot.mha}
    ${ITK_TEST_OUTPUT_DIR}/itkBSplineGradientImageFilterTestGradientMagnitude.mha
  )
