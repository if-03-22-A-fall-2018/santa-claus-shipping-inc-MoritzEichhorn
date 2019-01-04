#include "child_data_mgmt.h"

#ifndef SANTACLAUS_TOURPLAN_H
#define SANTACLAUS_TOURPLAN_H


typedef struct _childPlan {
    const char* name;
    int presents;
} ChildPlan;

typedef struct _cityPlan {
    List *child_plans;
    const char* city;
} CityPlan;

typedef struct _tourPlan {
    List *city_plans;
    int total_children;
    int total_presents;
} TourPlan;

/**
 * Creates a TourPlan structure
 */
TourPlan* plan_createTour(ChildDataMgmt *cdm);

/**
 * Prints the tour plan to the console
 * (hint: check the assignment description for the proper format)
 */
void plan_print(TourPlan *plan);

/**
 * Frees memory allocated by the plan (and its child elements)
 * (hint: some structure contain lists, you already implemented a list cleanup)
 */
void plan_delete(TourPlan *plan);

/**
 * Calculates the number of presents a kid receives based on how well he or she behaved
 * (hint: look at the test case to understand the calculation)
 */
int plan_calc_presents(double goodness);

/**
 * Converts a ChildData into a ChildPlan
 */
ChildPlan* get_child_data_as_child_plan(ChildData* child_data);

#endif //SANTACLAUS_TOURPLAN_H
