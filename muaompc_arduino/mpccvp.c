#include "mpcmtxops.h"
#include "mpccvp.h"


static void mpc_cvp_form_pmetric(struct mpc_pmetric *pmt);
static void mpc_copy_data(struct mpc_term *dest, struct mpc_term *src);

void mpc_cvp_copy_parameters(struct mpc_cvp *cvp, 
                struct mpc_cvp_parameters *parameters) {
    uint32_t i;
    struct mpc_term ctl_par[MPC_PAR_NUM];

    ctl_par[MPC_X_BAR].data = parameters->x_bar;

    for (i=0; i<MPC_PAR_NUM; i++) {
        mpc_copy_data(cvp->par[i], &(ctl_par[i]));
    }
    return;
}

void mpc_cvp_form_problem(struct mpc_cvp *cvp)  {
    uint32_t i, j;
    for (i=0; i<MPC_PMETRIC_NUM; i++) {
        if (cvp->pmetric[i]->fac_num[0] > 0) {
            mpc_cvp_form_pmetric(cvp->pmetric[i]);
        }  /* else: pmetric[i] is constant */
    }
    for (j=0; j<cvp->socc_num[0]; j++) {
        for (i=0; i<MPC_SOCC_PMETRIC_NUM; i++) {
            if (cvp->socc[j]->pmetric[i]->fac_num[0] > 0) {
                mpc_cvp_form_pmetric(cvp->socc[j]->pmetric[i]);
            }
        }
    }
    return;
}

void mpc_cvp_form_pmetric(struct mpc_pmetric *pmt)  {
    uint32_t j;

    mpc_copy_data(pmt->val, pmt->fac0);
    for (j=0; j<pmt->fac_num[0]; j++) {
        mpc_mtx_mul_add(pmt->val->data, pmt->aux->data,
        pmt->fac[j]->data, pmt->par[j]->data,
        pmt->fac[j]->rows, pmt->fac[j]->cols);
    }
    return;
}

void mpc_copy_data(struct mpc_term *dest, struct mpc_term *src)  {
    uint32_t j;
    for (j=0; j<(dest->cols*dest->rows); j++) {
        dest->data[j] = src->data[j];
    }
    return;
}

