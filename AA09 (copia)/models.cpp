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


int Nslices = 20;
float radious = 1;
float height = 1;
float cx = 0, cy = 0, cz = 0;
float PI = 3.1415;

M2_vertices.resize(((Nslices+1)*3)*2);

M2_vertices[0] = cx;
M2_vertices[1] = cy + height;
M2_vertices[2] = cz;


for (int i = 0; i<Nslices; i++){
    M2_vertices[(i+1)*3 + 0] = cx + radious * cos((float)i/Nslices * 2.0 * PI);
    M2_vertices[(i+1)*3 + 1] = cy + height;
    M2_vertices[(i+1)*3 + 2] = cz + radious * sin((float)i/Nslices * 2.0 * PI);
    //std::cout << "X: " << M2_vertices[(i+1)*3 + 0] << " - Y: " << M2_vertices[(i+1)*3 + 1] << " - Z:" << M2_vertices[(i+1)*3 + 2] << "\n";
}

M2_vertices[((Nslices+1)*3)] = cx;
M2_vertices[((Nslices+1)*3) + 1] = cy - height;
M2_vertices[((Nslices+1)*3) + 2] = cz;

// std::cout << "\n\n";

for (int i = 0; i<Nslices; i++){
    M2_vertices[((Nslices+1)*3) + (i+1)*3 + 0] = cx + radious * cos((float)i/Nslices * 2.0 * PI);
    M2_vertices[((Nslices+1)*3) + (i+1)*3 + 1] = cy - height;
    M2_vertices[((Nslices+1)*3) + (i+1)*3 + 2] = cz + radious * sin((float)i/Nslices * 2.0 * PI);
    // std::cout << "X: " << M2_vertices[((Nslices+1)*3) + (i+1)*3 + 0] << " - Y: " << M2_vertices[((Nslices+1)*3) + (i+1)*3 + 1] << " - Z:" << M2_vertices[((Nslices+1)*3) + (i+1)*3 + 2] << "\n";
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
    M2_indices[3 * Nslices + i*3 + 0] = (Nslices+1) + 0;
    M2_indices[3 * Nslices + i*3 + 1] = (Nslices+1) + i+1;
    M2_indices[3 * Nslices + i*3 + 2] = (Nslices+1) + (i+1)%Nslices+1;
}

//side 1
for(int i = 0; i<Nslices; i++){
    M2_indices[2 * 3 * Nslices + i*3 + 0] = i + 1;
    M2_indices[2 * 3 * Nslices + i*3 + 1] = (i+1)%Nslices + 1;
    M2_indices[2 * 3 * Nslices + i*3 + 2] = i + 1 + Nslices + 1;
}

//side 2
for(int i = 0; i<Nslices; i++){
    M2_indices[3 * 3 * Nslices + i*3 + 0] = (Nslices+1) + i + 1;
    M2_indices[3 * 3 * Nslices + i*3 + 1] = (Nslices+1) + (i+1)%Nslices + 1;
    M2_indices[3 * 3 * Nslices + i*3 + 2] = (i+1)%Nslices + 1;
}



// indices definitions


/******* end copy 2 ***/







//// M3 : Sphere
// Replace the code below, that creates a simple triangle, with the one to create a sphere.

// Parto con origine == centro sfera
// altezza_massima == raggio
// per ogni punto intermedio dell'altezza, ho che raggio = sqrt(R^2-z^2)

// Resizes the vertices array. Repalce the values with the correct number of
// vertices components (3 * number of vertices)

int circle_slices = 36;
int sphere_leyers = 40;
float sphere_radious = 0.5;
height = 1;
cx = 0, cy = -0.5, cz = 0;
PI = 3.1415;

int index = 0;
M3_vertices.resize(((circle_slices+1)*3)*(sphere_leyers+1));
//  std::cout << "LEN 1: " << ((circle_slices+1)*3)*(sphere_leyers+1) << "\n"; 


