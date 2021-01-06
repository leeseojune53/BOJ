package com.dsm.daily_book.service.diary;

import com.dsm.daily_book.dto.request.DiaryDTO;
import com.dsm.daily_book.entity.diary.Diary;
import com.dsm.daily_book.entity.diary.DiaryRepository;
import com.dsm.daily_book.entity.diary.Mood;
import com.dsm.daily_book.entity.user.User;
import com.dsm.daily_book.entity.user.UserRepository;
import com.dsm.daily_book.exception.user.UserNotFoundException;
import com.dsm.daily_book.security.jwt.AuthenticationFacade;
import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Service;

import java.util.Date;

@Service
@RequiredArgsConstructor
public class DiaryServiceImpl implements DiaryService{
    private final DiaryRepository diaryRepository;
    private final UserRepository userRepository;
    private final AuthenticationFacade authenticationFacade;

    @Override
    public void write(DiaryDTO.write request) {
        String email = authenticationFacade.getUser().getEmail();
        System.out.println(request.getSubject());
        try{
            userRepository.findByEmail(email)
                    .map(user ->
                        diaryRepository.save(
                                Diary.builder()
                                        .subject(request.getSubject())
                                        .content(request.getContent())
                                        .mood(Mood.value(request.getMood()))
                                        .writer(user)
                                        .build()
                        )
                    ).orElseThrow(UserNotFoundException::new);
        }catch (Exception e){
            throw new UserNotFoundException();
        }

    }
}