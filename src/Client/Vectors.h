#ifndef CC_VECTORS_H
#define CC_VECTORS_H
#include "Typedefs.h"
#include "Matrix.h"
#include "Compiler.h"
/* Represents 2, 3 dimensional vectors.
   Copyright 2017 ClassicalSharp | Licensed under BSD-3
*/

typedef struct Vector2_ { Real32 X, Y; } Vector2;
typedef struct Vector3_ { Real32 X, Y, Z; } Vector3;
typedef struct Vector3I_ { Int32 X, Y, Z; } Vector3I;

Vector2 Vector2_Create2(Real32 x, Real32 y);
Vector3 Vector3_Create1(Real32 value);
Vector3 Vector3_Create3(Real32 x, Real32 y, Real32 z);
Vector3I Vector3I_Create1(Int32 value);
Vector3I Vector3I_Create3(Int32 x, Int32 y, Int32 z);

Real32 Vector3_Length(Vector3* v);
Real32 Vector3_LengthSquared(Vector3* v);

#define VECTOR3_CONST(x, y, z) { x, y, z };
#define VECTOR3I_CONST(x, y, z) { x, y, z };
#define Vector3_UnitX VECTOR3_CONST(1.0f, 0.0f, 0.0f)
#define Vector3_UnitY VECTOR3_CONST(0.0f, 1.0f, 0.0f)
#define Vector3_UnitZ VECTOR3_CONST(0.0f, 0.0f, 1.0f)
#define Vector3_Zero  VECTOR3_CONST(0.0f, 0.0f, 0.0f)
#define Vector3_One   VECTOR3_CONST(1.0f, 1.0f, 1.0f)

void Vector3_Add(Vector3* result, Vector3* a, Vector3* b);
void Vector3I_Add(Vector3I* result, Vector3I* a, Vector3I* b);
void Vector3_Add1(Vector3* result, Vector3* a, Real32 b);
void Vector3_Subtract(Vector3* result, Vector3* a, Vector3* b);
void Vector3I_Subtract(Vector3I* result, Vector3I* a, Vector3I* b);
void Vector3_Multiply1(Vector3* result, Vector3* a, Real32 scale);
void Vector3I_Multiply1(Vector3I* result, Vector3I* a, Int32 scale);
void Vector3_Multiply3(Vector3* result, Vector3* a, Vector3* scale);
void Vector3_Divide1(Vector3* result, Vector3* a, Real32 scale);
void Vector3_Divide3(Vector3* result, Vector3* a, Vector3* scale);
void Vector3_Negate(Vector3* result, Vector3* a);
void Vector3I_Negate(Vector3I* result, Vector3I* a);

void Vector3_Lerp(Vector3* result, Vector3* a, Vector3* b, Real32 blend);
Real32 Vector3_Dot(Vector3* left, Vector3* right);
void Vector3_Cross(Vector3* result, Vector3* a, Vector3* b);
void Vector3_Normalize(Vector3* result, Vector3* a);

/* Transforms a vector by the given matrix. */
void Vector3_Transform(Vector3* result, Vector3* a, Matrix* mat);
/* Transforms a vector consisting of only a X component by the given matrix. */
void Vector3_TransformX(Vector3* result, Real32 x, Matrix* mat);
/* Transforms a vector consisting of only a Y component by the given matrix. */
void Vector3_TransformY(Vector3* result, Real32 y, Matrix* mat);
/* Transforms a vector consisting of only a Z component by the given matrix. */
void Vector3_TransformZ(Vector3* result, Real32 z, Matrix* mat);

/* Rotates the given 3D coordinates around the x axis. */
Vector3 Vector3_RotateX(Vector3 v, Real32 angle);
/* Rotates the given 3D coordinates around the y axis. */
Vector3 Vector3_RotateY(Vector3 v, Real32 angle);
/* Rotates the given 3D coordinates around the y axis. */
Vector3 Vector3_RotateY3(Real32 x, Real32 y, Real32 z, Real32 angle);
/* Rotates the given 3D coordinates around the z axis. */
Vector3 Vector3_RotateZ(Vector3 v, Real32 angle);

bool Vector3_Equals(Vector3* a, Vector3* b);
bool Vector3_NotEquals(Vector3* a, Vector3* b);
bool Vector3I_Equals(Vector3I* a, Vector3I* b);
bool Vector3I_NotEquals(Vector3I* a, Vector3I* b);

/* Returns a vector such that each component is floor of input floating-point component.*/
void Vector3I_Floor(Vector3I* result, Vector3* a);
/* Returns a vector with the integer components converted to floating-point components.*/
void Vector3I_ToVector3(Vector3* result, Vector3I* a);

void Vector3I_Min(Vector3I* result, Vector3I* a, Vector3I* b);
void Vector3I_Max(Vector3I* result, Vector3I* a, Vector3I* b);

/* Returns a normalised vector that faces in the direction described by the given yaw and pitch. */
Vector3 Vector3_GetDirVector(Real32 yawRad, Real32 pitchRad);
/* Returns the yaw and pitch of the given direction vector.
NOTE: This is not an identity function. Returned pitch is always within [-90, 90] degrees.*/
void Vector3_GetHeading(Vector3 dir, Real32* yawRad, Real32* pitchRad);
#endif