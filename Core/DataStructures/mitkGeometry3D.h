#ifndef GEOMETRY3D_H_HEADER_INCLUDED_C1EBD0AD
#define GEOMETRY3D_H_HEADER_INCLUDED_C1EBD0AD

#include "mitkCommon.h"
#include "mitkOperationActor.h"
#include "mitkVector.h"
#include <itkImageRegion.h>
#include <itkBoundingBox.h>


class vtkTransform;
class Operation;

namespace mitk {

//##ModelId=3E8600D800C5
//##Documentation
//## @brief Standard 3D-BoundingBox typedef
//##
//## Standard 3D-BoundingBox typedef to get rid of template arguments (3D, type).
typedef itk::BoundingBox<unsigned long, 3, mitk::ScalarType>   BoundingBox;

//##Documentation
//## @brief Standard typedef for time-bounds
typedef itk::FixedArray<mitk::ScalarType,2> TimeBounds;

//##ModelId=3DCBF389032B
//##Documentation
//## @brief Describes the geometry of a data object
//## @ingroup Geometry
//## Describes the geometry of a data object. At least, it can
//## return the bounding box of the data object. An important sub-class is
//## SlicedGeometry3D, which descibes data objects consisting of
//## slices, e.g., objects of type Image.
//## Conversions between world coordinates (in mm) and unit coordinates 
//## (e.g., pixels in the case of an Image) can be performed.
//## 
//## Geometry3D have to be initialized in the method GenerateOutputInformation() 
//## of BaseProcess (or CopyInformation/ UpdateOutputInformation of BaseData, 
//## if possible, e.g., by analyzing pic tags in Image) subclasses. See also
//## itk::ProcessObject::GenerateOutputInformation(),
//## itk::DataObject::CopyInformation() and
//## itk::DataObject::UpdateOutputInformation().
//## 
//## Rule: everything is in mm (ms) if not stated otherwise.
class Geometry3D : public itk::Object, public OperationActor
{
public:
  mitkClassMacro(Geometry3D, itk::Object);

  /** Method for creation through the object factory. */
  itkNewMacro(Self);

  //##ModelId=3DCBF5D40253
  itkGetConstObjectMacro(BoundingBox, BoundingBox);
  itkSetConstObjectMacro(BoundingBox, BoundingBox);

  virtual void SetTimeBoundsInMS(const mitk::TimeBounds& timebounds);

  //##ModelId=3DCBF5E9037F
  virtual const TimeBounds& GetTimeBoundsInMS() const;

  //##ModelId=3DDE65D1028A
  void MMToUnits(const mitk::Point3D &pt_mm, mitk::Point3D &pt_units) const;

  //##ModelId=3DDE65DC0151
  void UnitsToMM(const mitk::Point3D &pt_units, mitk::Point3D &pt_mm) const;

  //##ModelId=3E3B986602CF
  void MMToUnits(const mitk::Vector3D &vec_mm, mitk::Vector3D &vec_units) const;
  //##ModelId=3E3B987503A3
  void UnitsToMM(const mitk::Vector3D &vec_units, mitk::Vector3D &vec_mm) const;

  //##ModelId=3ED91D050305
  virtual void SetBoundingBox(const float bounds[6]);
  
  vtkTransform* GetTransform();

  itkGetConstMacro(TransformUnitsToMM, const mitk::Matrix4D &);
  
  //##ModelId=3E3453C703AF
  virtual void Initialize();

  //##Documentation
  //## @brief set a base geometry for the geometry.
  //## The geometrys transform is linked to the base geometrys transform  
  void SetBaseGeometry(mitk::Geometry3D* base);  
  
  //##Documentation
  //## @brief Transform the geometry with the transformation description
  //## provided as @a transform (type vtkTransform).
  //## @todo not yet implemented
  virtual void SetMasterTransform(const vtkTransform * transform);

  //##Documentation
  //## @brief duplicates the geometry
  virtual Pointer Clone() const;

  //##Documentation
  //##@brief executes affine operations (translate, rotate, scale)
  void ExecuteOperation(Operation* operation); 

  //itkSetVectorMacro(Position, ScalarType, 3);
  //itkSetVectorMacro(Orientation, ScalarType, 3);
  //itkSetVectorMacro(Scale, ScalarType, 3); 

  //itkGetVectorMacro(Position, const ScalarType, 3);
  //itkGetVectorMacro(Orientation, const ScalarType, 3);
  //itkGetVectorMacro(Scale, const ScalarType, 3);

  //virtual void SetPosition(const ScalarType data[]);
  //virtual void SetOrientation(const ScalarType data[]);
  //virtual void SetScale(const ScalarType data[]);

  //virtual const ScalarType* GetPosition() const;
  //virtual const ScalarType* GetOrientation() const;
  //virtual const ScalarType* GetScale() const;

  const ITKVector3D GetXAxis();
  const ITKVector3D GetYAxis();
  const ITKVector3D GetZAxis();
//  void UpdateTransform();
protected:
  Geometry3D();

  //##ModelId=3E3456C50067
  virtual ~Geometry3D();

  //##ModelId=3ED91D050269
  mutable mitk::BoundingBox::ConstPointer m_BoundingBox;

  mutable mitk::TimeBounds m_TimeBoundsInMS;

  //##ModelId=3E3BE8BF02BA
  mitk::Matrix4D m_TransformUnitsToMM;
  //##ModelId=3E3BEC5D0257
  mitk::Matrix4D m_TransformMMToUnits;
  //##ModelId=3E3BE8BF02EC
  mitk::Matrix4D m_TransformOfOrigin;

  vtkTransform* m_Transform;
  
  //ScalarType m_Position[3];
  //ScalarType m_Orientation[3];
  //ScalarType m_Scale[3];  
  //ScalarType m_Angle;
  //ITKPoint3D m_RotationVector;

  //bool m_Modified;


  Geometry3D::Pointer m_BaseGeometry;  
};

} // namespace mitk

#endif /* GEOMETRY3D_H_HEADER_INCLUDED_C1EBD0AD */