for(int l = 0; l <= sphere_leyers; l++){
    M3_vertices[index++] = cx;
    M3_vertices[index++] = cy + l*height/sphere_leyers;
    M3_vertices[index++] = cz;
    // std::cout << "indiciiiiii: " << index-3 << "  " <<index-2 << "  " << index-1 << "\n\n";
    // std::cout << "X: " << M3_vertices[index-3]<< " - Y: " << M3_vertices[index-2] << " - Z:" << M3_vertices[index-1] << "\n";

    for (int i = 0; i<circle_slices; i++){
        radious = sqrt(pow(sphere_radious, 2) - pow(cy + l*height/sphere_leyers, 2));
        // std::cout << "RAGGIO: " << radious << "\n\n"; 
        M3_vertices[index++] = cx + radious * cos((float)i/circle_slices * 2.0 * PI);
        M3_vertices[index++] = cy + l*height/sphere_leyers;
        M3_vertices[index++] = cz + radious * sin((float)i/circle_slices * 2.0 * PI);
        // std::cout << "indici: " << index-3 << "  " <<index-2 << "  " << index-1 << "\n\n";
        // std::cout << "X: " << M3_vertices[index-3]<< " - Y: " << M3_vertices[index-2] << " - Z:" << M3_vertices[index-1] << "\n";
    }
    // std::cout << "\n\n";
}



// Resizes the indices array. Repalce the values with the correct number of
// indices (3 * number of triangles)
 M3_indices.resize(3 * circle_slices * (sphere_leyers+1) + 2 * 3 * circle_slices * sphere_leyers);
//  std::cout << "XXXXXXXXXXXXXXXLEN: " << 3 * circle_slices * (sphere_leyers+1) + 2 * 3 * circle_slices * sphere_leyers << "\n"; 

for(int l = 0; l <= sphere_leyers; l++){
    for (int i = 0; i<circle_slices; i++){
        M3_indices[l*circle_slices*3 + i*3 + 0] = l*(circle_slices+1);
        M3_indices[l*circle_slices*3 + i*3 + 1] = l*(circle_slices+1) + i + 1;
        M3_indices[l*circle_slices*3 + i*3 + 2] = l*(circle_slices+1) + (i+1)%circle_slices + 1;
        // std::cout << "indices:" << l*circle_slices*3 + i*3 + 0 << "  " << l*circle_slices*3 + i*3 + 1 << "  " << l*circle_slices*3 + i*3 + 2 << "\n";
        // std::cout << "X: " << M3_indices[l*circle_slices*3 + i*3 + 0] << " - Y: " << M3_indices[l*circle_slices*3 + i*3 + 1] << " - Z:" << M3_indices[l*circle_slices*3 + i*3 + 2] << "\n";
    }
    // std::cout << "\n";
}


//  std::cout << "YYYYYYYYYYYYYYYYYYYLEN: " << 3 * circle_slices * (sphere_leyers+1) + 2 * 3 * circle_slices * sphere_leyers << "\n"; 

index = 3 * circle_slices * (sphere_leyers+1);

for(int l = 0; l < sphere_leyers; l++){
    for (int i = 0; i<circle_slices; i++){
        M3_indices[index++] = l*(circle_slices+1) + i + 1;
        M3_indices[index++] = l*(circle_slices+1) + (i+1)%circle_slices + 1;
        M3_indices[index++] = l*(circle_slices+1) + i + 1 + (circle_slices+1);
        // std::cout << "indices:" << index - 3  << "  " << index - 2 << "  " << index - 1 << "\n";
        // std::cout << "X: " << M3_indices[index - 3] << " - Y: " << M3_indices[index - 2] << " - Z:" << M3_indices[index - 1] << "\n";
    }
    // std::cout << "\n";
}



for(int l = 1; l <= sphere_leyers; l++){
    for (int i = 0; i<circle_slices; i++){
        M3_indices[index++] = l*(circle_slices+1) + i + 1;
        M3_indices[index++] = l*(circle_slices+1) + (i+1)%circle_slices + 1;
        M3_indices[index++] = (l-1)*(circle_slices+1) + (i+1)%circle_slices + 1;
        // std::cout << "indices:" << index - 3  << "  " << index - 2 << "  " << index - 1 << "\n";
        // std::cout << "X: " << M3_indices[index - 3] << " - Y: " << M3_indices[index - 2] << " - Z:" << M3_indices[index - 1] << "\n";
    }
    // std::cout << "\n";
}


//// M4 : Spring
// Replace the code below, that creates a simple octahedron, with the one to create a spring.

int M4Circles = 216;
int M4SlicesPerCircle = 72;
float radious_ext = 2.0;
radious = .5;
float step = 5.0 / M4Circles;

M4_vertices.resize(3 * (M4SlicesPerCircle + 1) * M4Circles);
index = 0;
float xc, yc, zc;

