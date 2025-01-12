#include <windows.h>
#include <GL/glut.h>
#include <cmath>

float p = 0.0f;  // Ubah nilai p untuk menempatkan pesawat di tengah layar

void drawLine(float x1, float y1, float x2, float y2) {
    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
}

void init(void) {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);  // Background hitam
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 100.0, 0.0, 80.0);  // Tetap gunakan ukuran jendela 2D
}

void drawShapes(void) {
    glClear(GL_COLOR_BUFFER_BIT);  // Bersihkan layar dengan warna latar belakang yang baru

    glColor3f(1.0, 0.0, 0.0);  // Pesawat berwarna merah

    // Gambar badan pesawat (sesuaikan posisi untuk menempatkan pesawat di tengah)
    glColor3f(0.7, 0.7, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(70 - p, 70);
    glVertex2f(85 - p, 70);
    glVertex2f(85 - p, 65);
    glVertex2f(70 - p, 65);
    glEnd();

    // Gambar sayap pesawat
    glBegin(GL_QUADS);
    glVertex2f(85 - p, 70);
    glVertex2f(90 - p, 75);
    glVertex2f(93 - p, 75);
    glVertex2f(85 - p, 65);
    glEnd();

    // Gambar ekor pesawat
    glColor3f(0.7, 0.0, 1.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(65 - p, 66);
    glVertex2f(70 - p, 70);
    glVertex2f(70 - p, 65);
    glEnd();

    // Gambar kokpit pesawat
    glColor3f(0, 0, 1);
    glBegin(GL_QUADS);
    glVertex2f(77 - p, 70);
    glVertex2f(81 - p, 74);
    glVertex2f(83 - p, 74);
    glVertex2f(80 - p, 70);
    glEnd();

    // Gambar bagian bawah pesawat
    glBegin(GL_QUADS);
    glVertex2f(77 - p, 65);
    glVertex2f(80 - p, 65);
    glVertex2f(81 - p, 62);
    glVertex2f(79 - p, 62);
    glEnd();

    glFlush();  // Render gambar
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);                        // Inisialisasi GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);   // Mode tampilan (single buffer, RGB)
    glutInitWindowPosition(50, 100);               // Posisi jendela
    glutInitWindowSize(1100, 800);                 // Ukuran jendela
    glutCreateWindow("Pesawat 2D");                // Judul jendela

    init();                                        // Inisialisasi OpenGL
    glutDisplayFunc(drawShapes);                   // Fungsi untuk menggambar pesawat
    glutMainLoop();                                // Mulai loop utama GLUT

    return 0;
}

