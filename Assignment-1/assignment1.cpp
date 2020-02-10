/***
 assignment1.cpp
 Assignment-1: Cartoonify

 Name: Raymundo, Nicolas

 Collaborators: N/A

 Project Summary:
 Using OpenGL and C++ to design a cartoon version of a face of our own choosing.
 I used Bezier's algorithm to accomplish this task, taking an iterative approach
 with the drawing of the curve.
 ***/

#ifdef __APPLE__
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#endif

#include <iostream>
#include <vector>
using namespace std;

class Vertex {
  GLfloat x, y;

 public:
  Vertex(GLfloat, GLfloat);
  GLfloat get_y() { return y; };
  GLfloat get_x() { return x; };
};

Vertex::Vertex(GLfloat X, GLfloat Y) {
  x = X;
  y = Y;
}

void setup() { glClearColor(1.0f, 1.0f, 1.0f, 1.0f); }

Vertex computeMidpoint(Vertex point_a, Vertex point_b) {
  GLfloat x = .5 * (point_a.get_x() + point_b.get_x());
  GLfloat y = .5 * (point_a.get_y() + point_b.get_y());

  return Vertex(x, y);
}

vector<Vertex> generate_points(vector<Vertex> control_points) {
  vector<Vertex> points = control_points;
  vector<Vertex> final_points_left;
  vector<Vertex> final_points;
  vector<Vertex> final_points_right;

  for (int i = 0; i < control_points.size() - 1; i++) {
    vector<Vertex> midpoints;
    for (int j = 0; j < points.size() - 1; j++) {
      Vertex m = computeMidpoint(points[j], points[j + 1]);
      midpoints.push_back(m);
    }
    points = midpoints;
    if (midpoints.size() == 1) {
      final_points_left.push_back(midpoints[0]);
    } else {
      final_points_left.push_back(midpoints[0]);
      final_points_right.push_back(midpoints[midpoints.size() - 1]);
    }
  }

  final_points.push_back(control_points[0]);
  for (int i = 0; i < final_points_left.size(); i++) {
    final_points.push_back(final_points_left[i]);
  }

  for (int j = final_points_right.size() - 1; j > 0; j--) {
    final_points.push_back(final_points_right[j]);
  }
  final_points.push_back(control_points[control_points.size() - 1]);

  return final_points;
}

void draw_curve(vector<Vertex> control_points, int n_iter) {
  vector<Vertex> points = control_points;

  for (int i = 0; i < n_iter; i++) {
    points = generate_points(points);
  }

  glLineWidth(15.0f);
  glBegin(GL_LINES);

  for (int i = 0; i < points.size() - 1; i++) {
    glVertex2f(points[i].get_x(), points[i].get_y());
    glVertex2f(points[i + 1].get_x(), points[i + 1].get_y());
  }

  glEnd();
}

