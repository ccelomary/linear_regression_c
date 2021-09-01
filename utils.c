/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elomary <elomary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 15:32:33 by elomary           #+#    #+#             */
/*   Updated: 2021/09/01 15:33:39 by elomary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linear_regression.h"

// y = alpha * x + b
double          linear_function(const t_linear_regression *lrg, double x)
{
    return (lrg->alpha * x + lrg->b);
}

// d(out - pout)^2/dalpha =  2 * (out - pout) * (-Xi)
double                  derivative_with_respect2alpha(const t_linear_regression *regressor,
                            double in, double out)
{
    return (-2 * (out - linear_function(regressor, in)) * in);
}
// d(out - pout)^2/db = 2 * (out - pout) * (-1)
double                  derivative_with_respect2b(const t_linear_regression *regressor,
                            double in, double out)
{
    return (-2 * (out - linear_function(regressor, in)));
}
