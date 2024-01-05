#pragma once

#include <Eigen/Dense>
#include <Eigen/src/Cholesky/LLT.h>
#include <Eigen/src/Core/Matrix.h>

template<int state_dim, int measure_dim>
class UnscentedKalman
{
public:
    void predict();
    void update(const Eigen::Vector<double, measure_dim> measurements);
    Eigen::Vector<double, state_dim> predict_function_f(Eigen::Matrix<double, 1, state_dim> item); //build this last
    Eigen::Vector<double, measure_dim> update_function_h(Eigen::Matrix<double, 1, state_dim> item); //build this last
    void unscented_transform_f(Eigen::Matrix<double, 2 * state_dim + 1, state_dim> sigmas); //Add spot for Q and R matricies
    void unscented_transform_h(Eigen::Matrix<double, 2 * state_dim + 1, measure_dim> sigmas);
    const Eigen::Vector<double, state_dim> get_state() { return state_vector; }
    const Eigen::Matrix<double, state_dim, state_dim> get_covar() { return covariance_matrix; }
    const Eigen::Vector<double, state_dim> get_state_p() { return state_vector_p; }
    const Eigen::Matrix<double, state_dim, state_dim> get_covar_p() { return covariance_matrix_p; }
private:
    static const int sigma_dim = 2 * state_dim + 1;
    const double kappa = 3 - state_dim;
    const double alpha = 1;
    const double beta = 2;
    const double lambda_ = pow(alpha, 2) * (state_dim - kappa) - state_dim;
    Eigen::Matrix<double, 1, sigma_dim> weights_m;
    Eigen::Matrix<double, 1, sigma_dim> weights_c;
    Eigen::Vector<double, state_dim> state_vector = Eigen::Vector<double, state_dim>::Ones();
    Eigen::Matrix<double, state_dim, state_dim> covariance_matrix = Eigen::Matrix<double, state_dim, state_dim>::Identity();
    Eigen::Vector<double, state_dim> state_vector_p = Eigen::Vector<double, state_dim>::Ones();
    Eigen::Matrix<double, state_dim, state_dim> covariance_matrix_p = Eigen::Matrix<double, state_dim, state_dim>::Identity();
    Eigen::Matrix<double, sigma_dim, state_dim> sigma_points = Eigen::Matrix<double, sigma_dim, state_dim>::Ones();
    Eigen::Matrix<double, sigma_dim, state_dim> sigma_points_f = Eigen::Matrix<double, sigma_dim, state_dim>::Ones();
    Eigen::Matrix<double, sigma_dim, measure_dim> sigma_points_h = Eigen::Matrix<double, sigma_dim, measure_dim>::Ones();
    Eigen::Vector<double, state_dim> unscented_x_p = Eigen::Vector<double, state_dim>::Ones();
    Eigen::Matrix<double, state_dim, state_dim> unscented_P_p = Eigen::Matrix<double, state_dim, state_dim>::Ones();
    Eigen::Vector<double, measure_dim> unscented_x_z = Eigen::Vector<double, measure_dim>::Ones();
    Eigen::Matrix<double, measure_dim, measure_dim> unscented_P_z = Eigen::Matrix<double, measure_dim, measure_dim>::Ones();
    Eigen::Vector<double, measure_dim> measure_vector = Eigen::Vector<double, measure_dim>::Ones();
    Eigen::Matrix<double, state_dim, state_dim> Q = Eigen::Matrix<double, state_dim, state_dim>::Random();
    Eigen::Matrix<double, measure_dim, measure_dim> R = Eigen::Matrix<double, measure_dim, measure_dim>::Random();

};
