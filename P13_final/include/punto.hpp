class punto
{
private:
    int x_;
    int y_;
public:
    punto(int x, int y);
    punto();
    ~punto();
    int get_x();
    int get_y();
    void set_x(int v);
    void set_y(int v);
    void write();
    punto multiplicarx2(int a, int p);
    punto sumar(punto otropunto, int p);

    punto& operator = (punto n);
    bool operator==(punto& n) const;
};