/*! 
 *  @authors   Pedro Lima
 *  @authors   Jorge Ordoñez
 *  @date      2018-2019
 */

#ifndef DFNFractureMesh_h
#define DFNFractureMesh_h

#include "pzfmatrix.h"
#include "pzvec.h"
#include "pzmanvector.h"
#include "pzstack.h"

#include <stdio.h>
#include <tuple>
#include "pzmatrix.h"
#include "pzcompel.h"
#include "pzgeoelbc.h"

#include "DFNRibs.h"
#include "DFNFace.h"
#include "DFNVolume.h"
#include "DFNFracPlane.h"


typedef TPZFMatrix<REAL> Matrix;

/*! 
 *  @brief     Compares a geomesh with fracture plane to find intersections.
 *  @details   Intersection search is performed after creation of skeleton
 * elements with DFNFractureMesh::CreateSkeletonElements. Fracture plane should
 *  be a DFNFracPlane.
 *  @authors   Pedro Lima
 *  @authors   Jorge Ordoñez
 *  @date      2018-2019
 */
class DFNFractureMesh
{
private:
    /// Define a default tolerance
    REAL fTolerance = 1.e-4;
    
    /// Map of intersected ribs
    std::map<int64_t, DFNRibs> fRibs;
    
    /// Map of intersected faces
    std::map<int64_t, DFNFace> fMidFaces;
    
    /// Map of end-fracture faces
    std::map<int64_t, DFNFace> fEndFaces;

    /// Map of intersected volumes
    std::map<int64_t, DFNVolume> fVolumes;

    /// Pointer for the geometric mesh
    TPZGeoMesh *fGMesh;

    /// Bounded plane from a fracture
    DFNFracPlane fFracplane;

    // /// Fracplane's geometric element index
    // int64_t fFracplaneindex;

    /// Material id of elements at fracture surface
    int fSurfaceMaterial = 40;

    /// Material id of mesh elements cut by fracture
    int fTransitionMaterial = 18;

public:
    
    /// Empty constructor
    DFNFractureMesh();
    
    /**Define the fracture plane from 3 to 4 points
     * Points should be coplanar
     * The matrix should be dimension 3xN, each column defining the coordinates
     * of a point
     *  
     */
    DFNFractureMesh(DFNFracPlane &FracPlane, TPZGeoMesh *gmesh, int matID);
    
    /// Copy constructor
    DFNFractureMesh(const DFNFractureMesh &copy);
    
    /// Assignment operator
    DFNFractureMesh &operator=(const DFNFractureMesh &copy);
    
    /// Associate the geometric mesh
    void SetgeoMesh(TPZGeoMesh *gmesh){
        fGMesh=gmesh;
    }
    
    /// Access the geomesh
    TPZGeoMesh* GetGeoMesh(){
        return fGMesh;
    }
    
    /// Return the corner nodes of the fracture
    DFNFracPlane GetPlane() const;
    
    /// Modify the default tolerance
    void SetTolerance(REAL tolerance);
    REAL GetTolerance() const;
    
private:
        
    /// Checks neighbour's dimension and returns true if it is equal
    bool HasEqualDimensionNeighbour(TPZGeoElSide &gelside);
    
    /// Finds intersection point of fracture boundaries and geometric mesh faces
    TPZVec<REAL> FindEndFracturePoint(DFNFace &face);
    
    void PrintYoungestChildren(TPZGeoEl *gel, std::ofstream &outfile);
public:
    
    /// Insert intersection elements of lower dimension in the geometric mesh.
    void CreateSkeletonElements(int dimension, int matid);
    
    /// Access the ribs data structure
    void AddRib(DFNRibs rib);
    
    /// Access mid-fracture faces' data structure
    void AddMidFace(DFNFace &face);
    
    /// Access end-fracture faces' data structure
    void AddEndFace(DFNFace &face);

    /// Insert new volume in data structure
    void AddVolume(DFNVolume volume);

    /// Pointer to rib of index 'index'
    DFNRibs *Rib(int64_t index){return &fRibs[index];}

    /// Pointer to face of index 'index'
    DFNFace *Face(int64_t index);
    
    /// Pointer to volume of index 'index'
    DFNVolume *Volume(int64_t index){return &fVolumes[index];}
    
    /// Find and split intersected faces
    void SplitFaces(int matID);
    
    /// Find and split intersected ribs
    void SplitRibs(int matID);

    /// Connects fracture-edge intersections (temporary name for lack of better one)
    void SplitFractureEdge();

    /// Triangulates fracture plane
    void SplitFracturePlane();

    /// Write mesh elements to .geo file
    void WriteGMSH(std::ofstream &outfile);

    /// Uses Gmsh to mesh volumes cut by fracture plane
    void CreateVolumes();

    /// Sets material for elements at surface of fracture
    void SetSurfaceMaterial(int matID);

    /// Get material ID for elements at surface of fracture
    int MaterialID(){return fSurfaceMaterial;}

    /// Find the volumetrical element that encloses a 2D element
    bool FindEnclosingVolume(TPZGeoEl *ifracface);
};

#endif /* DFNFractureMesh_h */
