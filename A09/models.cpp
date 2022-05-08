// this function creates the geometries to be shown, and output thems
// in global variables M1_vertices and M1_indices to M4_vertices and M4_indices
void makeModels() {
//// M1 : Cube
// Replace the code below, that creates a simple square, with the one to create a cube.

// Resizes the vertices array. Repalce the values with the correct number of
// vertices components (3 * number of vertices)
M1_vertices.resize(3 * 8);

// first vertex of M1
M1_vertices[0] = -1.0;
M1_vertices[1] = -1.0;
M1_vertices[2] = -1.0;

// second vertex of M1
M1_vertices[3] =  1.0;
M1_vertices[4] = -1.0;
M1_vertices[5] = -1.0;

// third vertex of M1
M1_vertices[6] =  1.0;
M1_vertices[7] =  1.0;
M1_vertices[8] = -1.0;

// fourth vertex of M1
M1_vertices[9] = -1.0;
M1_vertices[10] =  1.0;
M1_vertices[11] = -1.0;

// fifth vertex of M1
M1_vertices[12] = -1.0;
M1_vertices[13] = -1.0;
M1_vertices[14] = -3.0;

// sixth vertex of M1
M1_vertices[15] =  1.0;
M1_vertices[16] = -1.0;
M1_vertices[17] = -3.0;

// seventh vertex of M1
M1_vertices[18] =  1.0;
M1_vertices[19] =  1.0;
M1_vertices[20] = -3.0;

// eigth vertex of M1
M1_vertices[21] = -1.0;
M1_vertices[22] =  1.0;
M1_vertices[23] = -3.0;


// Resizes the indices array. Repalce the values with the correct number of
// indices (3 * number of triangles)
M1_indices.resize(3 * 12);

// first triangle
M1_indices[0] = 0;
M1_indices[1] = 1;
M1_indices[2] = 2;

// second triangle
M1_indices[3] = 2;
M1_indices[4] = 3;
M1_indices[5] = 0;

// third triangle
M1_indices[6] = 0;
M1_indices[7] = 1;
M1_indices[8] = 4;

// fourth triangle
M1_indices[9] = 1;
M1_indices[10] = 4;
M1_indices[11] = 5;

// fifth triangle
M1_indices[12] = 0;
M1_indices[13] = 4;
M1_indices[14] = 7;

// sixth triangle
M1_indices[15] = 0;
M1_indices[16] = 3;
M1_indices[17] = 7;

// seventh triangle
M1_indices[18] = 4;
M1_indices[19] = 5;
M1_indices[20] = 7;

// eigth triangle
M1_indices[21] = 5;
M1_indices[22] = 6;
M1_indices[23] = 7;

// ninth triangle
M1_indices[24] = 1;
M1_indices[25] = 5;
M1_indices[26] = 6;

// tenth triangle
M1_indices[27] = 1;
M1_indices[28] = 6;
M1_indices[29] = 2;

// eleventh triangle
M1_indices[30] = 2;
M1_indices[31] = 3;
M1_indices[32] = 7;

// twelfth triangle
M1_indices[33] = 2;
M1_indices[34] = 6;
M1_indices[35] = 7;








//// M2 : Cylinder
// Replace the code below, that creates a simple rotated square, with the one to create a cylinder.

// Resizes the vertices array. Repalce the values with the correct number of
// vertices components (3 * number of vertices)

int slices = 4;
M2_vertices.resize(3*(slices+1)*2);

M2_vertices[0]  =  0.0;
M2_vertices[1]  =  0.0;
M2_vertices[2]  =  0.0;

float radious = 2;
float alpha = glm::radians(360.0f/slices);;

for(int i = 3, j = 0; i<3*(slices+1); i=i+3, j++){
    M2_vertices[i] = ((M2_vertices[0]+radious)*cos(alpha*j));
    M2_vertices[i+1] = (M2_vertices[2]);
    M2_vertices[i+2] = ((M2_vertices[1]+radious)*sin(alpha*j));
}


M2_vertices[3*(slices+1)]  =  0.0;
M2_vertices[3*(slices+1)+1]  =  0.0;
M2_vertices[3*(slices+1)+2]  =  5.0;


for(int i = 3*(slices+1)+3, j = 0; i<3*(slices+1)*2; i=i+3, j++){
    M2_vertices[i] = ((M2_vertices[0]+radious)*cos(alpha*j));
    M2_vertices[i+1] = (M2_vertices[3*(slices+1)+2]);
    M2_vertices[i+2] = ((M2_vertices[1]+radious)*sin(alpha*j));
    std::cout <<  M2_vertices[i] << "\t" << M2_vertices[i+1] << "\t" << M2_vertices[i+2] << "\n";
}

std::cout << "\n\n\n";
// Resizes the indices array. Repalce the values with the correct number of
// indices (3 * number of triangles)
M2_indices.resize(3*slices*2);

for(int i = 0, j = 0; i<slices; i=i+1, j=j+3){
    M2_indices[j] = 0;
    M2_indices[j+1] = i+1;
    M2_indices[j+2] = (i+2)<=(slices)?i+2:1;
    std::cout <<  M2_indices[j] << "\t" << M2_indices[j+1] << "\t" << M2_indices[j+2] << "\n";
}


/*
// indices definitions
for(int i = 0; i<4; i=i+3){
    M2_indices[i] = 0;
    M2_indices[i+1] = i+1;
    M2_indices[i+2] = i+2;
}
*/










//// M3 : Sphere
// Replace the code below, that creates a simple triangle, with the one to create a sphere.

// Resizes the vertices array. Repalce the values with the correct number of
// vertices components (3 * number of vertices)
M3_vertices.resize(9);

// Vertices definitions
M3_vertices[0]  =  0.0;
M3_vertices[1]  =  1.0;
M3_vertices[2]  = -1.2;
M3_vertices[3]  = -0.866;
M3_vertices[4]  = -0.5;
M3_vertices[5]  = -1.2;
M3_vertices[6]  =  0.866;
M3_vertices[7]  = -0.5;
M3_vertices[8]  = -1.2;


// Resizes the indices array. Repalce the values with the correct number of
// indices (3 * number of triangles)
M3_indices.resize(3);

// indices definitions
M3_indices[0] = 0;
M3_indices[1] = 1;
M3_indices[2] = 2;









//// M4 : Spring
// Replace the code below, that creates a simple octahedron, with the one to create a spring.
M4_vertices.resize(3 * 6);

// Vertices definitions
M4_vertices[0]  =  0.0;
M4_vertices[1]  =  1.414;
M4_vertices[2]  = -1.0;
M4_vertices[3]  =  0.0;
M4_vertices[4]  = -1.414;
M4_vertices[5]  = -1.0;
M4_vertices[6]  = -1.0;
M4_vertices[7]  =  0.0;
M4_vertices[8]  = -2.0;
M4_vertices[9]  = -1.0;
M4_vertices[10] =  0.0;
M4_vertices[11] =  0.0;
M4_vertices[12] =  1.0;
M4_vertices[13] =  0.0;
M4_vertices[14] =  0.0;
M4_vertices[15] =  1.0;
M4_vertices[16] =  0.0;
M4_vertices[17] = -2.0;


// Resizes the indices array. Repalce the values with the correct number of
// indices (3 * number of triangles)
M4_indices.resize(3 * 8);

// indices definitions
M4_indices[0]  = 0;
M4_indices[1]  = 2;
M4_indices[2]  = 3;
M4_indices[3]  = 1;
M4_indices[4]  = 3;
M4_indices[5]  = 2;
M4_indices[6]  = 0;
M4_indices[7]  = 3;
M4_indices[8]  = 4;
M4_indices[9]  = 1;
M4_indices[10] = 4;
M4_indices[11] = 3;
M4_indices[12] = 0;
M4_indices[13] = 4;
M4_indices[14] = 5;
M4_indices[15] = 1;
M4_indices[16] = 5;
M4_indices[17] = 4;
M4_indices[18] = 0;
M4_indices[19] = 5;
M4_indices[20] = 2;
M4_indices[21] = 1;
M4_indices[22] = 2;
M4_indices[23] = 5;
}