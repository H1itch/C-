#include <iostream>
using namespace std;

class Polynomial
{
public:

  int *degCoeff;		// Name of your array (Don't change this)
  int capacity;

    Polynomial ()
  {
    capacity = 500;
    degCoeff = new int[capacity];
    for (int i = 0; i < capacity; i++)
      {
	degCoeff[i] = 0;
      }
  }

  Polynomial (Polynomial const &p)
  {
    capacity = p.capacity;
    degCoeff = new int[capacity];
    for (int i = 0; i < capacity; i++)
      {
	degCoeff[i] = p.degCoeff[i];
      }
  }

  void setCoefficient (int d, int c)
  {
    if (d >= capacity)
      {
	int temp = capacity;
	while (temp < d)
	  {
	    temp = temp * 2;
	  }
	int *newarr = new int[temp];
	for (int i = 0; i < capacity; i++)
	  {
	    newarr[i] = degCoeff[i];
	  }
	for (int i = capacity; i < temp; i++)
	  {
	    newarr[i] = 0;
	  }
	capacity = temp;
	delete[]degCoeff;
	degCoeff = newarr;
      }

    degCoeff[d] = c;

  }

  Polynomial operator+ (Polynomial const &p)
  {
    int m = capacity;
    int n = p.capacity;
    Polynomial ans;
    int i;
    for (i = 0; i < min (m, n); i++)
      {
	ans.setCoefficient (i, degCoeff[i] + p.degCoeff[i]);
      }
    while (i < m)
      {
	ans.setCoefficient (i, degCoeff[i]);
	i++;
      }
    while (i < n)
      {
	ans.setCoefficient (i, p.degCoeff[i]);
	i++;
      }
    return ans;
  }

  Polynomial operator- (Polynomial const &p)
  {
    int m = capacity;
    int n = p.capacity;
    Polynomial ans;
    int i;
    for (i = 0; i < min (m, n); i++)
      {
	ans.setCoefficient (i, degCoeff[i] - p.degCoeff[i]);
      }
    while (i < m)
      {
	ans.setCoefficient (i, degCoeff[i]);
	i++;
      }
    while (i < n)
      {
	ans.setCoefficient (i, p.degCoeff[i]);
	i++;
      }
    return ans;
  }

  Polynomial operator* (Polynomial const &p)
  {
    int m = capacity;
    int n = p.capacity;
    Polynomial ans;
    for (int i = 0; i < m; i++)
      {
	for (int j = 0; j < n; j++)
	  {
	    ans.degCoeff[i + j] += degCoeff[i] * p.degCoeff[j];
	  }
      }
    return ans;
  }

  void operator= (Polynomial const &p)
  {
    capacity = p.capacity;
    delete[]degCoeff;
    degCoeff = new int[capacity];
    for (int i = 0; i < capacity; i++)
      {
	degCoeff[i] = p.degCoeff[i];
      }
  }

  void print ()
  {
    for (int i = 0; i < capacity; i++)
      {
	if (degCoeff[i] != 0)
	  {
	    cout << degCoeff[i] << "x" << i << " ";
	  }
      }
    cout << endl;
  }



  // Complete the class

};





int
main ()
{
  int count1, count2, choice;
  cin >> count1;

  int *degree1 = new int[count1];
  int *coeff1 = new int[count1];

  for (int i = 0; i < count1; i++)
    {
      cin >> degree1[i];
    }

  for (int i = 0; i < count1; i++)
    {
      cin >> coeff1[i];
    }

  Polynomial first;
  for (int i = 0; i < count1; i++)
    {
      first.setCoefficient (degree1[i], coeff1[i]);
    }

  cin >> count2;

  int *degree2 = new int[count2];
  int *coeff2 = new int[count2];

  for (int i = 0; i < count2; i++)
    {
      cin >> degree2[i];
    }

  for (int i = 0; i < count2; i++)
    {
      cin >> coeff2[i];
    }

  Polynomial second;
  for (int i = 0; i < count2; i++)
    {
      second.setCoefficient (degree2[i], coeff2[i]);
    }

  cin >> choice;

  Polynomial result;
  switch (choice)
    {
      // Add
    case 1:
      result = first + second;
      result.print ();
      break;
      // Subtract
    case 2:
      result = first - second;
      result.print ();
      break;
      // Multiply
    case 3:
      result = first * second;
      result.print ();
      break;

    case 4:			// Copy constructor
      {
	Polynomial third (first);
	if (third.degCoeff == first.degCoeff)
	  {
	    cout << "false" << endl;
	  }
	else
	  {
	    cout << "true" << endl;
	  }
	break;
      }

    case 5:			// Copy assignment operator
      {
	Polynomial fourth (first);
	if (fourth.degCoeff == first.degCoeff)
	  {
	    cout << "false" << endl;
	  }
	else
	  {
	    cout << "true" << endl;
	  }
	break;
      }

    }

  return 0;
}