void display() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  // Set our color to black (R, G, B)
  glColor3f(0.0f, 0.0f, 0.0f);

  vector<Vertex> hair_section_1;

  hair_section_1.push_back(Vertex(0, 0.4837));
  hair_section_1.push_back(Vertex(0.265, 0.505));
  hair_section_1.push_back(Vertex(0.302, 0.3434));
  hair_section_1.push_back(Vertex(0.377, 0.329));

  vector<Vertex> hair_section_2;

  hair_section_2.push_back(Vertex(0.377, 0.329));
  hair_section_2.push_back(Vertex(0.4153, 0.242));
  hair_section_2.push_back(Vertex(0.442, 0.224));
  hair_section_2.push_back(Vertex(0.4656, 0.143));

  vector<Vertex> hair_section_3;

  hair_section_3.push_back(Vertex(0.4656, 0.143));
  hair_section_3.push_back(Vertex(0.484, 0.0267));
  hair_section_3.push_back(Vertex(0.4445, 0.054));
  hair_section_3.push_back(Vertex(0.45, 0.001));

  vector<Vertex> hair_section_4;

  hair_section_4.push_back(Vertex(0.45, 0.001));
  hair_section_4.push_back(Vertex(0.4503, -0.0236));
  hair_section_4.push_back(Vertex(0.446, -0.0387));
  hair_section_4.push_back(Vertex(0.4395, -0.048));

  vector<Vertex> hair_section_5;

  hair_section_5.push_back(Vertex(0.4395, -0.048));
  hair_section_5.push_back(Vertex(0.4188, -0.0378));
  hair_section_5.push_back(Vertex(0.4122, -0.0434));
  hair_section_5.push_back(Vertex(0.4139, -0.0406));

  vector<Vertex> hair_section_6;

  hair_section_6.push_back(Vertex(0.4139, -0.0406));
  hair_section_6.push_back(Vertex(0.429, 0.1246));
  hair_section_6.push_back(Vertex(0.258, 0.331));
  hair_section_6.push_back(Vertex(0, 0.344));

  vector<Vertex> hair_section_7;

  hair_section_7.push_back(Vertex(0, 0.344));
  hair_section_7.push_back(Vertex(-0.339, 0.346));
  hair_section_7.push_back(Vertex(-0.4313, 0.1834));
  hair_section_7.push_back(Vertex(-0.46, 0.107));

  vector<Vertex> hair_section_8;

  hair_section_8.push_back(Vertex(-0.46, 0.107));
  hair_section_8.push_back(Vertex(-0.4996, 0.1614));
  hair_section_8.push_back(Vertex(-0.4634, 0.197));
  hair_section_8.push_back(Vertex(-0.465, 0.318));
  hair_section_8.push_back(Vertex(-0.384, 0.398));
  hair_section_8.push_back(Vertex(-0.232, 0.4516));

  vector<Vertex> hair_section_9;

  hair_section_9.push_back(Vertex(-0.232, 0.4516));
  hair_section_9.push_back(Vertex(-0.172, 0.462));
  hair_section_9.push_back(Vertex(-0.146, 0.485));
  hair_section_9.push_back(Vertex(-0.087, 0.467));
  hair_section_9.push_back(Vertex(-0.052, 0.483));
  hair_section_9.push_back(Vertex(0, 0.4837));

  vector<Vertex> head_section_1;

  head_section_1.push_back(Vertex(-0.46, 0.107));
  head_section_1.push_back(Vertex(-0.513, -0.069));
  head_section_1.push_back(Vertex(-0.522, -0.2));
  head_section_1.push_back(Vertex(-0.344, -0.3824));
  head_section_1.push_back(Vertex(-0.4305, -0.298));
  head_section_1.push_back(Vertex(-0.25, -0.48));
  head_section_1.push_back(Vertex(-0.048, -0.474));

  vector<Vertex> head_section_2;

  head_section_2.push_back(Vertex(-0.048, -0.474));
  head_section_2.push_back(Vertex(0.068, -0.4825));
  head_section_2.push_back(Vertex(0.163, -0.425));
  head_section_2.push_back(Vertex(0.2554, -0.4518));
  head_section_2.push_back(Vertex(0.226, -0.334));
  head_section_2.push_back(Vertex(0.274, -0.451));
  head_section_2.push_back(Vertex(0.373, -0.222));

  vector<Vertex> head_section_3;

  head_section_3.push_back(Vertex(0.373, -0.222));
  head_section_3.push_back(Vertex(0.484, -0.245));
  head_section_3.push_back(Vertex(0.52, -0.073));
  head_section_3.push_back(Vertex(0.4395, -0.048));

  vector<Vertex> head_section_4;

  head_section_4.push_back(Vertex(0.4139, -0.0406));
  head_section_4.push_back(Vertex(0.3993, -0.0418));
  head_section_4.push_back(Vertex(0.39, -0.0427));
  head_section_4.push_back(Vertex(0.3823, -0.048));

  vector<Vertex> left_eye_top;

  left_eye_top.push_back(Vertex(-0.3888, 0));
  left_eye_top.push_back(Vertex(-0.3432, 0.067));
  left_eye_top.push_back(Vertex(-0.398, 0.033));
  left_eye_top.push_back(Vertex(-0.2957, 0.0614));
  left_eye_top.push_back(Vertex(-0.4157, 0.063));
  left_eye_top.push_back(Vertex(-0.1793, 0.1053));
  left_eye_top.push_back(Vertex(-0.4363, 0.047));
  left_eye_top.push_back(Vertex(-0.2735, 0.1174));
  left_eye_top.push_back(Vertex(-0.162, 0.136));
  left_eye_top.push_back(Vertex(-0.1213, 0));

  vector<Vertex> left_eye_bottom;

  left_eye_bottom.push_back(Vertex(-0.1213, 0));
  left_eye_bottom.push_back(Vertex(-0.107, -0.054));
  left_eye_bottom.push_back(Vertex(-0.1636, -0.2455));
  left_eye_bottom.push_back(Vertex(-0.304, -0.091));
  left_eye_bottom.push_back(Vertex(-0.312, -0.25));
  left_eye_bottom.push_back(Vertex(-0.3493, -0.075));
  left_eye_bottom.push_back(Vertex(-0.4476, -0.1222));
  left_eye_bottom.push_back(Vertex(-0.3706, -0.058));
  left_eye_bottom.push_back(Vertex(-0.4178, -0.0534));
  left_eye_bottom.push_back(Vertex(-0.3888, 0));

  vector<Vertex> right_eye_top;

  right_eye_top.push_back(Vertex(-0.02, -0.0248));
  right_eye_top.push_back(Vertex(-0.014, 0.037));
  right_eye_top.push_back(Vertex(0.0257, 0.0884));
  right_eye_top.push_back(Vertex(0.078, 0.1074));
  right_eye_top.push_back(Vertex(0.147, 0.102));
  right_eye_top.push_back(Vertex(0.2147, 0.106));
  right_eye_top.push_back(Vertex(0.2743, 0.0236));
  right_eye_top.push_back(Vertex(0.2695, -0.0312));

  vector<Vertex> right_eye_bottom;

  right_eye_bottom.push_back(Vertex(-0.02, -0.0248));
  right_eye_bottom.push_back(Vertex(-0.0218, -0.1166));
  right_eye_bottom.push_back(Vertex(0.011, -0.157));
  right_eye_bottom.push_back(Vertex(0.0765, -0.1698));
  right_eye_bottom.push_back(Vertex(0.158, -0.18));
  right_eye_bottom.push_back(Vertex(0.2175, -0.174));
  right_eye_bottom.push_back(Vertex(0.2622, -0.081));
  right_eye_bottom.push_back(Vertex(0.2695, -0.0312));

  vector<Vertex> nose;

  nose.push_back(Vertex(-0.031, -0.198));
  nose.push_back(Vertex(-0.101, -0.261));
  nose.push_back(Vertex(-0.1957, -0.208));
  nose.push_back(Vertex(-0.089, -0.1295));

  vector<Vertex> left_eye_dot;

  left_eye_dot.push_back(Vertex(-0.263, -0.0196));
  left_eye_dot.push_back(Vertex(-0.2416, -0.0452));
  left_eye_dot.push_back(Vertex(-0.2963, -0.0266));
  left_eye_dot.push_back(Vertex(-0.263, -0.0196));

  vector<Vertex> right_eye_dot;

  right_eye_dot.push_back(Vertex(0.1209, -0.0186));
  right_eye_dot.push_back(Vertex(0.1413, -0.0448));
  right_eye_dot.push_back(Vertex(0.0957, -0.03));
  right_eye_dot.push_back(Vertex(0.1209, -0.0186));

  vector<Vertex> right_brow;

  right_brow.push_back(Vertex(0.2364, 0.1057));
  right_brow.push_back(Vertex(0.1593, 0.11));
  right_brow.push_back(Vertex(0.0493, 0.097));
  right_brow.push_back(Vertex(0.0143, 0.139));

  vector<Vertex> left_brow;

  left_brow.push_back(Vertex(-0.162, 0.1304));
  left_brow.push_back(Vertex(-0.268, 0.13));
  left_brow.push_back(Vertex(-0.3264, 0.1144));
  left_brow.push_back(Vertex(-0.362, 0.102));

  vector<Vertex> nose_section_1;

  nose_section_1.push_back(Vertex(-0.089, -0.299));
  nose_section_1.push_back(Vertex(-0.099, -0.3237));
  nose_section_1.push_back(Vertex(-0.11, -0.3474));
  nose_section_1.push_back(Vertex(-0.1277, -0.3825));
  nose_section_1.push_back(Vertex(-0.1173, -0.415));
  nose_section_1.push_back(Vertex(-0.1, -0.415));

  vector<Vertex> nose_section_2;

  nose_section_2.push_back(Vertex(-0.0564, -0.365));
  nose_section_2.push_back(Vertex(-0.079, -0.3784));
  nose_section_2.push_back(Vertex(-0.091, -0.4034));
  nose_section_2.push_back(Vertex(-0.1, -0.415));

  vector<Vertex> nose_section_3;

  nose_section_3.push_back(Vertex(-0.0564, -0.365));
  nose_section_3.push_back(Vertex(-0.058, -0.3983));
  nose_section_3.push_back(Vertex(-0.0477, -0.426));
  nose_section_3.push_back(Vertex(-0.034, -0.439));
  nose_section_3.push_back(Vertex(-0.0122, -0.4407));

  vector<Vertex> nose_section_4;

  nose_section_4.push_back(Vertex(-0.0122, -0.4407));
  nose_section_4.push_back(Vertex(0.009, -0.427));
  nose_section_4.push_back(Vertex(0.008, -0.385));
  nose_section_4.push_back(Vertex(0.0144, -0.344));

  draw_curve(hair_section_1, 10);
  draw_curve(hair_section_2, 10);
  draw_curve(hair_section_3, 10);
  draw_curve(hair_section_4, 10);
  draw_curve(hair_section_5, 10);
  draw_curve(hair_section_6, 10);
  draw_curve(hair_section_7, 10);
  draw_curve(hair_section_8, 10);
  draw_curve(hair_section_9, 10);
  draw_curve(head_section_1, 3);
  draw_curve(head_section_2, 10);
  draw_curve(head_section_3, 10);
  draw_curve(head_section_4, 3);
  draw_curve(left_eye_top, 10);
  draw_curve(left_eye_bottom, 10);
  draw_curve(right_eye_top, 10);
  draw_curve(right_eye_bottom, 10);
  draw_curve(nose, 10);
  draw_curve(left_eye_dot, 10);
  draw_curve(right_eye_dot, 10);
  draw_curve(right_brow, 10);
  draw_curve(left_brow, 10);
  draw_curve(nose_section_1, 10);
  draw_curve(nose_section_2, 10);
  draw_curve(nose_section_3, 10);
  draw_curve(nose_section_4, 10);

  glutSwapBuffers();
}

int main(int argc, char *argv[]) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
  glutInitWindowSize(900, 900);  // Set your own window size
  glutCreateWindow("Assignment 1");
  setup();
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}
