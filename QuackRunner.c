#include <raylib.h>
#include <stdlib.h>
#include <time.h>

void segundaTela()
{
    DrawRectangle(0.0f, 0.0f, 1920.0f, 1080.0f, RED);
}



void faseGeralJogo(){
    
    SetTargetFPS(60);
    
    
    bool atirar = false;
    Vector2 posiTiro;
    
    bool gerarInimigo;
    gerarInimigo = false;
    
    bool gerarInimigo2;
    gerarInimigo2 = false;
    
    bool gerarInimigo3;
    gerarInimigo2 = false;
    
    bool gerarInimigo4;
    gerarInimigo2 = false;
    
    int rotacaoOvo;
    srand(time(NULL));
    
    Texture2D ovo = LoadTexture("./ovo.png");
    Texture2D pato = LoadTexture("./pato.png");
    
    //--TEXTURA PATO
    Texture2D patoCosta1 = LoadTexture("./pato_andando_a.png");
    Texture2D patoCosta2 = LoadTexture("./pato_andando_b.png");
    Texture2D patoAtirando = LoadTexture("./pato_atirando.png");
    Texture2D patoParado = LoadTexture("./pato_parado.png");
    
    //--TEXTURA INIMIGOS--
    //-AGUIA
    Texture2D aguia1 = LoadTexture("./aguia_voando_a.png");
    Texture2D aguia2 = LoadTexture("./aguia_voando_b.png");
    int constadorAguia = 0;
    //-COBRA
    Texture2D cobra1 = LoadTexture("./cobra_andando_a.png");
    Texture2D cobra2 = LoadTexture("./cobra_andando_b.png");
    int constadorCobra = 0;
    //-GUAXINIM-
    Texture2D guaxinim1 = LoadTexture("./guaxinim_andando_a.png");
    Texture2D guaxinim2 = LoadTexture("./guaxinim_andando_b.png");
    int constadorGuaxinim = 0;
    
    Texture2D fundo = LoadTexture("./fundo.png");
    
    
    Vector2 posiPlayer = {400, 300};
    int veloPato = 8;
    
    int posiFundo1 = 0;
    int posiFundo2 = 1600;
    
    int pontuacao = 0;
    
    int contadorPatoCosta = 0;
    while(!WindowShouldClose()){
        
        
        //DESENHO FUNDO-------------
        
        DrawTexture(fundo, posiFundo1 -= veloPato, 0, WHITE);
        if(posiFundo1 < -1600){
            posiFundo1 = 0;
        }
        DrawTexture(fundo, posiFundo2 -= veloPato, 0, WHITE);
        if(posiFundo2 < 0){
            posiFundo2 = 1600;
        }
        
        
        //--------------------------
        
        bool nenhumaTeclaPressionada = true;
        
        for (int key = 0; key < 64; key++)
        {
            if (IsKeyDown(key))
            {
                nenhumaTeclaPressionada = false;
                break;
            }
            
            if (IsKeyDown(KEY_D)) {
                nenhumaTeclaPressionada = false;
                break;
            }
            
         
        }

        if (nenhumaTeclaPressionada)
        {
            DrawTextureEx(patoParado, posiPlayer, 0, 0.08 , WHITE);
        }
        
        
        if(IsKeyDown(KEY_D)) {
            posiPlayer.x += veloPato;

            if (contadorPatoCosta < 25) {
                DrawTextureEx(patoCosta1, posiPlayer, 0, 0.08, WHITE);
            } else if (contadorPatoCosta < 50) {
                DrawTextureEx(patoCosta2, posiPlayer, 0, 0.08, WHITE);
            } else {
                contadorPatoCosta = 0;
            }
           
            
        }
        
        
        contadorPatoCosta += 1;
        
        if(IsKeyDown(KEY_A)) {
            posiPlayer.x -=veloPato;
        }
        
        if(IsKeyDown(KEY_W)) {
            posiPlayer.y -= veloPato;
        }
        
        if(IsKeyDown(KEY_S)) {
            posiPlayer.y +=veloPato;
        }
        
        //### COLISAO COM PAREDE ###///
        
        if(posiPlayer.x + 70 >= GetScreenWidth()){
            posiPlayer.x -= veloPato;
        }
        
        if(posiPlayer.x <= 0){
            posiPlayer.x += veloPato;
        }
        
        if(posiPlayer.y + 70 >= GetScreenHeight()){
            posiPlayer.y -= veloPato;
        }
        
        if(posiPlayer.y + 10 <= 0){
            posiPlayer.y += veloPato;
        }
        
        //##########################//
        
        
        
        //### ATIRAR ###//
        if(IsKeyPressed(KEY_SPACE) && atirar == false) {
            posiTiro.x = posiPlayer.x;
            posiTiro.y = posiPlayer.y;
            
            Vector2 posiTiro = {posiTiro.x, posiTiro.y};
           
            atirar = true;

        }
        
        if(IsKeyDown(KEY_SPACE)){
            DrawTextureEx(patoAtirando, posiPlayer, 0, 0.08, WHITE);
        }
        //##############//
        
        
        int posInimigo;
        int posInimigoX;
        
        if(gerarInimigo == false){
            
            posInimigo = rand() % 900;
            
            posInimigoX = 1600;  //POSIÇÃO DE SPAWN
            gerarInimigo = true;
        }
        
        int posInimigo2;
        int posInimigo2X;
        
        if(gerarInimigo2 == false){
            
            posInimigo2 = rand() % 900;
            
            posInimigo2X = 1900;  //POSIÇÃO DE SPAWN
            gerarInimigo2 = true;
        }
        
        int posInimigo3;
        int posInimigo3X;
        
        if(gerarInimigo3 == false){
            
            posInimigo3 = rand() % 900;
            
            posInimigo3X = 2200;  //POSIÇÃO DE SPAWN
            gerarInimigo3 = true;
        }
        
        int posInimigo4;
        int posInimigo4X;
        
        if(gerarInimigo4 == false){
            
            posInimigo4 = rand() % 900;
            
            posInimigo4X = 2500;  //POSIÇÃO DE SPAWN
            gerarInimigo4 = true;
        }
        
        //IMAGENS
        
        BeginDrawing();  
            pontuacao += 1;
            char pontuacaoStr[50];
            sprintf(pontuacaoStr, "%d", pontuacao);
            DrawText(pontuacaoStr, 10, 10, 50, WHITE);
        
            ClearBackground(BLACK); 
            
            Rectangle colisaoInimigo1 = { posInimigoX, posInimigo, 30, 30,};
            if (gerarInimigo == true){
                
                
                Vector2 posInimigoAguia = {posInimigoX, posInimigo};
                constadorAguia += 1;
                if (constadorAguia < 15) {
                    DrawTextureEx(aguia1, posInimigoAguia, 0, 0.1, WHITE);
                } else if (constadorAguia < 30) {
                    DrawTextureEx(aguia2, posInimigoAguia, 0, 0.1, WHITE);
                } else {
                    constadorAguia = 0;
                }
                
                if(posInimigoX >=0){
                    posInimigoX -= 20;  //VELOCIDADE INIMIGO'
                    
                    
                }else{
                    gerarInimigo = false;
                }
            }
            
            Rectangle colisaoInimigo2 = { posInimigo2X, posInimigo2, 30, 30,};
            if (gerarInimigo2 == true){
                
                Vector2 posInimigoCobra = {posInimigo2X, posInimigo2};
                constadorCobra += 1;
                if (constadorCobra < 15) {
                    DrawTextureEx(cobra1, posInimigoCobra, 0, 0.1, WHITE);
                } else if (constadorCobra < 30) {
                    DrawTextureEx(cobra2, posInimigoCobra, 0, 0.1, WHITE);
                } else {
                    constadorCobra = 0;
                }
                
                if(posInimigo2X >=0){
                    posInimigo2X -= 5;  //VELOCIDADE INIMIGO
                }else{
                    gerarInimigo2= false;
                }
            }
            
            Rectangle colisaoInimigo3 = { posInimigo3X, posInimigo3, 30, 30,};
            if (gerarInimigo3 == true){
                
                
                Vector2 posInimigoGuaxinim = {posInimigo3X, posInimigo3};
                constadorGuaxinim += 1;
                if (constadorGuaxinim < 15) {
                    DrawTextureEx(guaxinim1, posInimigoGuaxinim, 0, 0.1, WHITE);
                } else if (constadorGuaxinim < 30) {
                    DrawTextureEx(guaxinim2, posInimigoGuaxinim, 0, 0.1, WHITE);
                } else {
                    constadorGuaxinim = 0;
                }
                
                if(posInimigo2X >=0){
                    posInimigo2X -= 20;  //VELOCIDADE INIMIGO
                }else{
                    gerarInimigo2= false;
                }
                
                if(posInimigo3X >=0){
                    posInimigo3X -= 20;  //VELOCIDADE INIMIGO
                }else{
                    gerarInimigo3 = false;
                }
            }
            
            Rectangle colisaoInimigo4 = { posInimigo4X, posInimigo4, 30, 30,};
            /*if (gerarInimigo4 == true){
                
                 
                DrawRectangle(posInimigo4X, posInimigo4, 30,30,PURPLE);
                
                if(posInimigo4X >=0){
                    posInimigo4X -= 20;  //VELOCIDADE INIMIGO
                }else{
                    gerarInimigo4 = false;
                }
            }*/
            
            
            //##DESENHO OVO##//
            
            if(atirar == true){
                DrawText("ATIROU", 100, 100,12, RED);
                
                
                if(posiTiro.x <= 1600){
                    posiTiro.x += 20;
                    rotacaoOvo += 30;
                    DrawTexturePro(ovo, 
                       (Rectangle){ 0, 0, ovo.width, ovo.height }, // Origem da textura (toda a textura)
                       (Rectangle){ posiTiro.x, posiTiro.y, ovo.width * 5.0f, ovo.height * 5.0f }, // Destino e escala
                       (Vector2){ ovo.width * 2.5f, ovo.height * 2.5f }, // Ponto de origem eixo X e Y
                       rotacaoOvo, // Ângulo de rotação
                       WHITE);
                }else{
                    
                    atirar = false;
                }
                

            }
            Rectangle colisaoOvo = {posiTiro.x - 20, posiTiro.y - 20, ovo.width * 5.0f, ovo.height * 5.0f};
           
           
            
            
            
           
            //##DESENHO PATO##//
            
            Rectangle colisaoPato = {posiPlayer.x + 10, posiPlayer.y + 10, 50, 50};
            //################//
            
            //##CHECAR COLISOES##// 
            if(CheckCollisionRecs(colisaoPato, colisaoInimigo1) == true || CheckCollisionRecs(colisaoPato, colisaoInimigo2) == true || CheckCollisionRecs(colisaoPato, colisaoInimigo3) == true || CheckCollisionRecs(colisaoPato, colisaoInimigo4) == true){
                DrawText("COLIDIU COM VERMELHO", 100, 100, 20, RED);
                //CloseWindow();
            }
            
            if(CheckCollisionRecs(colisaoOvo, colisaoInimigo1) == true){
                posInimigoX = 0;
                posiTiro.x = 1600;
            }
            
            if(CheckCollisionRecs(colisaoOvo, colisaoInimigo2) == true){
                posInimigo2X = 0;
                posiTiro.x = 1600;
            }
            
            if(CheckCollisionRecs(colisaoOvo, colisaoInimigo3) == true){
                posInimigo3X = 0;
                posiTiro.x = 1600;
            }
            
            if(CheckCollisionRecs(colisaoOvo, colisaoInimigo4) == true){
                posInimigo4X = 0;
                posiTiro.x = 1600;
            }
            
            
            //###################//
        EndDrawing();
        
    }
    CloseWindow();
}




