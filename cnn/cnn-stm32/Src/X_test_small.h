#pragma once
const int N_SAMPLES = 3;
float X_test[3][1024] = {
{15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15.2,15. ,15. ,15.5,16.6,15. ,15. ,15. ,15.3,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15.6,16. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,16.2,16. ,15. ,15.3,16.4,16.2,16.5,17.5,16.2,15.1,15.4,15.4,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,18. ,17.3,15.5,19. ,17.6,17.2,19.1,18.6,15.2,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,17.5,18.5,16.9,17.9,17.8,18.7,19.7,18.5,16.2,15.2,17.5,18.1,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,16.8,18.2,18. ,17.1,17.5,18. ,19.5,19.3,16.3,15.4,18.3,19.2,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15.1,17.5,16.3,16.2,17.2,16.9,18.1,18. ,15.1,16.2,17.9,18.4,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15.5,15.6,15.4,16.4,16.9,16.4,17.4,16.2,16. ,17.3,16.4,15. ,16.8,17.5,17.8,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,20.5,19.6,17.8,16.1,18.1,18.4,15.5,15.6,16.2,15.3,16.3,15. ,15. ,16.9,17.7,17.9,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15.4,19.7,18.7,17.5,16.3,18.4,18.4,15. ,15.7,15. ,15.2,15.1,15. ,15. ,16.2,19.4,20.4,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15.5,16.2,17.1,16.5,16.9,17.7,16.6,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,19.6,21.2,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15.1,16. ,16.4,15.1,15. ,15.7,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15.6,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,18.1,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15.2,17.5,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,16.3,17.1,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15.7,16.4,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,16.3,16.5,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15.1,16. ,17.9,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15.2,16.7,19.6,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,16.2,17.6,18. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15.3,15.7,16.9,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15.3,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15.5,15. ,15.1,15. },{15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15.2,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15.7,15.4,15. ,16.3,15. ,15. ,15. ,16.2,15.8,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15.1,18.3,15.9,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15.1,15. ,15. ,15.5,15. ,15. ,15. ,15. ,15. ,15. ,15. ,17.7,16.5,15. ,15. ,15. ,17.2,15. ,15. ,15. ,15. ,16.1,19.3,17.3,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15.2,15. ,15. ,15.8,15. ,15.1,15. ,15.2,15. ,15. ,15. ,16. ,15.4,15. ,15. ,15.9,19.6,15.6,15. ,15. ,15. ,16. ,17.9,17.5,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15.1,15. ,15. ,15.7,15. ,15. ,15.2,15.5,16.8,16. ,15. ,15. ,16. ,17.1,15. ,15. ,15. ,15. ,16.6,17.8,16.9,15.3,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15.5,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,17.9,17.3,15.3,15. ,16.3,16.9,15.2,15. ,15. ,15. ,15.6,18.1,17. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15.3,15. ,15. ,15. ,15. ,15. ,15.3,15.5,15. ,15. ,18.9,18.5,17.2,15. ,16.1,16.8,15.5,15. ,15. ,15. ,15.6,17.1,16.6,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15.3,15. ,15. ,15. ,15.2,15. ,15. ,15. ,15.3,15. ,15. ,18.6,18.1,16.2,15. ,16.1,16.5,15. ,15. ,15. ,15. ,15.1,18. ,17.1,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,18.9,18.3,16.2,15. ,15.5,16.5,15. ,15. ,15. ,15. ,15. ,16.3,16.2,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15.5,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,18.8,18.2,16.4,15.6,15.9,16.8,15.7,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15.2,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15.8,15. ,15. ,16.8,18.1,17.5,16.4,15.8,16. ,15.3,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15.5,15. ,15. ,15. ,15.3,15.3,15. ,15.3,15.1,15.1,15. ,15.3,15. ,15. ,15. ,15. ,15. ,15. ,18.5,17.2,15.9,15. ,16.4,16.5,15.5,15. ,15. ,15. ,15.6,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,17.8,17.9,17.8,17.1,16.5,15.6,15. ,15. ,15. ,15. ,15. ,15. ,15.4,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15.1,15. ,18. ,17.5,19.1,16.7,17.5,16.4,15.8,15. ,15. ,15. ,15. ,15.2,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15.1,15. ,15. ,15. ,15. ,15. ,15. ,15. ,17.9,17.8,18.2,17.3,16.7,15.7,15. ,15. ,15.3,15. ,15.4,15. ,15.7,15.1,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,18.2,17.5,16.4,15.9,17. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15.3,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15.2,15. ,15. ,15. ,17. ,16.1,16.2,16.8,16.3,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,17.5,17.4,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15.3,16.2,17.8,17. ,16. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,17. ,15.2,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15.7,16.3,16.7,16.6,15.3,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15.6,15. ,15. ,15. ,15. ,15.3,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15.6,16.2,15.9,16. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15.5,16. ,15.9,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. },{15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15.5,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15.5,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15.6,15.3,15. ,15. ,15.9,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15.4,15. ,15. ,15. ,16.4,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15.7,15.8,15. ,15. ,15. ,16.6,17.7,15.5,15. ,15. ,15. ,15.1,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,17.9,18.5,15.6,15.3,15.8,19. ,19.5,16. ,15. ,15.3,15.6,15.6,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,16.4,17.3,15.8,15.8,17.5,19.6,19. ,16.9,15.1,19. ,16.3,15.5,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,16.4,17.7,16.4,15. ,16.7,18.5,18.6,17. ,16.7,19.5,17.5,16.9,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15.7,16.7,15. ,15. ,15.7,18.2,18.6,15.5,18.1,16.6,17.9,18.3,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,18.8,18.4,16.5,17.7,15. ,17.3,17.2,15. ,15. ,15. ,16.8,18.3,15.8,16. ,17.7,19.3,19.8,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,19.3,21.6,18.2,17.3,16.2,16.7,15.8,15. ,15. ,15. ,15.9,18.1,15.8,16.2,18.2,17.5,17.2,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15.5,17.2,16.9,17.6,16.5,16.3,15. ,15. ,15. ,15. ,15. ,15.6,15.9,17.2,17.6,16.8,16.5,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15.9,18.2,15.4,15.8,17.2,16.9,16. ,15. ,15. ,15. ,15. ,15. ,15. ,15.8,18.2,17.3,16.7,16.5,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15.8,16.4,15. ,15. ,15.3,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15.1,15.8,17.7,16.8,16.2,16. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15.1,16.8,18.1,17.9,16.4,17.3,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15.1,15.2,16.3,17.8,18.5,17.3,16.5,15.7,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15.9,15. ,15.7,16.6,16. ,17.1,16.8,17.3,16.7,16.5,15.9,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15.4,15.4,15.4,16.4,16.3,17.5,16.6,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15.4,16. ,15.9,17.1,17.8,18. ,17.4,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15.4,16.7,18.1,18.1,17.9,17.5,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15.8,15.3,16.4,17.1,17.2,17.6,17.2,16.2,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,17. ,16.8,16.5,16.2,16.4,16.9,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15.1,15.8,16.2,15.5,16.7,16.4,16.6,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15.6,16.5,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,15. ,16.9}
};
