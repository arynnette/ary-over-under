// Kalman_Filter_Test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <chrono>
#include "UnscentedKalman.h"
#include "SystemSims.h"

template<int state_dim, int measure_dim>
void UnscentedKalman<state_dim, measure_dim>::unscented_transform_f(Eigen::Matrix<double, 2 * state_dim + 1, state_dim> sigmas)
{
    for (int i = 0; i < state_dim; ++i)
    {
        unscented_x_p[i] = weights_m.dot(sigmas.col(i));
    }
    Eigen::Matrix<double, state_dim, state_dim> temp;
    for (int i = 0; i < sigma_dim; ++i)
    {
        Eigen::Matrix<double, 1, state_dim> Y = sigmas.row(i) - unscented_x_p.transpose();
        auto scalar = (weights_c[i] * (Y * Y.transpose())[0]);
        temp.fill(scalar);
        unscented_P_p = (unscented_P_p + temp);
    }
    unscented_P_p += Q;
}

template<int state_dim, int measure_dim>
void UnscentedKalman<state_dim, measure_dim>::unscented_transform_h(Eigen::Matrix<double, 2 * state_dim + 1, measure_dim> sigmas)
{
    for (int i = 0; i < measure_dim; ++i)
    {
        unscented_x_z[i] = weights_m.dot(sigmas.col(i));
    }
    Eigen::Matrix<double, measure_dim, measure_dim> temp;
    for (int i = 0; i < sigma_dim; ++i)
    {
        Eigen::Matrix<double, 1, measure_dim> Y = sigmas.row(i) - unscented_x_z.transpose();
        auto scalar = (weights_c[i] * (Y * Y.transpose())[0]);
        temp.fill(scalar);
        unscented_P_z += temp;
    }
    unscented_P_z += R;
}

template<int state_dim, int measure_dim>
void UnscentedKalman<state_dim, measure_dim>::predict()
{
    weights_m.fill(1 / (2 * (state_dim + lambda_)));
    weights_c.fill(1 / (2 * (state_dim + lambda_)));
    weights_m(0) = lambda_ / (state_dim + lambda_) + (1 - pow(alpha, 2) + beta);
    weights_c(0) = lambda_ / (state_dim + lambda_);
    Eigen::LLT<Eigen::Matrix<double, state_dim, state_dim>> U((state_dim + lambda_) * covariance_matrix);
    Eigen::Matrix<double, state_dim, state_dim> U_decomposed = U.matrixU();
    sigma_points.row(0) = state_vector;
    for (int i = 0; i < state_dim; ++i)
    {
        sigma_points.row(i + 1) = state_vector.transpose() + U_decomposed.row(i);
        sigma_points.row(state_dim + i + 1) = state_vector.transpose() - U_decomposed.row(i);
    }
    for (int i = 0; i < sigma_dim; ++i)
    {
        sigma_points_f.row(i) = this->predict_function_f(sigma_points.row(i));
    }
    this->unscented_transform_f(sigma_points_f);
    state_vector_p = unscented_x_p;
    covariance_matrix_p = unscented_P_p;
}


template<int state_dim, int measure_dim>
void UnscentedKalman<state_dim, measure_dim>::update(const Eigen::Vector<double, measure_dim> measurements)
{
    for (int i = 0; i < sigma_dim; ++i)
    {
        sigma_points_h.row(i) = this->update_function_h(sigma_points_f.row(i));
    }
    this->unscented_transform_h(sigma_points_h);
    Eigen::Matrix<double, state_dim, measure_dim> covariance_x_z;
    for (int i = 0; i < sigma_dim; ++i)
    {
        auto inner1 = (sigma_points_h.row(i) - unscented_x_z.transpose());
        auto inner2 = (sigma_points_f.row(i) - state_vector_p.transpose());
        auto comp = inner1.transpose() * inner2;
        auto temp = weights_c[i] * comp.transpose();
        covariance_x_z += temp;
    }
    auto K = covariance_x_z * unscented_P_z.inverse();
    state_vector = state_vector_p + K * (measurements - unscented_x_z); 
    covariance_matrix = covariance_matrix_p - (K * unscented_P_z * K.transpose());
}


template<int state_dim, int measure_dim>
Eigen::Vector<double, state_dim> UnscentedKalman<state_dim, measure_dim>::predict_function_f(Eigen::Matrix<double, 1, state_dim> item)
{
    Eigen::Matrix<double, state_dim, state_dim> F = Eigen::Matrix<double, state_dim, state_dim>::Ones();
    return F * item.transpose();
}


template<int state_dim, int measure_dim>
Eigen::Vector<double, measure_dim> UnscentedKalman<state_dim, measure_dim>::update_function_h(Eigen::Matrix<double, 1, state_dim> item)
{
    return { 1, 2, 3 };
}



UnscentedKalman<3, 3> filter;

Eigen::Vector<double, 3> test2 = Eigen::Matrix<double, 1, 3>::Random();
Eigen::Vector<double, 3> test3 = Eigen::Matrix<double, 1, 3>::Random();
Eigen::Vector<double, 3> test4 = Eigen::Matrix<double, 1, 3>::Random();

int main()
{

}


