#include "math.h"
#include "unsteady.h"
#include "udf.h"

double r1 = 1.0;
double r2 = 1.0;
double theta = 15 * M_PI / 180;
double omega = 0;   
double lambda = 0.5;       
double T1 = 1.0/2;
double T2 = 1.0/2;
double delta = -1;
double phi = 0;

double dispz(double ds, double x, double t, double T)
{
	double pz;

	pz =  r1 * ds * cos(theta *sin(2 * M_PI / T * t + delta * 2 * M_PI / lambda * x + phi));

	return pz;
}

double dispy(double ds, double x, double t, double T)
{
	double py;

	py = r2 * ds * sin(theta *sin(2 * M_PI / T * t + delta * 2 * M_PI / lambda * x + phi));

	return py;
}

double dispz2(double ds, double x, double t, double T)
{
	double pz;

	pz =  r1 * ds * cos(theta *sin(2 * M_PI / T * t + delta * 2 * M_PI / lambda * x + phi));

	return pz;
}

double dispy2(double ds, double x, double t, double T)
{
	double py;

	py = r2 * ds * sin(theta *sin(-2 * M_PI / T * t + delta * 2 * M_PI / lambda * x + phi));

	return py;
}



DEFINE_GRID_MOTION(fin2, domain, dt, time, dtime)
{
	Thread *tf = DT_THREAD(dt);
	face_t f;
	Node *v;
	int n;
	double current_time;
	double pre_time;
	double xprev,yprev,zprev;
	double ds,dss;
	double y_cur, z_cur;

	double y1, y2, y3, y4, y5, y6, y7, y8, y9;
	double z1, z2, z3, z4, z5, z6, z7, z8, z9;

	SET_DEFORMING_THREAD_FLAG(THREAD_T0(tf));
	begin_f_loop(f, tf)
	{
		f_node_loop(f, tf, n)
		{
			v = F_NODE(f, tf, n);
			if (NODE_POS_NEED_UPDATE(v))
			{
				NODE_POS_UPDATED(v);
				current_time = time;
				pre_time = time-dtime;
	
				xprev = NODE_X(v)-0.6;   
				y1 = NODE_Y(v)+0.145;     
				z1 = -(NODE_Z(v)+0.11);
										
				ds = sqrt(y1*y1 + z1*z1);  

				z_cur = z1 - dispz(ds, xprev, pre_time,T2) + dispz(ds, xprev, current_time,T2);
				y_cur = y1 - dispy(ds, xprev, pre_time,T2) + dispy(ds, xprev, current_time,T2);
				
				dss = sqrt(y_cur * y_cur + z_cur * z_cur);
				if (dss == 0)
				{
					dss = 1;
				}
				y2 = y_cur * ds / dss;
				z2 = z_cur * ds / dss;
				NODE_X(v) = xprev+0.6;
				NODE_Z(v) = -(z2+0.11);
				NODE_Y(v) = y2-0.145;
			}
		}
	}
	end_f_loop(f, tf)
}




DEFINE_GRID_MOTION(fin1, domain, dt, time, dtime)
{
	Thread *tf = DT_THREAD(dt);
	face_t f;
	Node *v;
	int n;
	double current_time;
	double pre_time;
	double xprev,yprev,zprev;
	double ds,dss;
	double y_cur, z_cur;

	double y1, y2, y3, y4, y5, y6, y7, y8, y9;
	double z1, z2, z3, z4, z5, z6, z7, z8, z9;

	SET_DEFORMING_THREAD_FLAG(THREAD_T0(tf));
	begin_f_loop(f, tf)
	{
		f_node_loop(f, tf, n)
		{
			v = F_NODE(f, tf, n);
			if (NODE_POS_NEED_UPDATE(v))
			{
				NODE_POS_UPDATED(v);
				current_time = time;
				pre_time = time-dtime;
	
				xprev = NODE_X(v)-0.6;   
				y1 = NODE_Y(v)+0.145;     
				z1 = NODE_Z(v)-0.11;
										
				ds = sqrt(y1*y1 + z1*z1);  

				z_cur = z1- dispz2(ds, xprev, pre_time,T1) + dispz2(ds, xprev, current_time,T1);
				y_cur = y1 - dispy2(ds, xprev, pre_time,T1) + dispy2(ds, xprev, current_time,T1);
				
				dss = sqrt(y_cur * y_cur + z_cur * z_cur);
				if (dss == 0)
				{
					dss = 1;
				}
				y2 = y_cur * ds / dss;
				z2 = z_cur * ds / dss;
    				


				NODE_X(v) = xprev+0.6;
				NODE_Z(v) = z2+0.11;
				NODE_Y(v) = y2-0.145;
			}
		}
	}
	end_f_loop(f, tf)
}
