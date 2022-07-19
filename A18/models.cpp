// this function creates the geometries to be shown, and output thems
// in global variables M1_vertices and M1_indices to M4_vertices and M4_indices
#include <glm/gtx/rotate_vector.hpp>

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



//Cylinder

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

int slicesPerCircle = 90;
int numberOfCricles = 90;
float sphere_radious = 0.5;
height = 1;
cx = 0, cy = -0.5, cz = 0;
PI = 3.1415;

int index = 0;
M3_vertices.resize(slicesPerCircle*numberOfCricles*6);
//  std::cout << "LEN 1: " << ((circle_slices+1)*3)*(sphere_leyers+1) << "\n"; 


for (int i = 0; i<numberOfCricles; i++){
    std::cout << "new cycle\n";
    for(int j = 0; j< slicesPerCircle; j++){
        glm::vec3 pos = glm::vec3(0, sphere_radious*cos(PI/(slicesPerCircle-1)*j), sphere_radious*sin(PI/(slicesPerCircle-1)*j));
        glm::vec3 norm = glm::vec3(0, cos(PI/(slicesPerCircle-1)*j), sin(PI/(slicesPerCircle-1)*j));
        
        M3_vertices[index].pos = glm::rotate(glm::mat4(1.0f), 2*PI/(numberOfCricles)*i, glm::vec3(0.0f, 1.0f, 0.0f))*glm::vec4(pos, 1);
        std::cout << "X: " << M3_vertices[index].pos[0] << " - Y: " << M3_vertices[index].pos[1] << " - Z:" << M3_vertices[index].pos[2] << "\n";
        M3_vertices[index++].norm = glm::rotate(glm::mat4(1.0f), 2*PI/(numberOfCricles)*i, glm::vec3(0.0f, 1.0f, 0.0f))*glm::vec4(norm, 1);

    }
    
}


M3_indices.resize((numberOfCricles-1)*(slicesPerCircle-1)*2*3+2*(slicesPerCircle-1)*3);
index = 0;

for(int l = 0; l < numberOfCricles-1; l++){
    for (int i = 0; i<slicesPerCircle-1; i++){
        M3_indices[index++] = slicesPerCircle*l + i;
        M3_indices[index++] = slicesPerCircle*l + (i)%slicesPerCircle+1;
        M3_indices[index++] = slicesPerCircle*(l+1) + i;
        // std::cout << "indices:" << index - 3  << "  " << index - 2 << "  " << index - 1 << "\n";
        std::cout << "X: " << M3_indices[index - 3] << " - Y: " << M3_indices[index - 2] << " - Z:" << M3_indices[index - 1] << "\n";
    }
    // std::cout << "\n";
}

for(int l = 0; l < numberOfCricles-1; l++){
    for (int i = 0; i<slicesPerCircle-1; i++){
        M3_indices[index++] = slicesPerCircle*(l+1) + i;
        M3_indices[index++] = slicesPerCircle*(l+1) + (i)%slicesPerCircle+1;
        M3_indices[index++] = slicesPerCircle*l  + (i)%slicesPerCircle+1;
        // std::cout << "indices:" << index - 3  << "  " << index - 2 << "  " << index - 1 << "\n";
        std::cout << "X: " << M3_indices[index - 3] << " - Y: " << M3_indices[index - 2] << " - Z:" << M3_indices[index - 1] << "\n";
    }
    // std::cout << "\n";
}


for (int i = 0; i<slicesPerCircle-1; i++){
    M3_indices[index++] = slicesPerCircle*(numberOfCricles-1) + i;
    M3_indices[index++] = slicesPerCircle*(numberOfCricles-1) + (i)%slicesPerCircle+1;
    M3_indices[index++] = (i);
    // std::cout << "indices:" << index - 3  << "  " << index - 2 << "  " << index - 1 << "\n";
    std::cout << "X: " << M3_indices[index - 3] << " - Y: " << M3_indices[index - 2] << " - Z:" << M3_indices[index - 1] << "\n";
}

for (int i = 0; i<slicesPerCircle-1; i++){
    M3_indices[index++] = slicesPerCircle*(numberOfCricles-1) + (i)%slicesPerCircle+1;
    M3_indices[index++] = (i)%slicesPerCircle+1;
    M3_indices[index++] = (i);
    // std::cout << "indices:" << index - 3  << "  " << index - 2 << "  " << index - 1 << "\n";
    std::cout << "X: " << M3_indices[index - 3] << " - Y: " << M3_indices[index - 2] << " - Z:" << M3_indices[index - 1] << "\n";
}






//// M4 : Spring
int M4Circles = 216;
int M4SlicesPerCircle = 72;
float radious_ext = 2.0;
radious = .5;
float step = 5.0 / M4Circles;

M4_vertices.resize(3 * (M4SlicesPerCircle + 1) * M4Circles);
index = 0;
float xc, yc, zc;
float alpha = atan(step/(4*PI*radious_ext/M4Circles));

