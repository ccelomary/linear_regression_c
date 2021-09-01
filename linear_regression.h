/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linear_regression.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elomary <elomary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 23:14:17 by elomary           #+#    #+#             */
/*   Updated: 2021/09/01 18:08:03 by elomary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINEAR_REGRESSION_H
# define LINEAR_REGRESSION_H

# include <sys/types.h> // size_t
# include <stdlib.h>
# include <math.h>
// y = alpha * x + b
typedef struct s_linear_regression
{
    double         alpha;
    double          b;
    double          learning_rate;
    size_t          epoch;
}               t_linear_regression;

t_linear_regression     init_linear_regression(double learning_rate, size_t epoch);
void                    train_linear_regression(t_linear_regression *lrg, double *input,
                                    double *output, size_t  len_in_out);
double                  predict_linear_regression(const t_linear_regression trined, double x);
// utils functions
double linear_function(const t_linear_regression *lrg, double x);
double                  derivative_with_respect2alpha(const t_linear_regression *regressor,
                            double in, double out);
double                  derivative_with_respect2b(const t_linear_regression *regressor,
                            double in, double out);
#endif