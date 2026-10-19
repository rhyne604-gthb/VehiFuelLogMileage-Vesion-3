#include <stdio.h>

// ============================================================================
// MEMBER 1: UI & MENU DISPLAY FUNCTIONS
// ============================================================================
void display_header(void) {
    printf("=============================================\n");
    printf("   VEHICLE FUEL AND MILEAGE CHECKING SYSTEM  \n");
    printf("=============================================\n");
}

void display_menu(void) {
    printf("1.  Log a fill-up\n");
    printf("2.  Mileage report\n");
    printf("3.  Best and worst tank\n");
    printf("4.  Cost per kilometre\n");
    printf("5.  Monthly spend\n");
    printf("6.  Save & load\n");
    printf("0.  Exit\n");
    printf("---------------------------------------------\n");
}

// ============================================================================
// MEMBER 2: DATA INPUT FUNCTIONS
// ============================================================================
void input_fill_up_record(int *fill_up_no, int *prev_odometer, int *odometer, double *litres, double *price) {
    printf("\nEnter fill_up number              :");
    scanf("%d", fill_up_no);
    printf("Enter previous odometer reading(km):");
    scanf("%d", prev_odometer);
    printf("Enter current odometer reading(km):");
    scanf("%d", odometer);
    printf("Enter fuel added (litres)         :");
    scanf("%lf", litres);
    printf("Enter price per litre             :");
    scanf("%lf", price);
}

// ============================================================================
// MEMBER 3 (YOUR PART): MATH & CALCULATION LOGIC
// ============================================================================
int calculate_distance(int prev_odometer, int current_odometer) {
    return current_odometer - prev_odometer;
}

double calculate_cost(double litres, double price_per_litre) {
    return litres * price_per_litre;
}

double calculate_mileage(int distance, double litres) {
    if (litres <= 0.0) {
        return 0.0; // Guard clause against division by zero
    }
    return (double)distance / litres;
}

double calculate_overall_cost_per_km(double total_cost, int total_distance) {
    if (total_distance <= 0) {
        return 0.0; // Guard clause against division by zero
    }
    return total_cost / total_distance;
}

// ============================================================================
// MEMBER 4: OUTPUT FORMATTING & REPORT DISPLAY
// ============================================================================
void print_report(int fill_no1, int odo1, double lit1, double prc1, int dist1, double cost1, double mil1,
                  int fill_no2, int odo2, double lit2, double prc2, int dist2, double cost2, double mil2,
                  int fill_no3, int odo3, double lit3, double prc3, int dist3, double cost3, double mil3,
                  double cost_per_km) {
    
    printf("\n---------------------------------------------\n");
    printf("                    [REPORT]               \n");
    printf("---------------------------------------------\n");
    printf("NO  ODOMETER   LITRES   PRICE     DISTANCE   COST       MILEAGE \n");
    printf("%d.  %-10d %-8.2f %-9.2f %-10d %-10.2f %.2f \n", fill_no1, odo1, lit1, prc1, dist1, cost1, mil1);
    printf("%d.  %-10d %-8.2f %-9.2f %-10d %-10.2f %.2f \n", fill_no2, odo2, lit2, prc2, dist2, cost2, mil2);
    printf("%d.  %-10d %-8.2f %-9.2f %-10d %-10.2f %.2f \n", fill_no3, odo3, lit3, prc3, dist3, cost3, mil3);
    printf("----------------------------------------------\n");
    printf("Cost_per_km   : %.2f \n", cost_per_km);
    printf("Total fill up : 3 \n");
}

// ============================================================================
// MAIN ASSEMBLY FUNCTION
// ============================================================================
int main(void) {
    // Variables for Record 1
    int fill_up_no1, previous_odometer1, odometer1, distance1;
    double litres1, price1, mileage1, cost1;

    // Variables for Record 2
    int fill_up_no2, previous_odometer2, odometer2, distance2;
    double litres2, price2, mileage2, cost2;

    // Variables for Record 3
    int fill_up_no3, previous_odometer3, odometer3, distance3;
    double litres3, price3, mileage3, cost3;

    double total_cost, total_distance, cost_Per_Km;

    // 1. UI Display
    display_header();
    display_menu();

    // 2. Inputs (Member 2's function called 3 times)
    input_fill_up_record(&fill_up_no1, &previous_odometer1, &odometer1, &litres1, &price1);
    input_fill_up_record(&fill_up_no2, &previous_odometer2, &odometer2, &litres2, &price2);
    input_fill_up_record(&fill_up_no3, &previous_odometer3, &odometer3, &litres3, &price3);

    // 3. Calculations (Member 3's functions called)
    distance1 = calculate_distance(previous_odometer1, odometer1);
    cost1     = calculate_cost(litres1, price1);
    mileage1  = calculate_mileage(distance1, litres1);

    distance2 = calculate_distance(previous_odometer2, odometer2);
    cost2     = calculate_cost(litres2, price2);
    mileage2  = calculate_mileage(distance2, litres2);

    distance3 = calculate_distance(previous_odometer3, odometer3);
    cost3     = calculate_cost(litres3, price3);
    mileage3  = calculate_mileage(distance3, litres3);

    total_cost     = cost1 + cost2 + cost3;
    total_distance = distance1 + distance2 + distance3;
    cost_Per_Km    = calculate_overall_cost_per_km(total_cost, (int)total_distance);

    // 4. Output Display
    print_report(fill_up_no1, odometer1, litres1, price1, distance1, cost1, mileage1,
                 fill_up_no2, odometer2, litres2, price2, distance2, cost2, mileage2,
                 fill_up_no3, odometer3, litres3, price3, distance3, cost3, mileage3,
                 cost_Per_Km);

    return 0;
}
