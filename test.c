#include <stdio.h>
#include <stdbool.h>

int formulaActualDamage(float attackPower, float multiplier) {
    int actualDamage = (int)(attackPower * multiplier);
    return actualDamage;
}

float formulaAttackMultiplier(int currentLearningPoints) {
    float attackMultiplier = 0.5f + (currentLearningPoints / 100.0f);
    return attackMultiplier;
}

float formulaHpMultiplier(int currentLearningPoints) {
    float hpMultiplier = 2.0f - (currentLearningPoints / 100.0f);
    return hpMultiplier;
}

int formulaElsaHPTotal(int ELSA_BASE_HP, float hpMultiplier) {
    int elsaHP = (int)(ELSA_BASE_HP * hpMultiplier);
    return elsaHP;
}
int formulaElsaDamageDasar(int turnCount,int baseDamage, float damageMultiplier){1
    int damage = (int)((baseDamage + (turnCount * 5)) * damageMultiplier);
    return damage;

}

float formulaElsaDamageMultiplier(int currentLearningPoints) {
    float damageMultiplier = 1.5f - (currentLearningPoints / 200.0f);
    return damageMultiplier;
}

int scoringFormula(int damageDealt, int turnsSurvived,int damageReceived) {
    float damageScore = damageDealt * 100 / 200;
    float survivalScore = turnsSurvived * 100 / 10;
    float healthScore = (1.0f - ((float)damageReceived / (100.0f * turnsSurvived))) * 100.0f;
    int learningPoints = (int)( 0.4 * damageScore + 0.3 * survivalScore + 0.3 *  healthScore);
    printf("%f %f %f ",damageScore,survivalScore,healthScore);   
    printf("Learning Points: %d\n", learningPoints);
    return learningPoints;
    
}

void main() {
    float elsaMultiplier, elsaHPMultiplier;
    int damageBaseSubaru = 0; 
    int currentLearningPoints = 0;
    int elsaBaseDamage = 0;
    char action[10]; // Mengubah action menjadi array karakter untuk menerima string
    int HpSubaru = 100;
    int hpElsaBase = 200;
    int round = 1;
    char message[100];

    currentLearningPoints = 10;
    float learningPointsAverage = 0;

    for (int i = 1; i <= 10; i++) {
        printf("=== Return by Death Battle Simulator === \n");
        printf("Subaru vs Elsa Granhiert \n");
        printf("[Death Loop #%d]\n", i);
        int arrayDamage[100];
        int damageDealt = 0;
        int damageReceived = 0 ; 
        bool isAlive = true;
        bool elsaAlive = true;

        int turnsSurvived = 1 ; 
        int tempHPSubaru = HpSubaru;
        float elsaHpMultiplier = formulaHpMultiplier(currentLearningPoints);
        int tempHPElsa = formulaElsaHPTotal(hpElsaBase, elsaHpMultiplier) ;

        printf("Elsa's HP Multiplier: %.2fx (Learning Points: %d)\n", elsaHpMultiplier, currentLearningPoints);
        while (tempHPElsa > 0 && round < 10 && isAlive && elsaAlive) {
            float multiplier = formulaAttackMultiplier(currentLearningPoints);
            printf("\n Subaru's HP: %d | Elsa HP: %d \n", tempHPSubaru, tempHPElsa);
            printf("Pilih Aksi \n");
            printf("A: Serang \nD: Menghindar \nR: Kabur (Reset ke checkpoint) \n");

            printf("Pilihan: ");
            scanf("%s", action);
            if(action[0] == 'R'){
                printf("Kabur! Reset ke checkpoint\n");
                break;
            }
            if(action[0] == 'D'){
                printf("Subaru menghindar!\n");
                continue;
            }
            else{
                printf("Masukkan kekuatan serangan (0-100): ");
                scanf("%d", &damageBaseSubaru);

              

                int actualDamage = formulaActualDamage(damageBaseSubaru, multiplier);
                printf("Subaru menyerang! Base: %d, Actual: %d (x%.2f)\n", damageBaseSubaru, actualDamage, multiplier);

                printf("Elsa menyerang! Damage: ");
                scanf("%d", &elsaBaseDamage);
                float elsaMultiplier = formulaElsaDamageMultiplier(currentLearningPoints);

                printf("Elsa menyerang! Damage: %d (x%.2f multiplier)\n", elsaBaseDamage, elsaMultiplier);
                tempHPSubaru -= elsaBaseDamage;
                tempHPElsa -= actualDamage;
                if (tempHPSubaru <= 0) {
                    isAlive = false;
                    arrayDamage[turnsSurvived-1] = actualDamage;
                    damageReceived += elsaBaseDamage;
                   
                    break;
                }
                else if(tempHPElsa <= 0){
                    
                    printf("Elsa telah dikalahkan! \n");
                    arrayDamage[turnsSurvived-1] = actualDamage;
                    damageReceived += elsaBaseDamage;
                    elsaAlive = false;
                    break;
                }
                else{
                    arrayDamage[turnsSurvived-1] = actualDamage;
                    damageReceived += elsaBaseDamage;
                    turnsSurvived++;
                }
            }

        }
        for(int j = 0; j < turnsSurvived; j++){
            int damage = arrayDamage[j];
            damageDealt += damage;
          
        }
        printf("damage dealt : %d turns survived : %d damage rev: %d  \n", damageDealt,turnsSurvived,damageReceived);
        currentLearningPoints = scoringFormula(damageDealt, turnsSurvived,damageReceived);
        learningPointsAverage += currentLearningPoints;
        if(!elsaAlive){
            printf("SUBARU BERHASIL MENGALAHKAN ELSA! \n");
            printf("=== Analisis Return by Death === \n");
            printf("Total Loop Kematian: %d\n", i);
            float average = learningPointsAverage/i;
            printf("Total Learning Points: %f\n", average);
            if(average >= 85){
                printf("Pemahaman Subaru tentang Elsa: Sempurna (Memahami sebagian besar pola)");
            }
            else if(average >= 70){
                printf("Pemahaman Subaru tentang Elsa: Tinggi (Memahami sebagian pola)");
            }
            else if (average >= 55){
                printf("Pemahaman Subaru tentang Elsa: Sedang (Mulai memahami pola dasar)");
            }
            else if(average >= 40){
                printf("Pemahaman Subaru tentang Elsa: Rendah (Masih banyak yang belum dipahami)");
            }
            else{
                printf("Pemahaman Subaru tentang Elsa: Sangat (Belum memahami pola)");
            }
           break;
        }
       

       
    }
}