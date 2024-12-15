#pragma once

#include <iostream>
#include <fstream>
#include <cmath>
#include "gsl/gsl_integration.h"
#include "gsl/gsl_errno.h"
#include "gsl/gsl_spline.h"
using namespace std;

struct gsl_f_params;

//ofstream foo;

class pure {
private:
    double* v = nullptr;
    double* sig = nullptr;
    char* vc = nullptr;
    char* sc = nullptr;
    int data_size;

    bool from_file = false;

    gsl_interp_accel* acc;
    gsl_spline* spline;
    gsl_integration_workspace* w;

    //gsl_f_params* p;
    double m;

    double a;
    double b;
    double c;
    int N;
    double I;

    double* aa = nullptr;
    double* bb = nullptr;
    double* cc = nullptr;
    int* NN = nullptr;
    double* II = nullptr;

    double T_start;
    double T_end;
    double T_step;

    double vp_start;
    double vp_end;
    double vp_step;
    bool flag_pure;
    bool flag_shift;

    double scale_v;
    double scale_sig;

    double result;
    double error;

    gsl_f_params* p;/////////////////

    //ifstream fin;
public:
    //pure( void );
    pure() {
        w = gsl_integration_workspace_alloc(1000);
    }

    pure(ifstream& fin, double scale_v1, double scale_sig1) {
        //m = 9.1e-28;
        from_file = true;
        //fin.open("Stenke_single_1.txt");

        double e, s;
        int count = 0;

        fin.clear(); // сбросить флаги потока
        fin.seekg(0);
        while (fin >> e >> s) {
            count++;
        }

        data_size = count;
        v = new double[data_size];
        sig = new double[data_size];

        fin.clear(); // сбросить флаги потока
        fin.seekg(0);
        for (int i = 0; i < data_size; i++) {
            fin >> v[i] >> sig[i];

            v[i] = sqrt(v[i] / 13.606) * scale_v1;
            sig[i] = sig[i] / pow(0.53e-8, 2) * scale_sig1;

        }

        fin.close();
        acc = gsl_interp_accel_alloc();
        spline = gsl_spline_alloc(gsl_interp_cspline, data_size);
        //System::Windows::Forms::MessageBox::Show("Неверный формат данных в файле", "Ошибка", System::Windows::Forms::MessageBoxButtons::OK);
        gsl_spline_init(spline, v, sig, data_size);
        //System::Windows::Forms::MessageBox::Show("Неверный формат данных в файле", "Ошибка", System::Windows::Forms::MessageBoxButtons::OK);
        w = gsl_integration_workspace_alloc(1000);
    }

    pure(ifstream& fin) {
        double q, y, e, r, t = 0;
        int count = 0;

        fin.clear(); // сбросить флаги потока
        fin.seekg(0);
        while (fin >> q >> y >> e >> r >> t) {
            count++;
        }

        data_size = count;

        aa = new double[data_size];
        bb = new double[data_size];
        cc = new double[data_size];
        NN = new int[data_size];
        II = new double[data_size];



        fin.clear(); // сбросить флаги потока
        fin.seekg(0);
        for (int i = 0; i < data_size; i++) {
            fin >> aa[i] >> bb[i] >> cc[i] >> NN[i] >> II[i];
        }

        fin.close();
        
        w = gsl_integration_workspace_alloc(1000);

    }

    //double m;
    //void setPars(gsl_f_params* xp) { p = xp; };

    int get_data_size() {
        return data_size;
    }

    void set_gsl_space(gsl_integration_workspace* wo, gsl_interp_accel* acco, gsl_spline* splineo) {
        w = wo;
        acc = acco;
        spline = splineo;
    }

    //void set_formula_params(double a1, double b1, double c1, int N1, double I1) {

    //    a = a1;
    //    b = b1;
    //    c = c1;
    //    N = N1;
    //    I = I1;

    //}

    void set_params(double m1, double T_start1, double T_end1, double T_step1, double vp_start1, double vp_end1, double vp_step1,
        bool flag_pure1, bool flag_shift1,
        gsl_f_params* po/*, ifstream &fin1*/) {
        m = m1;

        T_start = T_start1;
        T_end = T_end1;
        T_step = T_step1;

        vp_start = vp_start1;
        vp_end = vp_end1;
        vp_step = vp_step1;

        p = po;
        flag_pure = flag_pure1;
        flag_shift = flag_shift1;
        //fin = fin1;
    }

    void set_params(double m1, double T_start1, double T_end1, double T_step1, double vp_start1, double vp_end1, double vp_step1,
        bool flag_pure1, bool flag_shift1,
        gsl_f_params* po, double a1, double b1, double c1, int N1, double I1) {
        m = m1;

        T_start = T_start1;
        T_end = T_end1;
        T_step = T_step1;

        vp_start = vp_start1;
        vp_end = vp_end1;
        vp_step = vp_step1;

        p = po;

        a = a1;
        b = b1;
        c = c1;
        N = N1;
        I = I1;

        flag_pure = flag_pure1;
        flag_shift = flag_shift1;
    }


    void rescale(double scale_v1, double scale_sig1) {
        scale_v = scale_v1;
        scale_sig = scale_sig1;

        for (int i = 0; i < data_size; i++) {

            //cout << v[i] << " " << sig[i] << "\n";

            v[i] = sqrt(v[i] / 13.606) * scale_v;
            sig[i] = sig[i] / pow(0.53e-8, 2) * scale_sig;

            //cout << v[i] << " " << sig[i] << "\n";
        }
    }

