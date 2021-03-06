package com.leeseojune53.citylife.Service.Signup;

import com.leeseojune53.citylife.Entity.User;
import com.leeseojune53.citylife.Exceptions.UserAlreadySignupExceptions;
import com.leeseojune53.citylife.Payload.Request.SignRequest;
import com.leeseojune53.citylife.Repository.UserRepository;
import lombok.RequiredArgsConstructor;
import org.springframework.security.crypto.password.PasswordEncoder;
import org.springframework.stereotype.Service;

import java.util.Optional;

@Service
@RequiredArgsConstructor
public class SignupServiceImpl implements SignupService {
    private final UserRepository userRepository;
    private final PasswordEncoder passwordEncoder;

    @Override
    public boolean userSignupService(SignRequest request) {
        try{
            userRepository.save(
                    User.builder()
                        .userId(request.getUserId())
                        .userPw(passwordEncoder.encode(request.getUserPw()))
                        .build()
            );
            return true;
        }catch (Exception e){
            throw new UserAlreadySignupExceptions();
        }
    }

    @Override
    public boolean isAlreadySignupService(String userId) {
        Optional<User> user = userRepository.findByUserId(userId);
        return user.isEmpty();
    }
}
