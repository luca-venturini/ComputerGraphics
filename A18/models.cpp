// this function creates the geometries to be shown, and output thems
// in global variables M1_vertices and M1_indices to M4_vertices and M4_indices

struct Vertex {
	glm::vec3 pos;
	glm::vec3 norm;
};

std::vector<Vertex> M1_vertices;
std::vector<Vertex> M2_vertices;
std::vector<Vertex> M3_vertices;
std::vector<Vertex> M4_vertices;

void makeModels() {
//// M1 : Cube
// Replace the code below, that creates a simple square, with the one to create a cube.

// Resizes the vertices array. Repalce the values with the correct number of
// vertices
M1_vertices.resize(4*6);


// front z

M1_vertices[0].pos  = glm::vec3(-1.0,-1.0,-1.0);
M1_vertices[0].norm = glm::vec3(0.0,0.0,1.0);

M1_vertices[1].pos  = glm::vec3(1.0,-1.0,-1.0);
M1_vertices[1].norm = glm::vec3(0.0,0.0,1.0);

M1_vertices[2].pos  = glm::vec3(1.0,1.0,-1.0);
M1_vertices[2].norm = glm::vec3(0.0,0.0,1.0);

M1_vertices[3].pos  = glm::vec3(-1.0,1.0,-1.0);
M1_vertices[3].norm = glm::vec3(0.0,0.0,1.0);


// back z

M1_vertices[4].pos  = glm::vec3(-1.0,-1.0,-3.0);
M1_vertices[4].norm = glm::vec3(0.0,0.0,-1.0);

M1_vertices[5].pos  = glm::vec3(1.0,-1.0,-3.0);
M1_vertices[5].norm = glm::vec3(0.0,0.0,-1.0);

M1_vertices[6].pos  = glm::vec3(1.0,1.0,-3.0);
M1_vertices[6].norm = glm::vec3(0.0,0.0,-1.0);

M1_vertices[7].pos  = glm::vec3(-1.0,1.0,-3.0);
M1_vertices[7].norm = glm::vec3(0.0,0.0,-1.0);


// front x

M1_vertices[8].pos  = glm::vec3(1.0,-1.0,-1.0);
M1_vertices[8].norm = glm::vec3(1.0,0.0,0.0);

M1_vertices[9].pos  = glm::vec3(1.0,-1.0,-3.0);
M1_vertices[9].norm = glm::vec3(1.0,0.0,0.0);

M1_vertices[10].pos  = glm::vec3(1.0,1.0,-3.0);
M1_vertices[10].norm = glm::vec3(1.0,0.0,0.0);

M1_vertices[11].pos  = glm::vec3(1.0,1.0,-1.0);
M1_vertices[11].norm = glm::vec3(1.0,0.0,0.0);


// back x

M1_vertices[12].pos  = glm::vec3(-1.0,-1.0,-1.0);
M1_vertices[12].norm = glm::vec3(-1.0,0.0,0.0);

M1_vertices[13].pos  = glm::vec3(-1.0,-1.0,-3.0);
M1_vertices[13].norm = glm::vec3(-1.0,0.0,0.0);

M1_vertices[14].pos  = glm::vec3(-1.0,1.0,-3.0);
M1_vertices[14].norm = glm::vec3(-1.0,0.0,0.0);

M1_vertices[15].pos  = glm::vec3(-1.0,1.0,-1.0);
M1_vertices[15].norm = glm::vec3(-1.0,0.0,0.0);


// front y

M1_vertices[16].pos  = glm::vec3(-1.0,1.0,-1.0);
M1_vertices[16].norm = glm::vec3(.0,1.0,0.0);

M1_vertices[17].pos  = glm::vec3(1.0,1.0,-1.0);
M1_vertices[17].norm = glm::vec3(.0,1.0,0.0);

M1_vertices[18].pos  = glm::vec3(1.0,1.0,-3.0);
M1_vertices[18].norm = glm::vec3(.0,1.0,0.0);

M1_vertices[19].pos  = glm::vec3(-1.0,1.0,-3.0);
M1_vertices[19].norm = glm::vec3(.0,1.0,0.0);



// back y

M1_vertices[20].pos  = glm::vec3(-1.0,-1.0,-1.0);
M1_vertices[20].norm = glm::vec3(.0,-1.0,0.0);

M1_vertices[21].pos  = glm::vec3(1.0,-1.0,-1.0);
M1_vertices[21].norm = glm::vec3(.0,-1.0,0.0);

M1_vertices[22].pos  = glm::vec3(1.0,-1.0,-3.0);
M1_vertices[22].norm = glm::vec3(.0,-1.0,0.0);

M1_vertices[23].pos  = glm::vec3(-1.0,-1.0,-3.0);
M1_vertices[23].norm = glm::vec3(.0,-1.0,0.0);



// Resizes the indices array. Repalce the values with the correct number of
// indices (3 * number of triangles)
M1_indices.resize(6 * 6);


// front z

M1_indices[0] = 0;
M1_indices[1] = 1;
M1_indices[2] = 2;

M1_indices[3] = 2;
M1_indices[4] = 3;
M1_indices[5] = 0;

// back z

M1_indices[6] = 4;
M1_indices[7] = 5;
M1_indices[8] = 6;

M1_indices[9] = 6;
M1_indices[10] = 7;
M1_indices[11] = 4;

// front x

M1_indices[12] = 8;
M1_indices[13] = 9;
M1_indices[14] = 10;

M1_indices[15] = 10;
M1_indices[16] = 11;
M1_indices[17] = 8;

// back x

M1_indices[18] = 12;
M1_indices[19] = 13;
M1_indices[20] = 14;

M1_indices[21] = 14;
M1_indices[22] = 15;
M1_indices[23] = 12;


// front y

M1_indices[24] = 16;
M1_indices[25] = 17;
M1_indices[26] = 18;

M1_indices[27] = 18;
M1_indices[28] = 19;
M1_indices[29] = 16;


// back y

M1_indices[30] = 20;
M1_indices[31] = 21;
M1_indices[32] = 22;

M1_indices[33] = 22;
M1_indices[34] = 23;
M1_indices[35] = 20;








//// M2 : Cylinder
// Replace the code below, that creates a simple rotated square, with the one to create a cylinder.

// Resizes the vertices array. Repalce the values with the correct number of
// // vertices
// M2_vertices.resize(4);

// // Vertices definitions
// M2_vertices[0].pos  = glm::vec3(0.0,-1.0,-1.1);
// M2_vertices[0].norm = glm::vec3(0.0,0.0,1.0);

// M2_vertices[1].pos  = glm::vec3(1.0,0.0,-1.1);
// M2_vertices[1].norm = glm::vec3(0.0,0.0,1.0);

// M2_vertices[2].pos  = glm::vec3(0.0,1.0,-1.1);
// M2_vertices[2].norm = glm::vec3(0.0,0.0,1.0);

// M2_vertices[3].pos  = glm::vec3(-1.0,0.0,-1.1);
// M2_vertices[3].norm = glm::vec3(0.0,0.0,1.0);


// // Resizes the indices array. Repalce the values with the correct number of
// // indices (3 * number of triangles)
// M2_indices.resize(6);

// // indices definitions
// M2_indices[0] = 0;
// M2_indices[1] = 1;
// M2_indices[2] = 2;
// M2_indices[3] = 2;
// M2_indices[4] = 3;
// M2_indices[5] = 0;



int Nslices = 72;
float radious = 1;
float height = 1;
float cx = 0, cy = 0, cz = 0;
float PI = 3.1415;

M2_vertices.resize((Nslices*4)+2);

M2_vertices[0].pos = glm::vec3(cx, cy + height, cz);
M2_vertices[0].norm = glm::vec3(0.0, 1.0, 0.0);

for (int i = 0; i<Nslices; i++){
    M2_vertices[(i+1)].pos = glm::vec3(cx + radious * cos((float)i/Nslices * 2.0 * PI), cy + height, cz + radious * sin((float)i/Nslices * 2.0 * PI));
	M2_vertices[(i+1)].norm = glm::vec3(0.0, 1.0, 0.0);

	M2_vertices[Nslices + (i+1)].pos = glm::vec3(cx + radious * cos((float)i/Nslices * 2.0 * PI), cy + height, cz + radious * sin((float)i/Nslices * 2.0 * PI));
	M2_vertices[Nslices + (i+1)].norm = glm::vec3(cos((float)i/Nslices * 2.0 * PI), 0.0, sin((float)i/Nslices * 2.0 * PI));
}


M2_vertices[2*Nslices+1].pos = glm::vec3(cx, cy - height, cz);
M2_vertices[2*Nslices+1].norm = glm::vec3(0.0, -1.0, 0.0);

for (int i = 0; i<Nslices; i++){
    M2_vertices[2*Nslices+1 + (i+1)].pos = glm::vec3(cx + radious * cos((float)i/Nslices * 2.0 * PI), cy - height, cz + radious * sin((float)i/Nslices * 2.0 * PI));
	M2_vertices[2*Nslices+1 + (i+1)].norm = glm::vec3(0.0, -1.0, 0.0);

	M2_vertices[3*Nslices+1 + (i+1)].pos = glm::vec3(cx + radious * cos((float)i/Nslices * 2.0 * PI), cy - height, cz + radious * sin((float)i/Nslices * 2.0 * PI));
	M2_vertices[3*Nslices+1 + (i+1)].norm = glm::vec3(cos((float)i/Nslices * 2.0 * PI), 0.0, sin((float)i/Nslices * 2.0 * PI));
}



// Resizes the indices array. Repalce the values with the correct number of
// indices (3 * number of triangles)
M2_indices.resize((3 * Nslices)*2 + Nslices*3*2);

//upper circle
for(int i = 0; i<Nslices; i++){
    M2_indices[i*3 + 0] = 0;
    M2_indices[i*3 + 1] = i+1;
    M2_indices[i*3 + 2] = (i+1)%Nslices+1;
}

//lower circle
for(int i = 0; i<Nslices; i++){
    M2_indices[3 * Nslices + i*3 + 0] = (2*Nslices+1) + 0;
    M2_indices[3 * Nslices + i*3 + 1] = (2*Nslices+1) + i+1;
    M2_indices[3 * Nslices + i*3 + 2] = (2*Nslices+1) + (i+1)%Nslices+1;
}

//side 1
for(int i = 0; i<Nslices; i++){
    M2_indices[2 * 3 * Nslices + i*3 + 0] = Nslices + i + 1;
    M2_indices[2 * 3 * Nslices + i*3 + 1] = Nslices + (i+1)%Nslices + 1;
    M2_indices[2 * 3 * Nslices + i*3 + 2] = 3*Nslices + i + 1 + 1;
}

//side 2
for(int i = 0; i<Nslices; i++){
    M2_indices[3 * 3 * Nslices + i*3 + 0] = 3*(Nslices) + i + 1 + 1;
    M2_indices[3 * 3 * Nslices + i*3 + 1] = 3*(Nslices) + (i+1)%Nslices + 1 + 1;
    M2_indices[3 * 3 * Nslices + i*3 + 2] = Nslices + (i+1)%Nslices + 1;
}













//// M3 : Sphere

int circle_slices = 72;
int sphere_leyers = 500;
float sphere_radious = 0.5;
height = 1;
cx = 0, cy = -0.5, cz = 0;
PI = 3.1415;

int index = 0;
M3_vertices.resize(((circle_slices+1)*3)*(sphere_leyers+1));
//  std::cout << "LEN 1: " << ((circle_slices+1)*3)*(sphere_leyers+1) << "\n"; 


M3_vertices[index].pos = glm::vec3(cx, cy, cz);
M3_vertices[index++].norm = glm::vec3(.0, -1., .0);


for(int l = 1; l < sphere_leyers; l++){
	for (int i = 0; i<circle_slices; i++){
		radious = sqrt(pow(sphere_radious, 2) - pow(cy + l*height/sphere_leyers, 2));
		M3_vertices[index].pos = glm::vec3(cx + radious * cos((float)i/circle_slices * 2.0 * PI), cy + l*height/sphere_leyers, cz + radious * sin((float)i/circle_slices * 2.0 * PI));
		M3_vertices[index++].norm = glm::normalize(glm::vec3(radious*cos((float)i/circle_slices * 2.0 * PI), radious*sin(-PI/2 + PI * l*height/sphere_leyers) , radious*sin((float)i/circle_slices * 2.0 * PI)) );
	}
}


M3_vertices[index].pos = glm::vec3(cx, cy + height*1.0, cz);
M3_vertices[index++].norm = glm::vec3(.0, 1., .0);



//  std::cout << "YYYYYYYYYYYYYYYYYYYLEN: " << 3 * circle_slices * (sphere_leyers+1) + 2 * 3 * circle_slices * sphere_leyers << "\n"; 

M3_indices.resize(2 * 3 * circle_slices * (sphere_leyers-1) + 2*circle_slices*3);
index = 0;

for(int l = 0; l < sphere_leyers - 2; l++){
    for (int i = 0; i<circle_slices; i++){
        M3_indices[index++] = l*circle_slices + i + 1;
        M3_indices[index++] = l*circle_slices + (i+1)%circle_slices + 1;
        M3_indices[index++] = l*circle_slices + i + 1 + (circle_slices);
        // std::cout << "indices:" << index - 3  << "  " << index - 2 << "  " << index - 1 << "\n";
        // std::cout << "X: " << M3_indices[index - 3] << " - Y: " << M3_indices[index - 2] << " - Z:" << M3_indices[index - 1] << "\n";
    }
    // std::cout << "\n";
}

for(int l = 1; l < sphere_leyers - 1; l++){
    for (int i = 0; i<circle_slices; i++){
        M3_indices[index++] = l*circle_slices + i + 1;
        M3_indices[index++] = l*circle_slices + (i+1)%circle_slices + 1;
        M3_indices[index++] = (l-1)*circle_slices + (i+1)%circle_slices + 1;
        // std::cout << "indices:" << index - 3  << "  " << index - 2 << "  " << index - 1 << "\n";
        // std::cout << "X: " << M3_indices[index - 3] << " - Y: " << M3_indices[index - 2] << " - Z:" << M3_indices[index - 1] << "\n";
    }
    // std::cout << "\n";
}


for(int i = 0; i<circle_slices; i++){
    M3_indices[index++] = 0;
    M3_indices[index++] = i+1;
    M3_indices[index++] = (i+1)%circle_slices+1;
}

for(int i = 0; i<circle_slices; i++){
    M3_indices[index++] = (sphere_leyers-1)*circle_slices+1;
    M3_indices[index++] = (sphere_leyers-2)*circle_slices+1+i;
    M3_indices[index++] = (sphere_leyers-2)*circle_slices+(1+i)%circle_slices+1;
}





//// M4 : Spring
// Replace the code below, that creates a simple octahedron, with the one to create a spring.
M4_vertices.resize(6);

// Vertices definitions
M4_vertices[0].pos  = glm::vec3(0.0,1.414,-1.0);
M4_vertices[0].norm = glm::vec3(0.0,0.0,1.0);
M4_vertices[1].pos  = glm::vec3(0.0,-1.414,-1.0);
M4_vertices[1].norm = glm::vec3(0.0,0.0,1.0);
M4_vertices[2].pos  = glm::vec3(-1.0,0.0,-2.0);
M4_vertices[2].norm = glm::vec3(0.0,0.0,1.0);
M4_vertices[3].pos  = glm::vec3(-1.0,0.0,0.0);
M4_vertices[3].norm = glm::vec3(0.0,-1.0,0.0);
M4_vertices[4].pos  = glm::vec3(1.0,0.0,0.0);
M4_vertices[4].norm = glm::vec3(0.0,-1.0,0.0);
M4_vertices[5].pos  = glm::vec3(1.0,0.0,-2.0);
M4_vertices[5].norm = glm::vec3(0.0,-1.0,0.0);


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