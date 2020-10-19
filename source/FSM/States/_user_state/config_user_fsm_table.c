#include <stdio.h>
#include "../../fsm.h"
#include "../../../queue.h"
#include "config_user_fsm_table.h"




/*Foward Declarations*/



// prototipos
static void do_nothing(void);

/*** tablas de estado ***/

/*** menu ***/


/*** Id ***/

STATE id[]=
{
	{PRESS_EV, id, id_acceptNumber},
	{LKP_EV, id, id_confirmID},
	{ENCODER_RIGHT_EV, id, id_increaseCurrent},
    {ENCODER_LEFT_EV, id, id_decreaseCurrent},
	{CARD_SWIPE_EV, id, id_checkCardID},
	{RETURN_TO_LAST_STATE_EV, menu, showWelcomeAnimation},
	{ID_OK_EV, pin, initPinInput}, //TODO que updetee el display
	{TIMEOUT_EV, menu, showWelcomeAnimation},
	{FIN_TABLA,id,do_nothing},
};

/*** Pin ***/

STATE pin[] =
{
	//{,pin,},	    
	{PRESS_EV,pin, pin_acceptNumber},
	{ENCODER_RIGHT_EV,pin, pin_increaseCurrent}, 
    {ENCODER_LEFT_EV,pin, pin_decreaseCurrent},
	{LKP_EV, pin, pin_confirmPin}, 
	{USR_PIN_OK_EV, usr, initUserMenu},
    {ADMIN_PIN_OK_EV, admin, admin_initAdminMenu},
	{RETURN_TO_LAST_STATE_EV, id, initLogin},
	{FAIL_PIN_EV, fail, initFailState},
	{TIMEOUT_EV, menu, showWelcomeAnimation},
	{FIN_TABLA, pin, do_nothing}
};



//========interfaz=================


STATE *FSM_GetInitState(void)
{
	 return(menu);
}

///=========Rutinas de accion===============
void FMS_StartInitState()
{
	showWelcomeAnimation();
}


/*Dummy function*/
static void do_nothing(void)
{
	//take some time off, relax, and KEEP WORKING ////you lazy ass ALU
}