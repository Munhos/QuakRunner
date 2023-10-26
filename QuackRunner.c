#include <raylib.h>
#include <stdlib.h>
#include <time.h>

void segundaTela()
{
    return DrawRectangle(0.0f, 0.0f, 1920.0f, 1080.0f, RED);
}


main(){
    
    InitWindow(1600,900, "Quack Runner");
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
    
    Texture2D patoCosta1 = LoadTexture("./pato1.png");
    Texture2D patoCosta2 = LoadTexture("./pato2.png");
    
    
    Vector2 posiPlayer = {400, 300};
    int veloPato = 15;
    
    int contadorPatoCosta = 0;
    
    while(!WindowShouldClose()){
        
        bool nenhumaTeclaPressionada = true;

        for (int key = 0; key < 64; key++)
        {
            if (IsKeyDown(key))
            {
                nenhumaTeclaPressionada = false;
                break;
            }
        }

        if (nenhumaTeclaPressionada)
        {
            DrawTextureEx(pato, posiPlayer, 1, 10 , WHITE);
        }
        
        
        if(IsKeyDown(KEY_D)) {
            posiPlayer.x += veloPato;

            if (contadorPatoCosta < 50) {
                DrawTextureEx(patoCosta1, posiPlayer, 0, 0.5, WHITE);
            } else if (contadorPatoCosta < 100) {
                DrawTextureEx(patoCosta2, posiPlayer, 0, 0.09, WHITE);
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
        
            ClearBackground(BLACK); 
            
            Rectangle colisaoInimigo1 = { posInimigoX, posInimigo, 30, 30,};
            if (gerarInimigo == true){
                
                
                DrawRectangle(posInimigoX, posInimigo, 30,30,RED);
                
                if(posInimigoX >=0){
                    posInimigoX -= 20;  //VELOCIDADE INIMIGO'
                    
                    
                }else{
                    gerarInimigo = false;
                }
            }
            
            Rectangle colisaoInimigo2 = { posInimigo2X, posInimigo2, 30, 30,};
            if (gerarInimigo2 == true){
                
                
                DrawRectangle(posInimigo2X, posInimigo2, 30,30,BLUE);
                
                if(posInimigo2X >=0){
                    posInimigo2X -= 30;  //VELOCIDADE INIMIGO
                }else{
                    gerarInimigo2 = false;
                }
            }
            
            Rectangle colisaoInimigo3 = { posInimigo3X, posInimigo3, 30, 30,};
            if (gerarInimigo3 == true){
                
                
                DrawRectangle(posInimigo3X, posInimigo3, 30,30,YELLOW);
                
                if(posInimigo3X >=0){
                    posInimigo3X -= 20;  //VELOCIDADE INIMIGO
                }else{
                    gerarInimigo3 = false;
                }
            }
            
            Rectangle colisaoInimigo4 = { posInimigo4X, posInimigo4, 30, 30,};
            if (gerarInimigo4 == true){
                
                 
                DrawRectangle(posInimigo4X, posInimigo4, 30,30,PURPLE);
                
                if(posInimigo4X >=0){
                    posInimigo4X -= 20;  //VELOCIDADE INIMIGO
                }else{
                    gerarInimigo4 = false;
                }
            }
            
            
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
            }
            
            if(CheckCollisionRecs(colisaoOvo, colisaoInimigo2) == true){
                posInimigo2X = 0;
            }
            
            if(CheckCollisionRecs(colisaoOvo, colisaoInimigo3) == true){
                posInimigo3X = 0;
            }
            
            if(CheckCollisionRecs(colisaoOvo, colisaoInimigo4) == true){
                posInimigo4X = 0;
            }
            
            
            //###################//
            
        EndDrawing();
        
    }
    CloseWindow();
}



