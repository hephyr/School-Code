class PCBCGSolver{//定义一个类
 public: 
  int N;
  unsigned long *ija;
  double *sa;

  PCBCGSolver(int nonzeroelement){//？？
    ija = new unsigned long[nonzeroelement+2];
    sa = new double[nonzeroelement+2];
  }
  virtual ~PCBCGSolver(){//定义方法
    delete [] ija;
    delete [] sa;
  }
  void linbcg(unsigned long n, double b[], double x[], int itol, double tol,int itmax, int *iter, double *err);
  
 private://私有，声明方法
  PCBCGSolver(const PCBCGSolver& rhs);
  const PCBCGSolver &operator=(const PCBCGSolver& rhs);
  void dsprsax(double sa[], unsigned long ija[], double x[], double b[], unsigned long n);
  void asolve(unsigned long n, double b[], double x[], int itrnsp);
  void atimes(unsigned long n, double x[], double r[], int itrnsp);
  void dsprstx(double sa[], unsigned long ija[], double x[], double b[], unsigned long n);
  double snrm(unsigned long n, double sx[], int itol);
  

};

