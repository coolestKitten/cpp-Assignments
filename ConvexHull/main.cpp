#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Point structure. Standard at this point
struct Point{
    double x,y;

    Point(double _x, double _y){
        x = _x; y = _y;
    }
};

// finds the leftmost, bottommost point of a given array
Point findHullStart(vector<Point> points){
    Point p0 = points.front();

    for (int i = 0; i<points.size(); i++){
        // a point is only lower than the others if both its x and y coordinates are lower than the previous selection
        if (points[i].y < p0.y){
            p0 = points[i];
        } else if(points[i].y == p0.y){
            if (points[i].x < p0.x){
                p0 = points[i];
            }
        }
    }

    return p0;
}

// method that finds the polar angle of a point with another point 
double getPolarAngle(Point a, Point b){
    return (atan2(a.y - b.y, a.x - b.x) * 180 / M_PI);
}

// method that calculates the distance between a two points
double calcDistance(Point a, Point b){
    return pow((a.x - b.x),2) + pow((a.y - b.y),2);
}


// method that finds the orientation of three points
int orientation(Point q, Point r, Point p){
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
 
    if (val == 0) return 0;  // collinear
    return (val > 0)? 1: 2; // clock or counterclock wise
}

// method that sorts the point array by polar angle 
vector<Point> sortByAngle(vector<Point> points, Point p0){
    // should start sorting at 1, ignoring the first element
    Point catControl = points.front();

    cout << "p0: {" << p0.x << ", " << p0.y << "} " << endl; 
    for (int i = 1; i < points.size(); i++){
        for(int j = 1; j < points.size() - i; j++){
            // a point is lower than another if its polar angle to p0 is lower
            // if they are the same, the closest one will be picked
                
            if(getPolarAngle(points[j], p0) > getPolarAngle(points[j + 1], p0)){ // angles are different
                
                catControl = points[j];
                points[j] = points[j + 1];
                points[j + 1] = catControl;
            } else if (getPolarAngle(points[j], p0) == getPolarAngle(points[j + 1], p0)){ // angles are identical
                if (calcDistance(p0, points[j]) > calcDistance(p0, points[j+1])){
                    catControl = points[j];
                    points[j] = points[j + 1];
                    points[j + 1] = catControl;
                }
            }
        }

    }


cout << "Ordered array: ";
    for (int i = 1; i<points.size(); i++){
        cout << "{"<< points[i].x << ", " << points[i].y << "} " << getPolarAngle(points[i], points[0]) << " ";

    }
    cout << endl;

    return points;
    
} 

vector<Point> grahamScan(vector<Point> points){
    // hull array containing every point on the hull
    vector <Point> hull;

    // find the start of the hull as the bottommost, leftmost point in the array
    Point p0 = findHullStart(points);

    // find p0 within the array, then place it at the front
    for (int i = 0; i< points.size(); i++){
        if (p0.x == points[i].x && p0.y == points[i].y){
            points[i] = points.front(); // equals points[i] to whatever was at the front
            points[0] = p0; // moves p0 to the front
        }
    }

    // sort the remaining points in the points array
    vector<Point> sortedPoints = sortByAngle(points, p0);   
    hull.push_back(sortedPoints[0]);

    // go throught the array 
    for (int i = 1; i< sortedPoints.size(); i++){
        // while the length of the hull array is greater than two and the orientation ot he current three points is not 1
        while (hull.size() > 2 && orientation(hull[i-2], hull[i-1], sortedPoints[i]) != 1){
            //pop the last element of the hull
            hull.pop_back();
        }
        hull.push_back(sortedPoints[i]);

        //append the current element of points to the hull (outside of while)

        cout << "currentStep: ";
        for (int i = 0; i<hull.size(); i++){
            cout << "{"<< hull[i].x << ", " << hull[i].y << "} ";

        }
        cout << endl;

    }


    return hull;
    
}

bool findInArray(Point target, vector <Point> points){
  for (int i = 0; i< points.size(); i++){
    if (points[i].x == target.x && points[i].y == target.y){
      return true; 
    }
  }
  return false;
}


int main(){
    vector<Point> Points;
    int n;
    double x, y;
    cout << "Cantidad de puntos a comparar: ";
  cin >> n;
  while(cin.fail() || n <= 0){
    cout << "Entrada invalida, intentelo de nuevo" << endl;
    cin.clear();
    cin.ignore(256,'\n');
    cout << "Cantidad de puntos a comparar: ";
    cin >> n;
  }
  for (int i = 0; i<n; i++){
    cout << "x: ";
    cin >> x;
    while(cin.fail()){
      cout << "Entrada invalida, intentelo de nuevo" << endl;
      cin.clear();
      cin.ignore(256,'\n');        
      cout << "x: ";
      cin >> x;
    }
    cout << "y: ";
    cin >> y;
    while(cin.fail()){
      cout << "Entrada invalida, intentelo de nuevo" << endl;
      cin.clear();
      cin.ignore(256,'\n');
      cout << "y: ";
      cin >> y;
    }
    
    while (Points.size() > 0 && findInArray(Point(x,y), Points) == true){
      cout << "El punto introducido ya se encuentra dentro del arreglo" << endl;
          cout << "x: ";
    cin >> x;
    while(cin.fail()){
      cout << "Entrada invalida, intentelo de nuevo" << endl;
      cin.clear();
      cin.ignore(256,'\n');        
      cout << "x: ";
      cin >> x;
    }
    cout << "y: ";
    cin >> y;
    while(cin.fail()){
      cout << "Entrada invalida, intentelo de nuevo" << endl;
      cin.clear();
      cin.ignore(256,'\n');
      cout << "y: ";
      cin >> y;
    }
      
    } 
    Points.push_back(Point(x,y));
    
    
  }
    vector<Point> grahamHull = grahamScan(Points);
    for (int i = 0; i < grahamHull.size(); i++){
        cout << grahamHull[i].x << " " << grahamHull[i].y << endl;
    }
    
    return 0;
}