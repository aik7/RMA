#include "utilRMA.h"


// get the double infinity value
double getInf() {
 return std::numeric_limits<double>::infinity();
}


// get the integer inifinitiy value
int getIntInf() {
 return std::numeric_limits<int>::max();
}


// for 1D deque ooutput
template<class T>
ostream &operator<<(ostream &os, const deque<T> &v) {
  os << "(";
  for (typename deque<T>::const_iterator i = v.begin(); i != v.end(); ++i)
    os << " " << *i;
  os << " )\n";
  return os;
}
template ostream &operator<< <bool>(ostream &os, const deque<bool> &v);


// for 1D set output
template<class T>
ostream &operator<<(ostream &os, const set<T> &v) {
  os << "(";
  for (typename set<T>::const_iterator i = v.begin(); i != v.end(); ++i)
    os << " " << *i;
  os << " )\n";
  return os;
}


// for 2D vector output
template<class T>
ostream &operator<<(ostream &os, const vector<vector<T> > &v) {
  for (unsigned int i = 0; i < v.size(); ++i) {
    os << "(";
    for (unsigned int j = 0; j < v[i].size(); ++j)
      os << v[i][j] << " ";
    os << " )\n";
  }
  return os;
}

template ostream &operator<< <unsigned int>(ostream &os,
                 const vector<vector<unsigned int> > &v);
template ostream &operator<< <double>(ostream &os,
                 const vector<vector<double> > &v);


// ostream &operator<<(ostream &os, const deque<bool> &v) {
//   os << "(";
//   for (deque<bool>::const_iterator i = v.begin(); i != v.end(); ++i)
//     os << " " << *i;
//   os << " )\n";
//   return os;
// }

// ostream &operator<<(ostream &os, const vector<double> &v) {
//   os << "(";
//   for (vector<double>::const_iterator i = v.begin(); i != v.end(); ++i)
//     os << " " << *i;
//   os << " )\n";
//   return os;
// }
//
// ostream &operator<<(ostream &os, const vector<vector<int>> &v) {
//   for (unsigned int i = 0; i < v.size(); ++i) {
//     os << "(";
//     for (unsigned int j = 0; j < v[i].size(); ++j)
//       os << v[i][j] << " ";
//     os << " )\n";
//   }
//   return os;
// }

// ostream &operator<<(ostream &os, const vector<vector<double>> &v) {
//   for (unsigned int i = 0; i < v.size(); ++i) {
//     os << "(";
//     for (unsigned int j = 0; j < v[i].size(); ++j)
//       os << v[i][j] << " ";
//     os << " )\n";
//   }
//   return os;
// }
