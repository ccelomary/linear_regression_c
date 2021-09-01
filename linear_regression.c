/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linear_regression.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elomary <elomary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 23:14:42 by elomary           #+#    #+#             */
/*   Updated: 2021/09/02 00:17:10 by elomary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linear_regression.h"

t_linear_regression     init_linear_regression(double learning_rate, size_t epoch)
{
    t_linear_regression     lrg;

    lrg.alpha = 0.0;// (rand() % 1000) / 1000.0;
    lrg.b = 0.0 ;//(rand() % 1000) / 1000.0;
    lrg.epoch = epoch;
    lrg.learning_rate = learning_rate;
    return (lrg);
}

void                    train_linear_regression(t_linear_regression *lrg, double *input,
                             double *output, size_t len_in_out)
{
    size_t      train_index;
    double      sum_derv_alpha;
    double      sum_derv_b;
    size_t      index;

    train_index = 0;
    while (train_index < lrg->epoch)
    {
        sum_derv_alpha = 0;
        sum_derv_b = 0;
        index = 0;
        while (index < len_in_out)
        {
            sum_derv_alpha += derivative_with_respect2alpha(lrg, input[index], output[index]) / len_in_out;
            sum_derv_b += derivative_with_respect2b(lrg, input[index], output[index]) / len_in_out;
            index++;
        }
        lrg->alpha -= lrg->learning_rate * sum_derv_alpha;
        lrg->b -= lrg->learning_rate  * sum_derv_b;
        train_index++;
    }
}

double      predict_linear_regression(t_linear_regression trained_regressor, double x)
{
    return (trained_regressor.alpha * x + trained_regressor.b);
}