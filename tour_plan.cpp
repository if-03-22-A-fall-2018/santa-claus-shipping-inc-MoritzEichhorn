#include "tour_plan.h"
#include <string.h>

TourPlan* plan_createTour(ChildDataMgmt *cdm){
  TourPlan* tour_plan = (TourPlan*)malloc(sizeof(TourPlan));
  tour_plan->city_plans = list_create();
  char* city_before = (char*)malloc(128);
  CityPlan* crnt_city_plan;
  ChildData* crnt_child_data;
  ChildPlan* crnt_child_plan;

  Node* crnt_node = cdm_get_sorted_data(cdm);

  while(crnt_node != 0){
    crnt_child_data = ((ChildData*)list_get_data(crnt_node));

    if(strcmp(city_before,crnt_child_data->city) != 0){ // Überprüfung ob das aktuelle Kind in der selben Stadt wohnt wie das Kind zuvor
      crnt_city_plan = (CityPlan*)malloc(sizeof(CityPlan));
      crnt_city_plan->city = crnt_child_data->city;
      crnt_city_plan->child_plans = list_create();
      list_add(tour_plan->city_plans, crnt_city_plan);
    }

    city_before = strcpy(city_before, crnt_child_data->city);
    crnt_child_plan = get_child_data_as_child_plan(crnt_child_data);
    list_add(crnt_city_plan->child_plans, crnt_child_plan);
    tour_plan->total_children++;
    tour_plan->total_presents += crnt_child_plan->presents;
    crnt_node = list_get_next(crnt_node);
  }

  return tour_plan;
}


void plan_print(TourPlan *plan){

}


void plan_delete(TourPlan *plan){
  free(plan);
}

int plan_calc_presents(double goodness){
  if(goodness >= 1){
    return 5;
  }
  else if(goodness >= 0.9){
    return 4;
  }
  else if(goodness >= 0.8){
    return 3;
  }
  else if(goodness >= 0.7){
    return 2;
  }
  else if(goodness >= 0.6){
    return 1;
  }
  else{
    return 0;
  }
}

ChildPlan* get_child_data_as_child_plan(ChildData* child_data){
  ChildPlan* child_plan = (ChildPlan*)malloc(sizeof(ChildPlan));
  child_plan->name = child_data->name;
  child_plan->presents = plan_calc_presents(child_data->goodness);
  return child_plan;
}
