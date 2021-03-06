#ifndef __VERTEX_H__
#define __VERTEX_H__
/*! \file vertex.h
 * \author M. Sainlot
 * \date 2014
 */

#include "ressources.h"
#include "pgm.h"

/**
 * @brief The vertex structure
 * @details Define as well candidates points inside a simplex as vertex of a simplex
 * 
 * @param coords[DIM] : The coordinates of the vertex
 * @param links[NB_LNK][2] : The implicit definition of a doubly link list
 * @param zdist : Vertical distance of the point to the simplex it belongs to. (0 if inserted)
 * 
 */
typedef struct Vertex
{
	double coords[DIM];
	struct Vertex *links[NB_LNK][2];
	double zdist;
} Vertex ;


/*----------------------------------------------------------------------------------*/
//                                  Vertex functions prototypes
/*----------------------------------------------------------------------------------*/
/**
 * @brief Initialize vertex
 * @details Put neighbors to NULL
 * 
 * @param vert The vertex to initialize
 * @param x x coordinate
 * @param y y coordinate
 * @param z z coordinate
 */	
void init_vertex( Vertex *vert, double x, double y, double z ) ;

/**
 * @brief Create a new vertex
 * @details Do a malloc and call init_vertex()
 * 
 * @param x x coordinate
 * @param y y coordinate
 * @param z z coordinate
 * @return The new vertex created
 */
Vertex* create_vertex( double x, double y, double z ) ;

/**
 * @brief Compare vertices by there zdist
 * @details is p1 > p2 ?
 * 
 * @param p1 first vertex
 * @param p2 second vertex
 * 
 * @return 0 if p1 > p2 else 0
 */
int is_superior_vertex( Vertex *p1, Vertex *p2 ) ;

#endif