int main() {

    InitWindow(1600, 900, "QuackRunner");

    while (!WindowShouldClose()) {
        
        telaInicial();
    }

    CloseWindow();

    return 0;
}

void telaInicial(){
    while (!WindowShouldClose()) {
        
        if(IsKeyPressed(KEY_KP_1) || IsKeyPressed(KEY_ONE)) {
            
           menuFases();
            
        }
        
        BeginDrawing();
            DrawRectangle(0,0,1600,900,BLACK);
            DrawText("=======================================================================================", 0, 330, 30, WHITE);
                DrawText("1  - Jogar", 560, 380, 30, LIGHTGRAY);
                DrawText("2  - Créditos", 560, 420, 30, LIGHTGRAY);
                DrawText("3  - Sair", 560, 460, 30, LIGHTGRAY);
                DrawText("=======================================================================================", 0, 510, 30, WHITE);

        EndDrawing();
    }

    CloseWindow();
}

void menuFases(){    //CRIAÇÃO FRONT END DO MENU DE FASES
    while (!WindowShouldClose()) {
        
        
        
        BeginDrawing();
            
            DrawRectangle(0,0,1600,900,BLACK);
                
                DrawRectangle(400, 100, 200, 200, GREEN);
                DrawRectangle(700, 100, 200, 200, GREEN);
                DrawRectangle(1000, 100, 200, 200, GREEN);
                DrawText("FASE 1 - PRESSIONE 1", 560, 380, 30, LIGHTGRAY);
                DrawText("FASE 2 - PRESSIONE 2", 560, 420, 30, LIGHTGRAY);
                DrawText("FASE 3 - PRESSIONE 3", 560, 460, 30, LIGHTGRAY);
                DrawText("VOLTAR - PRESSIONE V", 560, 540, 30, LIGHTGRAY);
                

        EndDrawing();
        
        if(IsKeyPressed(KEY_KP_1) || IsKeyPressed(KEY_ONE)) {
            
           faseGeralJogo();
            
        }
        
        if(IsKeyPressed(KEY_KP_2) || IsKeyPressed(KEY_TWO)) {
            
           faseGeralJogo();
            
        }
        
        if(IsKeyPressed(KEY_KP_3) || IsKeyPressed(KEY_THREE)) {
            
           faseGeralJogo();
            
        }
        
        if(IsKeyPressed(KEY_V)) {
            
           telaInicial();
            
        }
    }

}


