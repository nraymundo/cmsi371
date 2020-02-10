/***
 assignment1.cpp
 Assignment-1: Cartoonify

 Name: Raymundo, Nicolas

 Collaborators: N/A

 Project Summary:
 Using OpenGL and C++ to design a cartoon version of a face of our own choosing. 
 I used Bezier's algorithm to accomplish this task, taking an iterative approach with the drawing of the curve.
 ***/

#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#endif

#include <vector>
#include <iostream>
using namespace std;

class Vertex
{
    GLfloat x, y;

public:
    Vertex(GLfloat, GLfloat);
    GLfloat get_y() { return y; };
    GLfloat get_x() { return x; };
};

Vertex::Vertex(GLfloat X, GLfloat Y)
{
    x = X;
    y = Y;
}

void setup()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

Vertex computeMidpoint(Vertex point_a, Vertex point_b)
{
    GLfloat x = .5 * (point_a.get_x() + point_b.get_x());
    GLfloat y = .5 * (point_a.get_y() + point_b.get_y());

    return Vertex(x, y);
}

vector<Vertex> generate_points(vector<Vertex> control_points)
{
    vector<Vertex> points = control_points;
    vector<Vertex> final_points_left;
    vector<Vertex> final_points;
    vector<Vertex> final_points_right;

    for (int i = 0; i < control_points.size() - 1; i++)
    {
        vector<Vertex> midpoints;
        for (int j = 0; j < points.size() - 1; j++)
        {
            Vertex m = Vertex(.5 * (points[j].get_x() + points[j + 1].get_x()), .5 * (points[j].get_y() + points[j + 1].get_y()));
            // Vertex m = computeMidpoint(points[j], points[j + 1]);
            midpoints.push_back(m);
        }
        points = midpoints;
        if (midpoints.size() == 1)
        {
            final_points_left.push_back(midpoints[0]);
        }
        else
        {
            final_points_left.push_back(midpoints[0]);
            final_points_right.push_back(midpoints[midpoints.size() - 1]);
        }
    }

    final_points.push_back(control_points[0]);
    for (int i = 0; i < final_points_left.size(); i++)
    {
        final_points.push_back(final_points_left[i]);
    }

    for (int j = final_points_right.size() - 1; j > 0; j--)
    {
        final_points.push_back(final_points_right[j]);
    }
    final_points.push_back(control_points[control_points.size() - 1]);

    return final_points;
}