for (int i = 0; i<M4Circles; i++){
    xc = radious_ext * cos(4 * PI * i / M4Circles);
    yc = 1 - step*i;
    zc = radious_ext * sin(4 * PI *i / M4Circles);
    for (int j = 0; j<M4SlicesPerCircle; j++){
        M4_vertices[index].pos = glm::rotate(
                                    glm::vec3(
                                    radious * cos(2 * PI * j / M4SlicesPerCircle) * cos(4 * PI *i / M4Circles), radious * sin(2 * PI * j / M4SlicesPerCircle),  radious * cos(2 * PI * j / M4SlicesPerCircle) * sin(4 * PI *i / M4Circles)
                                    ),
                                    alpha,
                                    glm::vec3(cos(4 * PI * i / M4Circles), 0, sin(4 * PI * i / M4Circles))
                                )+glm::vec3(xc, yc, zc);

        M4_vertices[index++].norm = glm::rotate(glm::vec3( 
            cos(2 * PI * j / M4SlicesPerCircle) * cos(4 * PI *i / M4Circles),
            sin(2 * PI * j / M4SlicesPerCircle),
            cos(2 * PI * j / M4SlicesPerCircle) * sin(4 * PI *i / M4Circles)),
            alpha,
            glm::vec3(cos(4 * PI * i / M4Circles), 0, sin(4 * PI * i / M4Circles))
        );
    }
}


int i = 0;

xc = radious_ext * cos(4 * PI * i / M4Circles);
yc = 1 - step*i;
zc = radious_ext * sin(4 * PI *i / M4Circles);

M4_vertices[index].pos = glm::vec3(xc, yc, zc);
M4_vertices[index++].norm = glm::rotateX(glm::vec3(0.0, 0.0, -1.0), alpha );

for (int j = 0; j<M4SlicesPerCircle; j++){
    M4_vertices[index].pos = glm::rotate(
            glm::vec3(
                radious * cos(2 * PI * j / M4SlicesPerCircle) * cos(4 * PI *i / M4Circles), radious * sin(2 * PI * j / M4SlicesPerCircle),  radious * cos(2 * PI * j / M4SlicesPerCircle) * sin(4 * PI *i / M4Circles)
            ),
            alpha,
            glm::vec3(cos(4 * PI * i / M4Circles), 0, sin(4 * PI * i / M4Circles))
        )+glm::vec3(xc, yc, zc);
    M4_vertices[index++].norm = glm::rotateX(glm::vec3(0.0, 0.0, -1.0), alpha );
}

i = M4Circles-1;

xc = radious_ext * cos(4 * PI * i / M4Circles);
yc = 1 - step*i;
zc = radious_ext * sin(4 * PI *i / M4Circles);

M4_vertices[index].pos = glm::vec3(xc, yc, zc);
M4_vertices[index++].norm = glm::rotateX(glm::vec3(0.0, 0.0, 1.0), alpha );

for (int j = 0; j<M4SlicesPerCircle; j++){
    M4_vertices[index].pos = glm::rotate(
            glm::vec3(
                radious * cos(2 * PI * j / M4SlicesPerCircle) * cos(4 * PI *i / M4Circles), radious * sin(2 * PI * j / M4SlicesPerCircle),  radious * cos(2 * PI * j / M4SlicesPerCircle) * sin(4 * PI *i / M4Circles)
            ),
            alpha,
            glm::vec3(cos(4 * PI * i / M4Circles), 0, sin(4 * PI * i / M4Circles))
        )+glm::vec3(xc, yc, zc);
    M4_vertices[index++].norm = glm::rotateX(glm::vec3(0.0, 0.0, 1.0), alpha );
}



// // Resizes the indices array. Repalce the values with the correct number of
// indices (3 * number of triangles)
M4_indices.resize(2 * 3 * (M4Circles-1) * M4SlicesPerCircle + 6 * 3 * M4SlicesPerCircle);


index = 0;

for (int i = 0; i < M4Circles - 1; i++){
    for (int j = 0; j < M4SlicesPerCircle; j++){
        M4_indices[index++] = (M4SlicesPerCircle)*i + j;
        M4_indices[index++] = (M4SlicesPerCircle)*i + (j + 1)%M4SlicesPerCircle;
        M4_indices[index++] = (M4SlicesPerCircle)*(i+1) + j;
    }
}

for (int i = 1; i < M4Circles; i++){
    for (int j = 0; j < M4SlicesPerCircle; j++){
        M4_indices[index++] = (M4SlicesPerCircle)*i + j;
        M4_indices[index++] = (M4SlicesPerCircle)*i + (j + 1)%M4SlicesPerCircle;
        M4_indices[index++] = (M4SlicesPerCircle)*(i-1) + (j+1)%M4SlicesPerCircle;
    }
}

for (int i = 0; i < M4SlicesPerCircle; i++){
    M4_indices[index++] = M4Circles*M4SlicesPerCircle;
    M4_indices[index++] = M4Circles*M4SlicesPerCircle + i+1;
    M4_indices[index++] = M4Circles*M4SlicesPerCircle + (i+1)%M4SlicesPerCircle+1;//; (M4SlicesPerCircle+1)*(i+1) + j + 1;
}


for (int i = 0; i < M4SlicesPerCircle; i++){
    M4_indices[index++] = (M4SlicesPerCircle+1) + M4Circles*M4SlicesPerCircle;
    M4_indices[index++] = (M4SlicesPerCircle+1) + M4Circles*M4SlicesPerCircle + i+1;
    M4_indices[index++] = (M4SlicesPerCircle+1) + M4Circles*M4SlicesPerCircle + (i+1)%M4SlicesPerCircle+1;//; (M4SlicesPerCircle+1)*(i+1) + j + 1;
}

}