#include <GL/glut.h>
// Transformation parameters
float scale = 1.0f;
float translateX = 0.0f, translateY = 0.0f, translateZ = 0.0f;
float rotateAngle = 0.0f;
// Function to draw a cube
void drawCube() {
    glutWireCube(1.0); // Draw a wireframe cube
}
// Display function
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear the screen and depth buffer
    glLoadIdentity(); // Load the identity matrix
    // Apply transformations
    glTranslatef(translateX, translateY, translateZ); // Translation
    glScalef(scale, scale, scale);                   // Scaling
    glRotatef(rotateAngle, 1.0f, 1.0f, 1.0f);        // Rotation about an axis
    // Draw the cube
    drawCube();
    glutSwapBuffers(); // Swap buffers for double buffering
}
// Keyboard controls
void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 's': scale += 0.1f; break;          // Increase scale
        case 'S': scale -= 0.1f; break;          // Decrease scale
        case 'x': translateX += 0.1f; break;     // Translate along X
        case 'X': translateX -= 0.1f; break;     // Translate along -X
        case 'y': translateY += 0.1f; break;     // Translate along Y
        case 'Y': translateY -= 0.1f; break;     // Translate along -Y
        case 'z': translateZ += 0.1f; break;     // Translate along Z
        case 'Z': translateZ -= 0.1f; break;     // Translate along -Z
        case 'r': rotateAngle += 5.0f; break;    // Rotate clockwise
        case 'R': rotateAngle -= 5.0f; break;    // Rotate counterclockwise
        case 27: exit(0);                        // Escape key to exit
    }
    glutPostRedisplay(); // Request redisplay
}
// Reshape function to handle window resizing
void reshape(int w, int h) {
    glViewport(0, 0, w, h); // Set the viewport to cover the new window
    glMatrixMode(GL_PROJECTION); // Set projection matrix
    glLoadIdentity();
    gluPerspective(45.0, (double)w / (double)h, 1.0, 100.0); // Perspective projection
    glMatrixMode(GL_MODELVIEW); // Switch back to modelview matrix
}
// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // Double buffering and depth buffer
    glutInitWindowSize(800, 600);
    glutCreateWindow("3D Cube Transformations");
    glEnable(GL_DEPTH_TEST); // Enable depth testing
    glutDisplayFunc(display);   // Set the display callback
    glutReshapeFunc(reshape);   // Set the reshape callback
    glutKeyboardFunc(keyboard); // Set the keyboard callback
    glutMainLoop(); // Enter the main event loop
    return 0;
}