for (int i = 0; i<M4Circles; i++){
    M4_vertices[index++] = xc = radious_ext * cos(4 * PI * i / M4Circles);
    M4_vertices[index++] = yc = 1 - step*i;
    M4_vertices[index++] = zc = radious_ext * sin(4 * PI *i / M4Circles);
    std::cout << "xc: " << xc << " - yc: " << yc << " - zc " << zc << "\n";
    for (int j = 0; j<M4SlicesPerCircle; j++){
        M4_vertices[index++] = xc + radious * cos(2 * PI * j / M4SlicesPerCircle) * cos(4 * PI *i / M4Circles);
        M4_vertices[index++] = yc + radious * sin(2 * PI * j / M4SlicesPerCircle);
        M4_vertices[index++] = zc + radious * cos(2 * PI * j / M4SlicesPerCircle) * sin(4 * PI *i / M4Circles);
        std::cout << "X: " << M4_vertices[index-3] << " - Y: " << M4_vertices[index-2] << " - Z: " << M4_vertices[index-1] << "\n";
    }
}

// // Vertices definitions
// M4_vertices[0]  =  0.0;
// M4_vertices[1]  =  1.414;
// M4_vertices[2]  = -1.0;
// M4_vertices[3]  =  0.0;
// M4_vertices[4]  = -1.414;
// M4_vertices[5]  = -1.0;
// M4_vertices[6]  = -1.0;
// M4_vertices[7]  =  0.0;
// M4_vertices[8]  = -2.0;
// M4_vertices[9]  = -1.0;
// M4_vertices[10] =  0.0;
// M4_vertices[11] =  0.0;
// M4_vertices[12] =  1.0;
// M4_vertices[13] =  0.0;
// M4_vertices[14] =  0.0;
// M4_vertices[15] =  1.0;
// M4_vertices[16] =  0.0;
// M4_vertices[17] = -2.0;


// Resizes the indices array. Repalce the values with the correct number of
// indices (3 * number of triangles)



M4_indices.resize(2 * 3 * (M4Circles-1) * M4SlicesPerCircle + 6 * 3 * M4SlicesPerCircle);


index = 0;

for (int i = 0; i < M4Circles - 1; i++){
    for (int j = 0; j < M4SlicesPerCircle; j++){
        M4_indices[index++] = (M4SlicesPerCircle+1)*i + j + 1;
        M4_indices[index++] = (M4SlicesPerCircle+1)*i + (j + 1)%M4SlicesPerCircle + 1;
        M4_indices[index++] = (M4SlicesPerCircle+1)*(i+1) + j + 1;
    }
}

for (int i = 1; i < M4Circles; i++){
    for (int j = 0; j < M4SlicesPerCircle; j++){
        M4_indices[index++] = (M4SlicesPerCircle+1)*i + j + 1;
        M4_indices[index++] = (M4SlicesPerCircle+1)*i + (j + 1)%M4SlicesPerCircle + 1;
        M4_indices[index++] = (M4SlicesPerCircle+1)*(i-1) + (j+1)%M4SlicesPerCircle + 1;
    }
}



for (int i = 0; i < M4SlicesPerCircle; i++){
    M4_indices[index++] = 0;
    M4_indices[index++] = i+1;
    M4_indices[index++] = (i+1)%M4SlicesPerCircle+1;//; (M4SlicesPerCircle+1)*(i+1) + j + 1;
}

for (int i = 0; i < M4SlicesPerCircle; i++){
    M4_indices[index++] = (1+M4SlicesPerCircle)*(M4Circles-1);
    M4_indices[index++] = (1+M4SlicesPerCircle)*(M4Circles-1) + i + 1;
    M4_indices[index++] = (1+M4SlicesPerCircle)*(M4Circles-1) + (i+1)%M4SlicesPerCircle+1;//; (M4SlicesPerCircle+1)*(i+1) + j + 1;

}





// indices definitions
// M4_indices[0]  = 0;
// M4_indices[1]  = 2;
// M4_indices[2]  = 3;
// M4_indices[3]  = 1;
// M4_indices[4]  = 3;
// M4_indices[5]  = 2;
// M4_indices[6]  = 0;
// M4_indices[7]  = 3;
// M4_indices[8]  = 4;
// M4_indices[9]  = 1;
// M4_indices[10] = 4;
// M4_indices[11] = 3;
// M4_indices[12] = 0;
// M4_indices[13] = 4;
// M4_indices[14] = 5;
// M4_indices[15] = 1;
// M4_indices[16] = 5;
// M4_indices[17] = 4;
// M4_indices[18] = 0;
// M4_indices[19] = 5;
// M4_indices[20] = 2;
// M4_indices[21] = 1;
// M4_indices[22] = 2;
// M4_indices[23] = 5;
}