    //void interpolate() {
    //    //cout << data_size;
    //    gsl_spline_init(spline, v, sig, data_size);
    //    //cout << gsl_spline_eval(spline, 18, acc)<< "jnj";
    //    //cout << "b ";
    //}

    double sigma(double v1) {
        //cout << "c ";
        /*acc = gsl_interp_accel_alloc();
        spline = gsl_spline_alloc(gsl_interp_cspline, data_size);

        gsl_spline_init(spline, v, sig, data_size);*/
        //cout << gsl_spline_eval(spline, v1, acc) << " ";
        if (from_file) {
            return gsl_spline_eval(spline, v1, acc);
        }
        else {
            //double s = 0;
            double u = 0;
            u = v1 * v1 * 13.606 / I - 1;
            //cout << "adfaa";
            return 1e-18 / pow(0.53e-8, 2) * a /*6.3*/ * pow(N, b/*1.20*/) * pow(u / (u + 1), c) * log(u + 1) / (u + 1) * pow(13.606 / I, 2);
        }

        //cout << "b ";
    }

    void out_sigma(ofstream& fout5) {
        double v5 = 0;
        for (double u = 1.; u < 100 * I; u *= pow(10, 0.05)) {
            v5 = sqrt((u + 1) * I / 13.606);
            fout5 << (u + 1) * I << "\t" << sigma(v5) << "\n";
        }
    }

    double maxwell(double v1, double T1, double vp) {
        if (flag_pure) {
            //cout << "jopa";
            return 4. * M_PI * pow(v1, 2) * pow(m / (2. * M_PI * T1), 1.5) * exp(-m * v1 * v1 / (2 * T1));
        }
        else {
            //cout << " koloc";
            return pow(m / (2 * M_PI * T1), 0.5) * v1 / vp * (exp(-m * pow((v1 - vp), 2) / (2 * T1)) - exp(-m * pow((v1 + vp), 2) / (2 * T1)));
        }
    }

    double vs(double v1, void* par);

    void integration(ofstream& fout, bool log_scale, bool log_scale_vp);




    ~pure() {
        if (v != nullptr) delete[] v;
        if (sig != nullptr) delete[] sig;

        //if (aa != nullptr) delete[] aa;
        //if (bb != nullptr) delete[] bb;
        //if (cc != nullptr) delete[] cc;
        //if (NN != nullptr) delete[] NN;
        //if (II != nullptr) delete[] II;

        //if (from_file) {
        //    gsl_spline_free(pure::spline);
        //    gsl_interp_accel_free(pure::acc);
        //}

        gsl_integration_workspace_free(w);

        //fin.close();
    }

};


struct gsl_f_params {
    double T;
    double vp;
    //double m;

    pure* pt_pure;

    //pt_
    //pure.pure(1);

};


double gslClassWrapper(double x, void* pp) {
    gsl_f_params* p = (gsl_f_params*)pp;
    return p->pt_pure->vs(x, p);
}

double scale_of_params(double x, double step, bool log_scale) {
    try {
        if (x < 0) {
            throw "Введены отрицательные числа";
        }
        if (log_scale) {

            if (x == 0) {
                throw "0 не может быть использован при логарифмическом масштабе";
            }
            return x * pow(10, 1 / step);
        }
        else {
            return x + step;
        }
    }

    catch (const char* exeption) {
        System::Windows::Forms::MessageBox::Show(System::Convert::ToString(exeption), "Ошибка", System::Windows::Forms::MessageBoxButtons::OK);
        //cerr << "Error: " << exeption;
    }
}


double pure::vs(double v1, void* par) {
    gsl_f_params* p = (gsl_f_params*)par;

    double T1 = (p->T);
    double vp1 = (p->vp);
    double f = sigma(v1) * v1 * maxwell(v1, T1, vp1);
    return f;
}

void pure::integration(ofstream& fout, bool log_scale_T, bool log_scale_vp) {
    gsl_function F;
    double T = 0;
    double vp = 0;
    p->pt_pure = this;

    F.function = &gslClassWrapper;
    F.params = p;

    if (flag_pure) {
        for (T = T_start; T <= T_end * (1 + 0.001); T = scale_of_params(T, T_step, log_scale_T)) {
            p->T = T / 2. / 13.606;
            p->vp = vp;
            if (from_file) {
                gsl_integration_qag(&F, v[0], v[data_size - 1], 0, 1e-3, 1000, 5, w, &result, &error);
            }
            else {
                gsl_integration_qagiu(&F, sqrt(I / 13.606), 0, 1e-3, 1000, w, &result, &error);
            }
            fout << T << " " << 0 << " " << result * 6.17e-9 << "\n";
        }
        flag_pure = false;
    }
    if (flag_shift) {
        for (vp = vp_start; vp <= vp_end * (1 + 0.001); vp = scale_of_params(vp, vp_step, log_scale_vp)) {
            for (T = T_start; T <= T_end * (1 + 0.001); T = scale_of_params(T, T_step, log_scale_T)) {
                p->T = T / 2. / 13.606;
                p->vp = vp;
                if (from_file) {
                    gsl_integration_qag(&F, v[0], v[data_size - 1], 0, 1e-3, 1000, 5, w, &result, &error);
                }
                else {
                    gsl_integration_qagiu(&F, sqrt(I / 13.606), 0, 1e-3, 1000, w, &result, &error);
                }
                fout << T << " " << vp << " " << result * 6.17e-9 << "\n";
            }
        }
    }
}