void draw_curve(vector<Vertex> control_points, int n_iter)
{
    vector<Vertex> points = control_points;

    for (int i = 0; i < n_iter; i++)
    {
        points = generate_points(points);
    }

    glPointSize(5.0f);
    glBegin(GL_POINTS);

    for (int i = 0; i < points.size() - 1; i++)
    {
        glVertex2f(points[i].get_x(), points[i].get_y());
        glVertex2f(points[i + 1].get_x(), points[i + 1].get_y());
    }

    glEnd();

    glLineWidth(15.0f);
    glBegin(GL_LINES);

    for (int i = 0; i < points.size() - 1; i++)
    {
        glVertex2f(points[i].get_x(), points[i].get_y());
        glVertex2f(points[i + 1].get_x(), points[i + 1].get_y());
    }

    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // Set our color to black (R, G, B)
    glColor3f(0.0f, 0.0f, 0.0f);

    vector<Vertex> top_left_outer_face;

    top_left_outer_face.push_back(Vertex(0, 0.96));
    top_left_outer_face.push_back(Vertex(-0.2, 0.95));
    top_left_outer_face.push_back(Vertex(-0.4, 0.92));
    top_left_outer_face.push_back(Vertex(-0.6, 0.84));
    top_left_outer_face.push_back(Vertex(-0.8, 0.69));
    top_left_outer_face.push_back(Vertex(-0.91, 0.5));
    top_left_outer_face.push_back(Vertex(-0.95, 0.35));
    top_left_outer_face.push_back(Vertex(-0.92, 0.2));
    // top_left_outer_face.push_back(Vertex(-0.95, 0.08));
    // top_left_outer_face.push_back(Vertex(-0.96, 0));

    vector<Vertex> top_left_inner_face;

    top_left_inner_face.push_back(Vertex(-0.92, 0.2));
    top_left_inner_face.push_back(Vertex(-0.885, 0.28));
    top_left_inner_face.push_back(Vertex(-0.85, 0.34));
    top_left_inner_face.push_back(Vertex(-0.8, 0.403));
    top_left_inner_face.push_back(Vertex(-0.75, 0.455));
    top_left_inner_face.push_back(Vertex(-0.7, 0.495));
    top_left_inner_face.push_back(Vertex(-0.65, 0.53));
    top_left_inner_face.push_back(Vertex(-0.6, 0.557));
    top_left_inner_face.push_back(Vertex(-0.5, 0.603));
    top_left_inner_face.push_back(Vertex(-0.4, 0.636));
    top_left_inner_face.push_back(Vertex(-0.3, 0.659));
    top_left_inner_face.push_back(Vertex(-0.2, 0.675));
    top_left_inner_face.push_back(Vertex(-0.1, 0.682));
    top_left_inner_face.push_back(Vertex(0, 0.681));

    vector<Vertex> connect_left_face;

    connect_left_face.push_back(Vertex(-0.92, 0.2));
    connect_left_face.push_back(Vertex(-0.95, 0.08));
    connect_left_face.push_back(Vertex(-0.96, 0));

    vector<Vertex> bottom_left_outer_face;

    bottom_left_outer_face.push_back(Vertex(-0.96, 0));
    bottom_left_outer_face.push_back(Vertex(-0.966, -0.034));
    bottom_left_outer_face.push_back(Vertex(-0.968, -0.074));
    bottom_left_outer_face.push_back(Vertex(-0.971, -0.12));
    bottom_left_outer_face.push_back(Vertex(-0.9715, -0.168));
    bottom_left_outer_face.push_back(Vertex(-0.968, -0.219));
    bottom_left_outer_face.push_back(Vertex(-0.968, -0.219));
    bottom_left_outer_face.push_back(Vertex(-0.948, -0.323));
    bottom_left_outer_face.push_back(Vertex(-0.935, -0.367));
    bottom_left_outer_face.push_back(Vertex(-0.9175, -0.414));
    bottom_left_outer_face.push_back(Vertex(-0.896, -0.456));
    bottom_left_outer_face.push_back(Vertex(-0.8735, -0.5));
    bottom_left_outer_face.push_back(Vertex(-0.843, -0.547));
    bottom_left_outer_face.push_back(Vertex(-0.8075, -0.596));
    bottom_left_outer_face.push_back(Vertex(-0.767, -0.643));
    bottom_left_outer_face.push_back(Vertex(-0.741, -0.673));
    bottom_left_outer_face.push_back(Vertex(-0.705, -0.706));
    bottom_left_outer_face.push_back(Vertex(-0.6655, -0.738));
    bottom_left_outer_face.push_back(Vertex(-0.624, -0.772));
    bottom_left_outer_face.push_back(Vertex(-0.601, -0.788));
    bottom_left_outer_face.push_back(Vertex(-0.5665, -0.809));
    bottom_left_outer_face.push_back(Vertex(-0.534, -0.828));
    bottom_left_outer_face.push_back(Vertex(-0.5235, -0.836));
    bottom_left_outer_face.push_back(Vertex(-0.494, -0.851));
    bottom_left_outer_face.push_back(Vertex(-0.461, -0.867));
    bottom_left_outer_face.push_back(Vertex(-0.445, -0.872));
    bottom_left_outer_face.push_back(Vertex(-0.414, -0.886));
    bottom_left_outer_face.push_back(Vertex(-0.395, -0.8915));
    bottom_left_outer_face.push_back(Vertex(-0.336, -0.913));
    bottom_left_outer_face.push_back(Vertex(-0.3, -0.92));
    bottom_left_outer_face.push_back(Vertex(-0.245, -0.933));
    bottom_left_outer_face.push_back(Vertex(-0.19, -0.942));
    bottom_left_outer_face.push_back(Vertex(-0.134, -0.946));
    bottom_left_outer_face.push_back(Vertex(-0.071, -0.948));
    bottom_left_outer_face.push_back(Vertex(-0.0305, -0.948));
    bottom_left_outer_face.push_back(Vertex(0, -0.945));

    vector<Vertex> bottom_right_outer_face;

    bottom_right_outer_face.push_back(Vertex(0, -0.945));
    bottom_right_outer_face.push_back(Vertex(0.0355, -0.942));
    bottom_right_outer_face.push_back(Vertex(0.071, -0.937));
    bottom_right_outer_face.push_back(Vertex(0.117, -0.932));
    bottom_right_outer_face.push_back(Vertex(0.164, -0.921));
    bottom_right_outer_face.push_back(Vertex(0.197, -0.913));
    bottom_right_outer_face.push_back(Vertex(0.2, -0.91));
    bottom_right_outer_face.push_back(Vertex(0.244, -0.897));
    bottom_right_outer_face.push_back(Vertex(0.304, -0.8805));
    bottom_right_outer_face.push_back(Vertex(0.362, -0.856));
    bottom_right_outer_face.push_back(Vertex(0.41, -0.834));
    bottom_right_outer_face.push_back(Vertex(0.447, -0.815));
    bottom_right_outer_face.push_back(Vertex(0.51, -0.771));
    bottom_right_outer_face.push_back(Vertex(0.558, -0.732));
    bottom_right_outer_face.push_back(Vertex(0.598, -0.69));
    bottom_right_outer_face.push_back(Vertex(0.625, -0.656));
    bottom_right_outer_face.push_back(Vertex(0.652, -0.62));
    bottom_right_outer_face.push_back(Vertex(0.675, -0.585));
    bottom_right_outer_face.push_back(Vertex(0.698, -0.547));
    bottom_right_outer_face.push_back(Vertex(0.7145, -0.514));
    bottom_right_outer_face.push_back(Vertex(0.732, -0.478));
    bottom_right_outer_face.push_back(Vertex(0.745, -0.442));
    bottom_right_outer_face.push_back(Vertex(0.75, -0.44));

    vector<Vertex> right_ear;

    right_ear.push_back(Vertex(0.75, -0.44));
    right_ear.push_back(Vertex(0.778, -0.452));
    right_ear.push_back(Vertex(0.82, -0.448));
    right_ear.push_back(Vertex(0.854, -0.436));
    right_ear.push_back(Vertex(0.887, -0.411));
    right_ear.push_back(Vertex(0.914, -0.382));
    right_ear.push_back(Vertex(0.934, -0.35));
    right_ear.push_back(Vertex(0.95, -0.316));
    right_ear.push_back(Vertex(0.962, -0.2835));
    right_ear.push_back(Vertex(0.969, -0.249));
    right_ear.push_back(Vertex(0.967, -0.206));
    right_ear.push_back(Vertex(0.953, -0.173));
    right_ear.push_back(Vertex(0.93, -0.137));
    right_ear.push_back(Vertex(0.911, -0.118));
    right_ear.push_back(Vertex(0.88, -0.1));

    vector<Vertex> line_next_to_right_ear;

    line_next_to_right_ear.push_back(Vertex(0.824, -0.084));
    line_next_to_right_ear.push_back(Vertex(0.811, -0.0865));
    line_next_to_right_ear.push_back(Vertex(0.799, -0.089));
    line_next_to_right_ear.push_back(Vertex(0.789, -0.091));
    line_next_to_right_ear.push_back(Vertex(0.7795, -0.094));
    line_next_to_right_ear.push_back(Vertex(0.769, -0.095));

    vector<Vertex> top_right_outer_face;

    top_right_outer_face.push_back(Vertex(0.88, -0.1));
    top_right_outer_face.push_back(Vertex(0.89, -0.05));
    top_right_outer_face.push_back(Vertex(0.9, 0));
    top_right_outer_face.push_back(Vertex(0.9, 0.05));
    top_right_outer_face.push_back(Vertex(0.92, 0.1));
    top_right_outer_face.push_back(Vertex(0.93, 0.14));
    top_right_outer_face.push_back(Vertex(0.93, 0.2));
    top_right_outer_face.push_back(Vertex(0.93, 0.27));
    top_right_outer_face.push_back(Vertex(0.92, 0.31));
    top_right_outer_face.push_back(Vertex(0.87, 0.41));
    top_right_outer_face.push_back(Vertex(0.83, 0.49));
    top_right_outer_face.push_back(Vertex(0.8, 0.55));
    top_right_outer_face.push_back(Vertex(0.75, 0.64));
    top_right_outer_face.push_back(Vertex(0.72, 0.66));
    top_right_outer_face.push_back(Vertex(0.7, 0.67));
    top_right_outer_face.push_back(Vertex(0.65, 0.72));
    top_right_outer_face.push_back(Vertex(0.6, 0.77));
    top_right_outer_face.push_back(Vertex(0.5, 0.84));
    top_right_outer_face.push_back(Vertex(0.33, 0.94));
    top_right_outer_face.push_back(Vertex(0.19, 0.96));
    top_right_outer_face.push_back(Vertex(0.1, 0.96));
    top_right_outer_face.push_back(Vertex(0, 0.96));

    vector<Vertex> top_right_inner_face;

    top_right_inner_face.push_back(Vertex(0, 0.681));
    top_right_inner_face.push_back(Vertex(0.1, 0.673));
    top_right_inner_face.push_back(Vertex(0.2, 0.656));
    top_right_inner_face.push_back(Vertex(0.3, 0.623));
    top_right_inner_face.push_back(Vertex(0.4, 0.576));
    top_right_inner_face.push_back(Vertex(0.5, 0.509));
    top_right_inner_face.push_back(Vertex(0.6, 0.428));
    top_right_inner_face.push_back(Vertex(0.7, 0.312));
    top_right_inner_face.push_back(Vertex(0.75, 0.234));
    top_right_inner_face.push_back(Vertex(0.8, 0.11));
    top_right_inner_face.push_back(Vertex(0.823, 0));
    top_right_inner_face.push_back(Vertex(0.824, -0.084));

    vector<Vertex> connect_right_face;

    connect_right_face.push_back(Vertex(0.824, -0.084));
    connect_right_face.push_back(Vertex(0.88, -0.1));

    vector<Vertex> left_eye;

    left_eye.push_back(Vertex(-0.777, 0));
    left_eye.push_back(Vertex(-0.738, 0.063));
    left_eye.push_back(Vertex(-0.692, 0.115));
    left_eye.push_back(Vertex(-0.638, 0.154));
    left_eye.push_back(Vertex(-0.58, 0.18));
    left_eye.push_back(Vertex(-0.518, 0.19));
    left_eye.push_back(Vertex(-0.434, 0.182));
    left_eye.push_back(Vertex(-0.365, 0.154));
    left_eye.push_back(Vertex(-0.299, 0.104));
    left_eye.push_back(Vertex(-0.266, 0.057));
    left_eye.push_back(Vertex(-0.24, 0));
    left_eye.push_back(Vertex(-0.24, -0.044));
    left_eye.push_back(Vertex(-0.253, -0.098));
    left_eye.push_back(Vertex(-0.274, -0.146));
    left_eye.push_back(Vertex(-0.3, -0.186));
    left_eye.push_back(Vertex(-0.34, -0.23));
    left_eye.push_back(Vertex(-0.393, -0.266));
    left_eye.push_back(Vertex(-0.448, -0.287));
    left_eye.push_back(Vertex(-0.518, -0.305));
    left_eye.push_back(Vertex(-0.596, -0.3));
    left_eye.push_back(Vertex(-0.649, -0.285));
    left_eye.push_back(Vertex(-0.691, -0.268));
    left_eye.push_back(Vertex(-0.735, -0.236));
    left_eye.push_back(Vertex(-0.768, -0.196));
    left_eye.push_back(Vertex(-0.79, -0.146));
    left_eye.push_back(Vertex(-0.798, -0.096));
    left_eye.push_back(Vertex(-0.793, -0.05));
    left_eye.push_back(Vertex(-0.789, -0.02));
    left_eye.push_back(Vertex(-0.777, 0));

    vector<Vertex> left_eye_dot;
    left_eye_dot.push_back(Vertex(-0.517, -0.0534));
    left_eye_dot.push_back(Vertex(-0.5293, -0.064));
    left_eye_dot.push_back(Vertex(-0.549, -0.054));
    left_eye_dot.push_back(Vertex(-0.533, -0.0374));
    left_eye_dot.push_back(Vertex(-0.517, -0.0534));

    vector<Vertex> right_eye;

    right_eye.push_back(Vertex(-0.031, 0.0005));
    right_eye.push_back(Vertex(-0.039, -0.062));
    right_eye.push_back(Vertex(-0.038, -0.109));
    right_eye.push_back(Vertex(-0.0215, -0.172));
    right_eye.push_back(Vertex(0.016, -0.237));
    right_eye.push_back(Vertex(0.0684, -0.28));
    right_eye.push_back(Vertex(0.16, -0.313));
    right_eye.push_back(Vertex(0.2685, -0.322));
    right_eye.push_back(Vertex(0.357, -0.302));
    right_eye.push_back(Vertex(0.423, -0.2645));
    right_eye.push_back(Vertex(0.477, -0.2074));
    right_eye.push_back(Vertex(0.522, -0.1316));
    right_eye.push_back(Vertex(0.537, -0.065));
    right_eye.push_back(Vertex(0.528, -0.001));
    right_eye.push_back(Vertex(0.5, 0.06));
    right_eye.push_back(Vertex(0.457, 0.11));
    right_eye.push_back(Vertex(0.392, 0.151));
    right_eye.push_back(Vertex(0.3154, 0.178));
    right_eye.push_back(Vertex(0.235, 0.184));
    right_eye.push_back(Vertex(0.137, 0.168));
    right_eye.push_back(Vertex(0.062, 0.1326));
    right_eye.push_back(Vertex(0.011, 0.087));
    right_eye.push_back(Vertex(-0.015, 0.047));
    right_eye.push_back(Vertex(-0.031, 0.0005));

    vector<Vertex> right_eye_dot;
    right_eye_dot.push_back(Vertex(0.253, -0.053));
    right_eye_dot.push_back(Vertex(0.238, -0.0637));
    right_eye_dot.push_back(Vertex(0.2236, -0.053));
    right_eye_dot.push_back(Vertex(0.239, -0.037));
    right_eye_dot.push_back(Vertex(0.253, -0.053));

    vector<Vertex> left_brow;
    left_brow.push_back(Vertex(-0.726, 0.218));
    left_brow.push_back(Vertex(-0.547, 0.249));
    left_brow.push_back(Vertex(-0.327, 0.26));

    vector<Vertex> right_brow;
    right_brow.push_back(Vertex(0.03, 0.2795));
    right_brow.push_back(Vertex(0.079, 0.245));
    right_brow.push_back(Vertex(0.195, 0.2194));
    right_brow.push_back(Vertex(0.47, 0.21));

    vector<Vertex> nose;
    nose.push_back(Vertex(-0.177, -0.262));
    nose.push_back(Vertex(-0.2355, -0.311));
    nose.push_back(Vertex(-0.268, -0.367));
    nose.push_back(Vertex(-0.267, -0.411));
    nose.push_back(Vertex(-0.227, -0.445));
    nose.push_back(Vertex(-0.171, -0.4485));
    nose.push_back(Vertex(-0.124, -0.434));
    nose.push_back(Vertex(-0.06, -0.397));

    vector<Vertex> mouth;
    mouth.push_back(Vertex(-0.1755, -0.5986));
    mouth.push_back(Vertex(-0.23, -0.74));
    mouth.push_back(Vertex(-0.233, -0.769));
    mouth.push_back(Vertex(-0.233, -0.79));
    mouth.push_back(Vertex(-0.227, -0.808));
    mouth.push_back(Vertex(-0.203, -0.8315));
    mouth.push_back(Vertex(-0.186, -0.807));
    mouth.push_back(Vertex(-0.167, -0.784));
    mouth.push_back(Vertex(-0.146, -0.758));
    mouth.push_back(Vertex(-0.117, -0.731));
    mouth.push_back(Vertex(-0.111, -0.746));
    mouth.push_back(Vertex(-0.111, -0.768));
    mouth.push_back(Vertex(-0.105, -0.798));
    mouth.push_back(Vertex(-0.097, -0.824));
    mouth.push_back(Vertex(-0.087, -0.844));
    mouth.push_back(Vertex(-0.065, -0.868));
    mouth.push_back(Vertex(-0.045, -0.877));
    mouth.push_back(Vertex(-0.025, -0.879));
    mouth.push_back(Vertex(-0.005, -0.859));
    mouth.push_back(Vertex(0.006, -0.832));
    mouth.push_back(Vertex(0.014, -0.799));
    mouth.push_back(Vertex(0.019, -0.763));
    mouth.push_back(Vertex(0.0245, -0.726));
    mouth.push_back(Vertex(0.03, -0.687));

    draw_curve(top_left_outer_face, 6);
    draw_curve(top_left_inner_face, 6);
    draw_curve(connect_left_face, 6);
    draw_curve(top_right_outer_face, 6);
    draw_curve(top_right_inner_face, 6);
    draw_curve(connect_right_face, 6);
    draw_curve(bottom_left_outer_face, 6);
    draw_curve(bottom_right_outer_face, 6);
    draw_curve(right_ear, 6);
    draw_curve(line_next_to_right_ear, 6);
    draw_curve(left_eye, 6);
    draw_curve(left_eye_dot, 6);
    draw_curve(right_eye, 6);
    draw_curve(right_eye_dot, 6);
    draw_curve(left_brow, 6);
    draw_curve(right_brow, 6);
    draw_curve(nose, 6);
    draw_curve(mouth, 6);

    glutSwapBuffers();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize(900, 900); // Set your own window size
    glutCreateWindow("Assignment 1");
    setup();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
