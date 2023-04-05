#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Point {
    int x,y;

};

struct Line {
    Point start, end;

    Line(Point _start, Point _end){
        start = _start;
        end = _end;
    }
};

int orientation(Point p, Point q, Point r){
	int det = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

	if (det == 0){
        return 0;
    } else if (det > 0){
        return 1;
    }

	return 2; 
}

bool checkIfSegment(Point a, Point b, Point c){
    return (b.x <= max(a.x, c.x) && b.x >= min(a.x, c.x) &&
        b.y <= max(a.y, c.y) && b.y >= min(a.y, c.y));
       
}

bool checkIntersection(Point start1, Point end1, Point start2, Point end2){
    int o1 = orientation(start1, end1, start2), o2 = orientation(start1, end1, end2), o3 = orientation(start2, end2, start1), o4 = orientation(start2, start2, end1);
  
    if (o1 != o2 && o3 != o4){
        return true;

    } else if(o1 == 0 && checkIfSegment(start1, start2, end1)){
        return true;

    } else if (o2 == 0 && checkIfSegment(start1, end2, end1)){
        return true;

    } else if (o3 == 0 && checkIfSegment(start2, start1, end2)){
        return true;

    } else if (o4 == 0 && checkIfSegment(start2, end1, end2)){
        return true;

    }
  
    return false; 
}



int main (){
    vector<Line> lines;
    vector<string> labels;
    int n;

    cout << "Cantidad de segmentos: ";
    cin >> n;
    while(cin.fail() || n <= 0){
        cout << "Entrada invalida, intentelo de nuevo" << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cin >> n;
    }
    for (int i = 0; i < n; i++){
        Point a, b;
        cout << "Punto origen: " << endl;
        cout << "x: ";
        cin >>  a.x;
        cout << "y: ";
        cin >> a.y;
        cout << "Punto final: " << endl;
        cout << "x: ";
        cin >> b.x;
        cout << "y: ";
        cin >> b.y;
        Line newLine(a, b);
        lines.push_back(newLine);

    }

    for (int i = 0; i< lines.size() -1; i ++){
    for (int j = i + 1; j < lines.size(); j++){
        cout << "Line " << i << " to line " << j  << " -> " 
        << checkIntersection(lines[j].start, lines[j].end, lines[i].start, lines[i].end) << endl;
    }}

    


    return 0;
}