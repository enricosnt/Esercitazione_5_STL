#include <iostream>
#include "TriangularMesh.hpp"
#include "Utils.hpp"
#include "UCDUtilities.hpp"

using namespace std;
using namespace Eigen;
using namespace PolygonalLibrary;

int main()
{
    PolygonalMesh mesh;

    if(!ImportMesh(mesh))
    {
        cerr << "file not found" << endl;
        return 1;
    }
    cout << "Mesh importata con successo!" << endl;
// ***************************************************************************
    if (!ImportCell0Ds(mesh))
    {
        cerr << "Errore nell'importazione delle Cell0Ds" << endl;
        return 1;
 
// ***************************************************************************
    if (!ImportCell1Ds(mesh))
    {
        cerr << "Errore nell'importazione delle Cell1Ds" << endl;
        return 1;
	}
// ***************************************************************************
    if (!ImportCell2Ds(mesh))
    {
        cerr << "Errore nell'importazione delle Cell2Ds" << endl;
        return 1;
    }


    cout << endl;
    cout << "Dettagli delle Cell2Ds:" << endl;
    for (unsigned int i = 0; i < mesh.NumCell2Ds; i++)
    {
        cout << "Cell2D ID: " << mesh.Cell2DsId[i] << endl;
        cout << "Num Vertices: " << mesh.Cell2DsVertices[i].size() << endl;
        cout << "Vertices: ";
        for (unsigned int v : mesh.Cell2DsVertices[i])
        {
            cout << v << " ";
        }
        cout << endl;
        cout << "Num Edges: " << mesh.Cell2DsEdges[i].size() << endl;
        cout << "Edges: ";
        for (unsigned int e : mesh.Cell2DsEdges[i])
        {
            cout << e << " ";
        }
        cout << endl;
    }
	
    return 0;
}
