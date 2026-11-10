#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<locale.h>	
struct Players{
	char sdname[50];
	char birthDate[15];
	char club[50];
	char position[30];
	int matches;
	char birthPlace[50];
};
int get_age(const char* birthDate) {
    int day, month, year;
    if (sscanf(birthDate, "%*d.%*d.%d", &year) == 1) {
        return 2026 - year;
    }
    return 0;
}
int main() {
    setlocale(LC_ALL, "Russian");
    struct Players players[10] = {
    {"Иванов", "15.05.2007", "Зенит", "Защитник", 45, "Санкт-Петербург"},
    {"Смирнов", "22.11.2003", "Спартак", "Защитник", 52, "Москва"},
    {"Кузнецов", "10.08.2006", "ЦСКА", "Защитник", 12, "Москва"},
    {"Морозов", "05.05.2008", "Локомотив", "Защитник", 55, "Москва"},
    {"Васильев", "19.07.2007", "Динамо", "Защитник", 41, "Москва"},
    {"Волков", "17.11.2007", "Сочи", "Защитник", 48, "Сочи"},
    {"Соколов", "05.12.2006", "Краснодар", "Защитник", 8, "Краснодар"},
    {"Михайлов", "14.04.2008", "Рубин", "Защитник", 44, "Казань"},
    {"Новиков", "30.01.2008", "Ахмат", "Защитник", 42, "Грозный"},
    {"Федоров", "11.10.2001", "Балтика", "Защитник", 70, "Калининград"}
    };
    printf("--- РЕЗУЛЬТАТЫ ПОИСКА ---\n");
    printf("Условия: Защитники, младше 20 лет, более 40 матчей.\n\n");

    int found = 0;
    for (int i = 0; i < 10; i++) {
        int age = get_age(players[i].birthDate);
        if (strcmp(players[i].position, "Защитник") == 0 &&
            age < 20 &&
            players[i].matches > 40) {

            printf("Фамилия: %s\n", players[i].sdname);
            printf("Дата рождения: %s (Возраст: %d)\n", players[i].birthDate, age);
            printf("Клуб: %s\n", players[i].club);
            printf("Амплуа: %s\n", players[i].position);
            printf("Количество игр: %d\n", players[i].matches);
            printf("Место рождения: %s\n", players[i].birthPlace);
            printf("-----------------------------------\n");
            found++;
        }
    }
    if (found == 0) {
        printf("Игроков, подходящих под условия, не найдено.\n");
    }
    else {
        printf("Всего найдено игроков: %d\n", found);
    }

    return 0;
}