Search :

			pMarkInstance->SetPosition(pTextTail->x - iWidth/2 - iImageHalfSize, pTextTail->y - c_fyMarkPosition);
			pGuildNameInstance->SetPosition(pTextTail->x + iImageHalfSize, pTextTail->y - c_fyGuildNamePosition, pTextTail->z);
			pGuildNameInstance->Update();

Replace with :

#ifdef ALIGN_ABOVE
			pMarkInstance->SetPosition(pTextTail->x - iWidth / 2 - iImageHalfSize, pTextTail->y - c_fyMarkPosition - 15);
			pGuildNameInstance->SetPosition(pTextTail->x + iImageHalfSize, pTextTail->y - c_fyGuildNamePosition - 15, pTextTail->z);
			pGuildNameInstance->Update();
#else
			pMarkInstance->SetPosition(pTextTail->x - iWidth/2 - iImageHalfSize, pTextTail->y - c_fyMarkPosition);
			pGuildNameInstance->SetPosition(pTextTail->x + iImageHalfSize, pTextTail->y - c_fyGuildNamePosition, pTextTail->z);
			pGuildNameInstance->Update();			
#endif	

Search :

		int iNameWidth, iNameHeight;

Replace with : 

		int iNameWidth, iNameHeight, iImageHalfSize;

Search :

			if (LocaleService_IsEUROPE())
			{
				if( GetDefaultCodePage() == CP_ARABIC )
				{
					pTitle->SetPosition(pTextTail->x - (iNameWidth / 2) - iTitleWidth - 4.0f, pTextTail->y, pTextTail->z);
				}
				else
				{
					pTitle->SetPosition(pTextTail->x - (iNameWidth / 2), pTextTail->y, pTextTail->z);
				}
			}
			else
			{
				pTitle->SetPosition(pTextTail->x - (iNameWidth / 2) - fxAdd, pTextTail->y, pTextTail->z);
			}			
			pTitle->Update();

Replace with :

			if (LocaleService_IsEUROPE())
			{
				if( GetDefaultCodePage() == CP_ARABIC )
				{
#ifdef ALIGN_ABOVE
					pTitle->SetPosition(pTextTail->x + iImageHalfSize, pTextTail->y - c_fyGuildNamePosition, pTextTail->z);
#else
					pTitle->SetPosition(pTextTail->x - (iNameWidth / 2) - iTitleWidth - 4.0f, pTextTail->y, pTextTail->z);
#endif
				}
				else
				{
#ifdef ALIGN_ABOVE
					pTitle->SetPosition(pTextTail->x + iImageHalfSize, pTextTail->y - c_fyGuildNamePosition, pTextTail->z);
#else
					pTitle->SetPosition(pTextTail->x - (iNameWidth / 2), pTextTail->y, pTextTail->z);
#endif
				}
			}
			else
			{
#ifdef ALIGN_ABOVE
				pTitle->SetPosition(pTextTail->x + iImageHalfSize, pTextTail->y - c_fyGuildNamePosition, pTextTail->z);
#else
				pTitle->SetPosition(pTextTail->x - (iNameWidth / 2) - fxAdd, pTextTail->y, pTextTail->z);
#endif
			}			
			pTitle->Update();
			

Search :

						pLevel->SetPosition(pTextTail->x - (iNameWidth / 2) - iTitleWidth, pTextTail->y, pTextTail->z);

Replace with :

#ifdef ALIGN_ABOVE
						pLevel->SetPosition(pTextTail->x - (iNameWidth / 2) + 4.0f, pTextTail->y, pTextTail->z);
#else
						pLevel->SetPosition(pTextTail->x - (iNameWidth / 2) - iTitleWidth, pTextTail->y, pTextTail->z);
#endif
