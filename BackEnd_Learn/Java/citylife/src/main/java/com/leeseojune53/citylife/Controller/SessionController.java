package com.leeseojune53.citylife.Controller;

import com.leeseojune53.citylife.Entity.User;
import com.leeseojune53.citylife.Payload.Request.LoginRequest;
import com.leeseojune53.citylife.Payload.Response.TokenResponse;
import com.leeseojune53.citylife.Security.JwtTokenProvider;
import com.leeseojune53.citylife.Service.Session.SessionService;
import lombok.RequiredArgsConstructor;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
@RequiredArgsConstructor
public class SessionController {
    private final SessionService sessionService;


    @GetMapping("/login")
    public TokenResponse login(
            @RequestBody  LoginRequest loginRequest
            ){
        String token = sessionService.CreateToken(loginRequest);
        JwtTokenProvider jwtTokenProvider = new JwtTokenProvider();
        System.out.println(jwtTokenProvider.getuserId(token));
        return new TokenResponse("성공", token, token);
    }

    @GetMapping("/test")
    public String test(){
        String asdf = "Bearer eyJhbGciOiJIUzI1NiIXVCJ9";
        String token;
        if(asdf.startsWith("")){
            token = asdf.substring(7);
        }
        else return null;
        return token;
    }

    @GetMapping("/ranking/Top3")
    public List<User> ranking(){
        return sessionService.rank();
    }

}
