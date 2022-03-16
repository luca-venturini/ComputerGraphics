// Create a matrix for Isometric projection with the given aspect ration a
glm::mat4 PO1(float a) {
	float w = 2;
	float l=(-w), r=w, b=(-w)/a, t=w/a, n=-4, f=12;
	glm::mat4 scale = glm::scale(glm::mat4(1.0), glm::vec3(1, -1, 1));
	glm::mat4 ort = glm::ortho(l, r, b, t, n, f);
	glm::mat4 rot_35 = glm::rotate(glm::mat4(1.0), glm::radians(35.26f), glm::vec3(1, 0, 0));
	glm::mat4 rot_45 = glm::rotate(glm::mat4(1.0), glm::radians(45.0f), glm::vec3(0, 1, 0));
	return scale*ort*rot_35*rot_45;
}

// Create a matrix for Dimnetric projection (alpha = 45 degree)
// with the given aspect ration a
glm::mat4 PO2(float a) {
	float w = 2;
	float l=(-w), r=w, b=(-w)/a, t=w/a, n=-4, f=12;
	glm::mat4 scale = glm::scale(glm::mat4(1.0), glm::vec3(1, -1, 1));
	glm::mat4 ort = glm::ortho(l, r, b, t, n, f);
	glm::mat4 rot_alpha = glm::rotate(glm::mat4(1.0), glm::radians(45.0f), glm::vec3(1, 0, 0));
	glm::mat4 rot_45 = glm::rotate(glm::mat4(1.0), glm::radians(45.0f), glm::vec3(0, 1, 0));
	return scale*ort*rot_alpha*rot_45;
}

// Create a matrix for Trimetric projection (alpha = 45 degree, beta = 60 degree)
// with the given aspect ration a
glm::mat4 PO3(float a) {
	float w = 2;
	float l=(-w), r=w, b=(-w)/a, t=w/a, n=-4, f=12;
	glm::mat4 scale = glm::scale(glm::mat4(1.0), glm::vec3(1, -1, 1));
	glm::mat4 ort = glm::ortho(l, r, b, t, n, f);
	glm::mat4 rot_alpha = glm::rotate(glm::mat4(1.0), glm::radians(45.0f), glm::vec3(1, 0, 0));
	glm::mat4 rot_beta = glm::rotate(glm::mat4(1.0), glm::radians(60.0f), glm::vec3(0, 1, 0));
	return scale*ort*rot_alpha*rot_beta;
}

// Create a matrix for Cabinet projection (alpha = 45)
// with the given aspect ration a
glm::mat4 PO4(float a) {
	float w = 2;
	float l=(-w), r=w, b=(-w)/a, t=w/a, n=-4, f=12;
	glm::mat4 scale = glm::scale(glm::mat4(1.0), glm::vec3(1, -1, 1));
	glm::mat4 ort = glm::ortho(l, r, b, t, n, f);
	glm::mat4 shear = glm::mat4(1.0);
	shear[2][0] = -(0.5)*cos(45);
	shear[2][1] = -(0.5)*sin(45);
	return scale*ort*shear;
}

